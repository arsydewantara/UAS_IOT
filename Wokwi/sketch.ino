// This example uses an ESP32 Development Board
// to connect to shiftr.io.
//
// You can check on your device after a successful
// connection here: https://www.shiftr.io/try.
//
// by Joël Gähwiler
// https://github.com/256dpi/arduino-mqtt

#include <WiFi.h>
#include <MQTT.h>
#include "DHT.h"

#define DHTPIN 2
#define LEDPIN 19
#define LEDPIN2 21
#define LEDPIN3 18
#define LEDPIN4 5
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);

const char ssid[] = "Wokwi-GUEST";
const char pass[] = "";

WiFiClient net;
MQTTClient client;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];

unsigned long lastMillis = 0;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("bedroom","kelompokfajri","0Fi7O0DO7wVVP1HX")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");
  client.subscribe("iot/bedroom/led");
  client.subscribe("iot/livingroom/led");
  client.subscribe("iot/bathroom/led");
  client.subscribe("iot/kitchen/led");


  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  if(payload[0] == '1' && topic == "iot/bedroom/led"){
    digitalWrite(LEDPIN, HIGH);
  }else{
    digitalWrite(LEDPIN, LOW);
  }
  if(payload[0] == '1' && topic == "iot/bathroom/led"){
    digitalWrite(LEDPIN2, HIGH);
  }else{
    digitalWrite(LEDPIN2, LOW);
  }
  if(payload[0] == '1' && topic == "iot/livingroom/led"){
    digitalWrite(LEDPIN3, HIGH);
  }else{
    digitalWrite(LEDPIN3, LOW);
  }
  if(payload[0] == '1' && topic == "iot/kitchen/led"){
    digitalWrite(LEDPIN4, HIGH);
  }else{
    digitalWrite(LEDPIN4, LOW);
  }

  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`.
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  pinMode(LEDPIN, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
  pinMode(LEDPIN3, OUTPUT);
  pinMode(LEDPIN4, OUTPUT);
  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported
  // by Arduino. You need to set the IP address directly.
  client.begin("kelompokfajri.cloud.shiftr.io", net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  //suhu bedroom
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (temp,msg,10));
  client.publish("iot/bedroom/suhu",msg);
  //kelembaban bedroom
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (hum,msg,10));
  client.publish("iot/bedroom/kelembaban",msg);

  //suhu livingroom
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (temp+5,msg,10));
  client.publish("iot/livingroom/suhu",msg);
  //kelembaban living room
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (hum+5,msg,10));
  client.publish("iot/livingroom/kelembaban",msg);

  //suhu bathroom
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (temp-2,msg,10));
  client.publish("iot/bathroom/suhu",msg);
  //kelembaban bathroom
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (hum-2,msg,10));
  client.publish("iot/bathroom/kelembaban",msg);

  //suhu kitchen
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (temp+2,msg,10));
  client.publish("iot/kitchen/suhu",msg);
  //kelembaban kitchen
  snprintf(msg, MSG_BUFFER_SIZE, "%s",itoa (hum+2,msg,10));
  client.publish("iot/kitchen/kelembaban",msg);

  delay(2000);
}