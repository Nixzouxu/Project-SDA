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
	-Menambahkan nasabah ke dalam antrian dengan memilih jenis layanan (Setor Tunai, Tarik Tunai, atau Pembukaan Rekening).
	-Memproses nasabah yang berada di depan antrian dan menyimpan riwayat transaksi.
	-Menampilkan antrian nasabah yang sedang menunggu.
	-Menampilkan riwayat transaksi yang telah diproses.
	-Membatalkan transaksi terakhir (undo) dan mengembalikan nasabah ke antrian.
	-Keluar dari program dengan membersihkan semua memori yang dialokasikan.
Program ini menggunakan dua struktur data utama yaitu :
	-Queue (Antrian): Untuk mengelola nasabah yang sedang menunggu.
	-Stack (Tumpukan): Untuk menyimpan riwayat transaksi yang telah diproses.

INTRUKSI KOMPILASI dan CARA MENJALANKAN PROGRAM
Cara Kompilasi :
1) Sebelum Kompilasi, di terminal gunakan command " [Console]::OutputEncoding = [System.Text.UTF8Encoding]::new() " agar Emoji yang ada di kode program dapat muncul di terminal
2) Compile dengan command " gcc -o sistem_antrian_bank sistem_antrian_bank.c" lalu tekan ENTER
3) lalu masukkan command " ./sistem_antrian_bank " dan tekan ENTER
dan Program akan berjalan



