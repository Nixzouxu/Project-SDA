#ifndef NASABAH_H
#define NASABAH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct untuk data nasabah
typedef struct Nasabah{
    char nama[50];
    char layanan[50];
    struct Nasabah* next;
} Nasabah;

// Struct untuk Queue (Antrian)
typedef struct{
    Nasabah* front; // Elemen depan Antrian
    Nasabah* rear;  // Elemen belakang Antrian
} Queue;

// Struct Untuk Stack (Riwayat Transaksi)
typedef struct{
    Nasabah* top; // Elemen Teratas stack
} Stack;

// Fungsi Untuk membuat Stack Baru
Stack* createStack();
// Fungsi untuk menambahkan nasabah ke antrian (Enqueue)
void enqueue(Queue* queue, char nama[], char layanan[]);
// Fungsi untuk memproses nasabah dari antrian (Dequeue)
void dequeue(Queue* queue, Stack* stack);

// Fungsi untuk menampilkan antrian saat ini
void displayQueue(Queue* queue);

// Fungsi untuk menampilkan riwayat transaksi 
void displayStack(Stack* stack);

// Fungsi untuk membatalkan transaksi terakhir (Undo)
void undo(Queue* queue, Stack* stack);

#endif