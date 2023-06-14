<?php
$servername = "localhost";
$username = "id20906941_fajriiotdatabase";
$password = "2009106033Arsy#";
$dbname = "id20906941_database";


$con = mysqli_connect($servername,$username,$password,$dbname);

if(!$con){
    die("Koneksi Gagal".mysqli_connect_error());
}

$webhs = json_decode(file_get_contents('php://input'),true);
$topic = @$webhs['topic'];
$payload = @$webhs['payload'];

$sql = "INSERT INTO dataiot (topic,payload) VALUES ('$topic','$payload')";


mysqli_query($con,$sql);

?>