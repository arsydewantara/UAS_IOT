# UAS_IOT

* Anggota Kelompok
* Deskripsi Projek
* Broker Yang Digunakan
* Topik Yang Digunakan
* Alur Projek
* Tampilan Platform

# Anggota Kelompok
* Muhammad Gusti Keyandi - 2009106003
* Hadi Bayu Saputra - 2009106006
* Muhammad Arsy Dewantara - 2009106033
* Muhammad Fajriannur - 2009106040
* Muhammad Amri Rasyid Ramadhan - 2009106047

# Deskripsi Projek
Projek ini merupakan aplikasi smarthome yang berbasis internet of things dengan menggunakan platform shiftr.io sebagai metode mqtt dan platform iot yang digunakan adalah kodular. aplikasi ini dapat menampilkan kelembaban, suhu, dan menongontrol mati nyala lampu LED yang terdiri dari 4 ruangan yaitu kitchen, bathroom, bedroom, dan living room.

# Broker Yang Digunakan
* https://kelompokfajri.cloud.shiftr.io/

![image](https://github.com/arsydewantara/UAS_IOT/assets/74332636/2d1bee47-9852-461c-9e7e-394109eb702b)

# Topik Yang Digunakan
### Wokwi
* iot/bedroom/led
* iot/livingroom/led
* iot/bathroom/led
* iot/kitchen/led
* iot/bedroom/suhu
* iot/bedroom/kelembaban
* iot/livingroom/suhu
* iot/livingroom/kelembaban
* iot/bathroom/suhu
* iot/bathroom/kelembaban
* iot/kitchen/suhu
* iot/kitchen/kelembaban

# Alur Projek
Sensor DHT akan mempublish suhu dan kelembaban ke setiap ruangan broker yang sudah ditetapkan. Kodular, database, dan website akan menerima data yang di publish oleh DHT. Kontroling LED akan mengambil data yang dipublish kodular dikirimkan ke broker lalu LED pada wokwi akan menyala dan mati. data yang ditampilkan di website dan kodular adalah data terakhir yang dikirimkan oleh broker. 

# Tampilan Platform
* Halaman Utama
![image](https://github.com/arsydewantara/UAS_IOT/assets/74332636/0f6dac5f-c98e-442b-8c56-9a6c0bab4d7f)
* Halaman Bathroom
![image](https://github.com/arsydewantara/UAS_IOT/assets/74332636/b06f1ebe-b7b0-4d36-af4f-a6e7c11fc7cc)
* Halaman Living Room
![image](https://github.com/arsydewantara/UAS_IOT/assets/74332636/8516688e-55d3-415d-95f3-6983a0e13a62)
* Halaman Kitchen
![image](https://github.com/arsydewantara/UAS_IOT/assets/74332636/3d5735c9-d380-4c78-bafe-9219a8ee297f)
* Halaman Bedroom
![image](https://github.com/arsydewantara/UAS_IOT/assets/74332636/6db1ac40-79bd-4cdc-9ad4-1ef42f3ee1fb)

* Kodular
![WhatsApp Image 2023-06-14 at 13 48 24](https://github.com/arsydewantara/UAS_IOT/assets/74332636/1032e42e-04da-4765-a10f-d7b9490ed625)

