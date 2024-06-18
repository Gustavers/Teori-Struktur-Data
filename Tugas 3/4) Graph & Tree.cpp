#include <stdio.h>
#include <time.h>

// Struktur Untuk Representasi Graph
typedef struct {
    char nama[20];
    int jarak[10];
} Kota;

int main() {
    int n;
    printf("Masukkan Jumlah Simpul : ");
    scanf("%d", &n);
    
    Kota kota[n];
    for (int i = 0; i < n; i++) {
        printf("Masukkan Nama Simpul Ke-%d : ", i + 1);
        scanf("%s", kota[i].nama);
    }
    
    printf("Masukkan Bobot Antar Simpul\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%s--->%s = ", kota[i].nama, kota[j].nama);
            scanf("%d", &kota[i].jarak[j]);
        }
    }
    
    printf("\n");

    // Header Kolom
    printf("%-8s", "");
    for (int i = 0; i < n; i++) {
        printf("%-8s", kota[i].nama);
    }
    printf("\n");

    // Matriks Bobot
    for (int i = 0; i < n; i++) {
        printf("%-8s", kota[i].nama);
        for (int j = 0; j < n; j++) {
            printf("%-8d", kota[i].jarak[j]);
        }
        printf("\n");
    }
    
    printf("\nProcess Returned 0 (0x0)   Execution Time : ");
    
    // Menghitung Waktu Eksekusi
    clock_t start = clock();
    // Simulasi Proses Yang Memakan Waktu
    for (int i = 0; i < 100000000; i++);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.3f s\n", time_spent);
    printf("Press Any Key To Continue.\n");

    return 0;
}