#include "nasabah.h"
#include "ui_menu.h"

// Fungsi untuk membuat Queue baru
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Fungsi untuk membuat Stack baru
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
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

// Fungsi untuk memproses nasabah di dalam antrian (Dequeue)
void dequeue(Queue* queue, Stack* stack){
    if(queue->front == NULL){
        printf("Antrian Kosong, tidak ada nasabah yang diproses. \n");
        return;
    }
    Nasabah* temp = queue->front;
    queue->front = queue->front->next;

    if(queue->front == NULL){ // jika antrian kosong setelah dequeue
        queue->rear = NULL;
    }

    // Simpan Nasabah yang diproses ke stack riwayat transaksi
    temp->next = stack->top;
    stack->top = temp;

    printf("⚙️ Nasabah %s dengan layanan %s telah diproses. ✅\n", temp->nama, temp->layanan);
}

// Fungsi untuk menampilkan antrian saat ini
void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }

    Nasabah* current = q->front;
    printf("\n+------+----------------+------------------+\n");
    printf("| No.  | Nama Nasabah   | Layanan          |\n");
    printf("+------+----------------+------------------+\n");

    int count = 1;
    while (current != NULL) {
        printf("| %-4d | %-14s | %-16s |\n", count, current->nama, current->layanan);
        current = current->next;
        count++;
    }
    printf("+------+----------------+------------------+\n");
    printf("Total nasabah dalam antrian: %d\n", count - 1);
}
