#include <iostream>
#include <algorithm>

using namespace std;

void mergeSortedArrays(int A[], int sizeA, int B[], int sizeB) {
int i = 0, j = 0, k = 0;

    // Menggabungkan Elemen Array B Ke Dalam Array A
    while (i < sizeA && j < sizeB) {
        if (A[i] <= B[j]) {
            A[k] = A[i];
            i++;
        } else {
            A[k] = B[j];
            j++;
        }
        k++;
    }

    // Menambahkan Elemen Yang Tersisa Dari Array A Atau Array B
    while (i < sizeA) {
        A[k] = A[i];
        k++;
        i++;
    }
    while (j < sizeB) {
        A[k] = B[j];
        k++;
        j++;
    }

    // Mengurutkan Array A Yang Telah Digabungkan
    sort(A, A + k);
}

int main() {
    int A[10];
    int sizeA = 5;
    int B[] = {20, 12, 78, 29, 34};
    int sizeB = 5;

    // Memasukkan Elemen Ke Array A
    for (int i = 0; i < sizeA; i++) {
        A[i] = i + 2;
    }

    // Menggabungkan Dan Mengurutkan Array A & B
    mergeSortedArrays(A, sizeA, B, sizeB);

    // Menampilkan Array A Yang Telah Digabungkan Dan Diurutkan
    cout << "Data Array A Yang Telah Digabungkan Dan Diurutkan : ";
    for (int i = 0; i < sizeA + sizeB; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}