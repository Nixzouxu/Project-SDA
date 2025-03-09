#ifndef UI_MENU_H
#define UI_MENU_H

#include "nasabah.h"
#include <stdio.h>
#include <windows.h>// Untuk efek delay
#include <stdlib.h>

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


// clear screen (linux/macOs: "clear", Windows: "cls")
#define CLEAR_SCREEN() system("clear || cls")

// fungsi untuk menampilkan animasi loading
void loadingEffect();

// Fungsi untuk menampilkan menu utama
void displayMenu(Queue* queue, Stack* stack);

#endif
