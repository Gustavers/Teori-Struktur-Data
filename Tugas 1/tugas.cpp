// Nama: Ahmad Fariz Gustav
// NIM: 2311110012
// Kelas: S1SD-04A

// 1. Tugas membuat kode  program yang lebih efisien untuk mencari adanya duplikasi pada array
#include <iostream>
#include <algorithm>

int main() {
    int arrA[] = {2, 1, 3, 1};
    int panjangArrA = sizeof(arrA) / sizeof(arrA[0]);

    // Mengurutkan array menggunakan algoritma sort
    std::sort(arrA, arrA + panjangArrA);

    // Mengecek keberadaan duplikat menggunakan adjacent_find
    bool duplikat = std::adjacent_find(arrA, arrA + panjangArrA) != arrA + panjangArrA;

    // Menampilkan hasil (true jika ada duplikat, false jika tidak)
    std::cout << std::boolalpha << duplikat;

    return 0;
}

// kode ini lebih efisien karena memiliki kompleksitas waktu O(N log N)