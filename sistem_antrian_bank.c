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

// Fungsi Untuk menampilkan Antrian 
void displayQueue(Queue* queue){
    if(queue->front == NULL){
        printf("\n");
        printf("╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮\n");
        printf("┃    📭  ANTRIAN KOSONG!    ┃\n");
        printf("┃  Tidak ada nasabah saat ini.┃\n");
        printf("╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯\n\n");
        return;
    }
    Nasabah* current = queue->front;
    printf("\n");
    
    printf("╔════════════════════════════════════════════╗\n");
    printf("║         🌟  DAFTAR ANTRIAN NASABAH  🌟      ║\n");
    printf("╠════╦════════════════╦══════════════════════╣\n");
    printf("║ 🔢 │     🏷 Nama     │       🏦 Layanan     ║\n");
    printf("╠════╬════════════════╬══════════════════════╣\n"); 

    int count = 1;
    while (current != NULL) {
        /*mencetak data antrian dalam format tabel yang rapi
            %-2d : menampilkan angka dengan lebar minimal 2 karakter dan rata kiri
            %-14s : menampilkan nama nasabah dengan lebar minimal 14 karakter dan rata kiri
            %-18s : menampilkan layanan dengan lebar minimal 18 karakter dan rata kiri*/
        printf("║ %-2d │ %-14s │ %-18s ║\n", count, current->nama, current->layanan);
        current = current->next;
        count++;
    }

    printf("╚════╩════════════════╩══════════════════════╝\n");
    printf("📢 Jumlah nasabah dalam antrian: %d\n", count - 1);
    printf("⌛ Mohon bersabar, layanan segera diproses... ✅\n\n");

}
