
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false; // Flag untuk mendeteksi adanya pertukaran elemen

        for (int j = 0; j < n-i-1; j++) {
            // Bandingkan elemen saat ini dengan elemen berikutnya
            if (arr[j] > arr[j+1]) {
                // Jika elemen saat ini lebih besar, tukar posisi dengan elemen berikutnya
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true; // Set flag menjadi true karena ada pertukaran
            }
        }

        // Jika tidak ada elemen yang ditukar, array sudah terurut
        if (!swapped)
            break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array sebelum diurutkan: " << endl;
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Array setelah diurutkan: " << endl;;
    printArray(arr, n);
    return 0;
}
