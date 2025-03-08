#include "nasabah.h"
#include "ui_menu.h"

// Fungsi untuk membuat Queue baru
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// fungsi untuk menambahkan nasabah ke dalam antrian (Enqueue)
void enqueue(Queue* queue, char nama[], char layanan[]){
    Nasabah* newNasabah = (Nasabah*)malloc(sizeof(Nasabah));
    strcpy(newNasabah->nama, nama);
    strcpy(newNasabah->layanan, layanan);
    newNasabah->next = NULL;

    if(queue->rear == NULL) { // jika antrian kosong
        queue->front = queue->rear = newNasabah;
    } else {
        queue->rear->next = newNasabah;
        queue->rear = newNasabah;
    }
  printf("✅ Nasabah %s berhasil ditambahkan ke antrian dengan layanan %s. \n", nama, layanan);
}
