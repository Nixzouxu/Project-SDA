#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

// ANSI Escape Codes untuk warna terminal (jika didukung)
#define RESET   "\033[0m"
#define CYAN    "\033[96m"
#define GREEN   "\033[92m"
#define YELLOW  "\033[93m"
#define RED     "\033[91m"
#define BLUE    "\033[94m"
#define BOLD    "\033[1m"
#define NEON    "\033[38;5;87m" 
#define BG_DARK    "\033[48;5;235m" 
#define BLINK    "\033[48;5m"  // Efek kedip


// Fungsi untuk membersihkan layar
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Untuk Windows
    #else
        system("clear"); // Untuk Linux/MacOS
    #endif
}

// Fungsi untuk efek loading
void futuristicLoading(){
    const char* animation[] = {"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"};
    int numFrames = sizeof(animation) / sizeof(animation[0]);

    printf(BOLD CYAN "\n ⏳ initializing System... ⏳\n" RESET);
    Sleep(500);

    for (int i = 0; i < 30; i++)
    {
        printf(BOLD GREEN "\r[ %s ] Loading...%d%%" RESET, animation[i % numFrames], (i + 1) * 3);
        fflush(stdout);
        Sleep(100);
    }
    printf(BOLD NEON "\r[ ✔ ] System Ready!          \n" RESET);
    
}

// Struct untuk data nasabah
typedef struct Nasabah {
    char nama[50];
    char layanan[50];
    struct Nasabah* next;
} Nasabah;

// Struct untuk Queue (Antrian)
typedef struct {
    Nasabah* front; // Elemen depan Antrian
    Nasabah* rear;  // Elemen belakang Antrian
} Queue;

// Struct Untuk Stack (Riwayat Transaksi)
typedef struct {
    Nasabah* top; // Elemen Teratas stack
} Stack;

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

// Fungsi untuk menambahkan nasabah ke antrian (Enqueue)
void enqueue(Queue* queue, char nama[], char layanan[]) {
    Nasabah* newNasabah = (Nasabah*)malloc(sizeof(Nasabah));
    strcpy(newNasabah->nama, nama);
    strcpy(newNasabah->layanan, layanan);
    newNasabah->next = NULL;

    if (queue->rear == NULL) { // Jika antrian kosong
        queue->front = queue->rear = newNasabah;
    } else {
        queue->rear->next = newNasabah;
        queue->rear = newNasabah;
    }
    printf("✅ %sNasabah %s berhasil ditambahkan ke antrian dengan layanan %s.%s\n", GREEN, nama, layanan, RESET);
}

// Fungsi untuk memproses nasabah dari antrian (Dequeue)
void dequeue(Queue* queue, Stack* stack) {
    if (queue->front == NULL) {
        printf("%s⚠️ Antrian kosong, tidak ada nasabah untuk diproses.%s\n", RED, RESET);
        return;
    }

    Nasabah* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) { // Jika antrian kosong setelah dequeue
        queue->rear = NULL;
    }

    // Simpan nasabah yang diproses ke stack riwayat transaksi
    temp->next = stack->top;
    stack->top = temp;

    printf("\n⚙️ Memproses transaksi %s%s%s untuk layanan %s%s%s...\n", CYAN, temp->nama, RESET, BLUE, temp->layanan, RESET);
    Sleep(1000);  // Delay 1 detik untuk simulasi proses
    printf("⚙️ %sNasabah %s dengan layanan %s telah diproses ✅.%s\n", GREEN, temp->nama, temp->layanan, RESET);
}

// Fungsi untuk membatalkan transaksi terakhir (Undo)
void undo(Queue* q, Stack* s) {
    if (s->top == NULL) {
        printf("Tidak ada transaksi untuk dibatalkan.\n");
        return;
    }

    Nasabah* temp = s->top;
    s->top = s->top->next;

    // Kembalikan nasabah ke antrian
    temp->next = NULL;
    if (q->rear == NULL) { // Jika antrian kosong
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }

    printf("✓ Transaksi %s dengan layanan %s telah dibatalkan dan dikembalikan ke antrian.\n", temp->nama, temp->layanan);
}

//fungsi untuk menampilkan antrian pada saat ini
void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("%s⚠️ Antrian kosong.%s\n", RED, RESET);
        return;
    }

    Nasabah* current = q->front;
    printf("\n");
    printf(BOLD BLUE "+---------------------------------------+\n" RESET);
    printf(BOLD BLUE "|          ANTRIAN NASABAH            |\n" RESET);
    printf(BOLD BLUE "+------+----------------+------------------+\n" RESET);
    printf("| No.  | Nama Nasabah   | Layanan          |\n");
    printf(BOLD BLUE "+------+----------------+------------------+\n" RESET);

    int count = 1;
    while (current != NULL) {
        printf("| %-4d | %-14s | %-16s |\n", count, current->nama, current->layanan);
        current = current->next;
        count++;
    }
    printf(BOLD BLUE "+------+----------------+------------------+\n" RESET);
    printf("Total nasabah dalam antrian: %d\n", count - 1);
}

// fungsi untuk menampilkan riwayat transaksi
void displayStack(Stack* s) {
    if (s->top == NULL) {
        printf("%sRiwayat transaksi kosong.%s\n", RED, RESET);
        return;
    }

    Nasabah* current = s->top;
    printf("\n");
    printf(BOLD BLUE "+---------------------------------------+\n" RESET);
    printf(BOLD BLUE "|       RIWAYAT TRANSAKSI NASABAH      |\n" RESET);
    printf(BOLD BLUE "+------+----------------+------------------+\n" RESET);
    printf("| No.  | Nama Nasabah   | Layanan          |\n");
    printf(BOLD BLUE "+------+----------------+------------------+\n" RESET);

    int count = 1;
    while (current != NULL) {
        printf("| %-4d | %-14s | %-16s |\n", count, current->nama, current->layanan);
        current = current->next;
        count++;
    }
    printf(BOLD BLUE "+------+----------------+------------------+\n" RESET);
    printf("Total transaksi dalam riwayat: %d\n", count - 1);
}

// Fungsi untuk membersihkan semua memory yang dialokasikan dalam Queue
void freeQueue(Queue* q) {
    Nasabah* current = q->front;
    Nasabah* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(q);
}

// Fungsi untuk membersihkan semua memory yang dialokasikan dalam Stack
void freeStack(Stack* s) {
    Nasabah* current = s->top;
    Nasabah* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(s);
}


