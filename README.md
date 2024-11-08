Program ini adalah simulasi interaktif yang menggambarkan dunia Pet Cafe, dimana ada dua jenis karakter yaitu pegawai (manusia) dan pet (hewan). Pengguna dapat memberikan perintah untuk berinteraksi dengan karakter-karakter ini, interaksi tersebut akan mempengaruhi atribut mereka yaitu energy dan loves.
1. Karakter pada program ini:
-Pet: Karakter jenis hewan. Aktivitas yang dapat dilakukan oleh karakter jenis pet adalah PLAY (bermain).
-Pegawai: Karakter manusia yang bekerja di kafe. Aktivitas yang dapat dilakukan oleh karakter jenis pegawai adalah SERVE (menyajikan kopi).

2. Atribut Karakter:
Setiap karakter memiliki atribut-atribut berikut:
-name: Nama karakter (misalnya, Moka, Inul).
-energy: Energi karakter yang akan berkurang saat melakukan aktivitas.
-loves: Level afeksi atau rasa suka karakter terhadap interaksi yang dilakukan.

3. Fungsi Utama:
-createCharacter(): Fungsi ini digunakan untuk membuat karakter baru. Fungsi ini mengalokasikan memori untuk karakter, mengisi nama, tipe (pet atau pegawai), serta atribut energy dan loves.
-play(): Fungsi ini digunakan untuk memberi perintah bermain dengan hewan. Hanya karakter bertipe pet yang bisa melakukan aktivitas ini. Ketika karakter pet bermain, loves karakter tersebut bertambah dan energy berkurang.
-serveCoffee(): Fungsi ini digunakan untuk memberi perintah pegawai menyajikan kopi. Hanya karakter bertipe pegawai yang bisa melakukan aktivitas ini. Ketika pegawai menyajikan kopi, loves pegawai bertambah dan energy berkurang.
-showAttributes(): Fungsi ini digunakan untuk menampilkan atribut-atribut (energy dan loves) dari karakter yang dipilih.
-handleCommand(): Fungsi ini bertanggung jawab untuk memproses perintah yang diberikan oleh pengguna. Program menerima perintah dalam format tertentu seperti PLAY <NAMA>, SERVE <NAMA>, atau ATTR <NAMA>, dan melakukan aksi sesuai dengan perintah tersebut.

4. Proses dan Alur Program:
-Inisialisasi Karakter: Di dalam fungsi main(), beberapa karakter diciptakan menggunakan fungsi createCharacter().
-Input Pengguna: Program menunggu input dari pengguna yang berupa perintah untuk menginstruksikan karakter melakukan aktivitas tertentu. Format perintahnya adalah:
PLAY <NAMA>: Memerintahkan karakter pet untuk bermain.
SERVE <NAMA>: Memerintahkan pegawai untuk menyajikan kopi.
ATTR <NAMA>: Menampilkan atribut (energy dan loves) dari karakter.
exit: Untuk keluar dari simulasi.
-Proses Perintah:
Ketika perintah diterima, program mencari karakter yang sesuai berdasarkan nama yang diberikan.
Setelah karakter ditemukan, perintah dieksekusi sesuai dengan jenis karakter (pet atau pegawai).
Program akan memberikan output berupa perubahan atribut karakter setelah aktivitas dilakukan (misalnya, menambah loves dan mengurangi energy).
-Looping: Program akan terus berjalan hingga pengguna mengetikkan perintah exit, yang akan menghentikan simulasi.

5. Output:
Setiap kali perintah dirun, program akan memberikan feedback berupa status terkini dari karakter yang dipilih, seperti:
"Moka sedang bermain! Loves sekarang: 60, Energy sekarang: 95"
"Inul sedang menyajikan kopi! Loves sekarang: 75, Energy sekarang: 110"
"Atribut dari Moka (pet): Energy: 95, Loves: 60"
