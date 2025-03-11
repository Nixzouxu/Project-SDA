# Project STRUKTUR DATA DAN ALGORITMA
Sistem Antrian Bank

NAMA dan NPM


Muhammad Hafidz (2408107010052)

Khairan Rafi (2408107010039)

Syakila Naira (2408107010034)  

Yogi Wanda Putra (2408107010056)

Muhammad Sulthan Shadiq (2408107010104) 


Deskripsi Singkat Program
Program ini adalah simulasi sistem antrian bank berbasis teks yang memungkinkan user untuk:
1) Menambahkan nasabah ke dalam antrian dengan memilih jenis layanan (Setor Tunai, Tarik Tunai, atau Pembukaan Rekening)
2) Memproses nasabah yang berada di depan antrian dan menyimpan riwayat transaksi
3) Menampilkan antrian nasabah yang sedang menunggu
4) Menampilkan riwayat transaksi yang telah diproses
5) Membatalkan transaksi terakhir (undo) dan mengembalikan nasabah ke antrian
6) Keluar dari program dengan membersihkan semua memori yang dialokasikan

Program ini menggunakan dua struktur data utama yaitu :
1) Queue (Antrian): Untuk mengelola nasabah yang sedang menunggu
2) Stack (Tumpukan): Untuk menyimpan riwayat transaksi yang telah diproses

INTRUKSI KOMPILASI dan CARA MENJALANKAN PROGRAM
Cara Kompilasi :
1) Sebelum Kompilasi, di terminal gunakan command " [Console]::OutputEncoding = [System.Text.UTF8Encoding]::new() " agar Emoji yang ada di kode program dapat muncul di terminal
2) Compile dengan command " gcc -o sistem_antrian_bank sistem_antrian_bank.c" lalu tekan ENTER
3) lalu masukkan command " ./sistem_antrian_bank " dan tekan ENTER
dan Program akan berjalan

Penjelasan Struktur Program dan Implementasi Struktur Data.

1) Fungsi clearScrean()
   
   	-fungsi ini digunakan untuk membersihkan layar terminal. Pada Windows, perintah cls digunakan, sedangkan pada Linux/MacOS, perintah clear digunakan.

2) Fungsi futuristicloading()

   	-Fungsi ini menampilkan animasi loading dengan efek visual yang menarik.
   
   	-Menggunakan array animation yang berisi karakter-karakter untuk animasi.
   
   	-Setiap iterasi menampilkan persentase loading yang meningkat.

4) Struct nasabah

   	-Struct ini merepresentasikan data nasabah.
   
   	-Menyimpan nama nasabah.
   
   	-Menyimpan jenis layanan yang dipilih nasabah.
   
   	-nextPointer ke nasabah berikutnya dalam antrian atau stack.

5) Struct Queue
  
  	 digunakan untuk menyimpan daftar nasabah yang sedang mengantri. Implementasi ini menggunakan linked list dengan pointer front (elemen pertama dalam antrian) dan rear (elemen terakhir dalam antrian).Struktur ini 	 mengimplementasikan antrian menggunakan linked list. Memiliki dua pointer:

   	- front: Menunjuk ke elemen depan antrian.
   
	- rear: Menunjuk ke elemen belakang antrian.

6) Struct Stack (Riwayat Transaksi)
   	Stack digunakan untuk menyimpan transaksi yang telah diproses. Struktur stack diimplementasikan dengan menggunakan linked list, di mana pointer top menunjuk ke elemen terakhir yang dimasukkan. 


   	-top menunjuk ke transaksi terakhir yang diproses.
   
   	-Push (Menambahkan data): Menambahkan transaksi baru ke dalam stack.
   
   	-Pop (Menghapus data): Menghapus transaksi terakhir dari stack.

   	-Undo: Mengembalikan transaksi terakhir dari stack ke dalam antrian.

   
7) Fungsi create queue()

   
	-Fungsi ini bertugas untuk membuat antrian baru. Caranya adalah dengan mengalokasikan memori yang diperlukan untuk antrian menggunakan malloc, kemudian menginisialisasi nilai front dan rear ke NULL karena antrian 	baru tersebut awalnya kosong dan belum memiliki elemen apa pun. Dengan demikian, antrian siap digunakan untuk menambahkan nasabah nantinya.

7.Fungsi createStack()


	-Fungsi ini berfungsi untuk membuat stack baru. Caranya adalah dengan mengalokasikan memori yang dibutuhkan untuk stack menggunakan `malloc`, kemudian menginisialisasi nilai `top` ke `NULL` karena stack baru 	tersebut awalnya kosong dan belum memiliki elemen apa pun. Dengan demikian, stack siap digunakan untuk menyimpan riwayat transaksi nantinya.

8.Fungsi enqueue()


	-Fungsi ini digunakan untuk menambahkan nasabah ke antrian. Membuat nasabah baru, mengisi data, dan menambahkannya ke belakang antrian

9.Fungsi dequeue()


	-Fungsi ini digunakan untuk memproses nasabah dari antrian.
 
	-Nasabah yang diproses dipindahkan dari antrian ke stack riwayat transaksi.

10.Fungsi undo()	


	-Fungsi ini digunakan untuk membatalkan transaksi terakhir.
 
	-Nasabah yang terakhir diproses dikembalikan ke antrian.

11.Fungsi displayQueue()


	-Fungsi ini digunakan untuk menampilkan antrian nasabah saat ini.Menampilkan daftar nasabah dalam antrian beserta layanan yang mereka pilih

12.Fungsi displayStack()


	-Fungsi ini digunakan untuk menampilkan riwayat transaksi.
 
	-Menampilkan daftar nasabah yang telah diproses beserta layanan yang mereka pilih.

13.Fungsi freeQueue()


	-Fungsi ini digunakan untuk membersihkan memori yang dialokasikan untuk antrian

14.Fungsi freeStack()


	-Fungsi ini digunakan untuk membersihkan memori yang dialokasikan untuk stack

15.Fungsi displayMenu()	


	-Fungsi ini menampilkan menu utama dan memproses pilihan pengguna.

	-Pengguna dapat memilih untuk menambah nasabah, memproses nasabah, menampilkan antrian, menampilkan riwayat transaksi, membatalkan transaksi terakhir, atau keluar 	 dari program.
16.Fungsi main 


	-Menginisialisasi antrian dan stack, menampilkan efek loading, dan memanggil fungsi displayMenu() untuk menampilkan menu utama

 
Hasil Eksekusi Program

menu utama

![alt text](https://github.com/Nixzouxu/Project-SDA/blob/main/hasil%20eksekusi/utama.jpg?raw=true)  


menambah nasabah

![alt text](https://github.com/Nixzouxu/Project-SDA/blob/main/hasil%20eksekusi/menambah%20nasabah.jpg?raw=true)


memproses nasabah

![alt text](https://github.com/Nixzouxu/Project-SDA/blob/main/hasil%20eksekusi/memperoses%20nasabah.jpg?raw=true)


menampilkan antrian

![alt text](https://github.com/Nixzouxu/Project-SDA/blob/main/hasil%20eksekusi/menampilkan%20antrian.jpg?raw=true)


menampilkan riwayat transaksi

![alt text](https://github.com/Nixzouxu/Project-SDA/blob/main/hasil%20eksekusi/menampilkan%20riwayat%20transaksi.jpg?raw=true)


membatalkan transaksi terakhir

![alt text](https://github.com/Nixzouxu/Project-SDA/blob/main/hasil%20eksekusi/membatalkan%20transaksi%20terakhir.jpg?raw=true)


Kendala dan Solusi Selama Pengembangan:


1) Mengalami kendala saat beberapa kali debugging tampilan antarmuka hingga harus mengganti-ganti tampilannya
2) Menghadapi kesulitan saat menginisialisasi stack dan queue dalam switch case di fungsi displayMenu.

   
Solusi

Kami hanya memperbaiki syntax nya lalu code pun berjalan dengan normal





