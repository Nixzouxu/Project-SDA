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


