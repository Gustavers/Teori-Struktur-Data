# <h1 align="center">Eveluasi CPMK Semester Genap</h1>
<p align="center">Ahmad Fariz Gustav </p>
<p align="center">2311110012</p>
<p align="center">S1SD-04-A</p>

## Soal Penugasan
### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! (35 Poin)

### Jawaban :
Berikut adalah penjelasan mengenai alur dan runtime dari algoritma Bubble Sort, Selection Sort, dan Merge Sort:

### Bubble Sort

#### Alur :
1. **Iterasi Pertama**:
   - Mulai dari elemen pertama, bandingkan elemen saat ini dengan elemen berikutnya.
   - Jika elemen saat ini lebih besar dari elemen berikutnya, tukar posisi keduanya.
   - Lanjutkan perbandingan hingga akhir array, elemen terbesar akan "bubble up" ke posisi terakhir.
2. **Iterasi Berikutnya**:
    - Ulangi proses yang sama untuk elemen-elemen yang tersisa, mengabaikan elemen terakhir yang sudah terurut.
   - Proses ini diulang hingga seluruh array terurut.

#### Runtime :
- **Best Case**: O(n) - terjadi ketika array sudah terurut. Algoritma dapat mendeteksi bahwa tidak ada pertukaran yang perlu dilakukan setelah satu iterasi.
- **Worst Case**: O(n²) - terjadi ketika array terurut secara terbalik. Setiap elemen perlu dibandingkan dan ditukar pada setiap iterasi.

### Selection Sort

#### Alur :
1. **Iterasi Pertama**:
   - Cari elemen terkecil di array dan tukar dengan elemen pertama.
2. **Iterasi Berikutnya**:
   - Cari elemen terkecil di subarray yang tersisa (mengabaikan elemen yang sudah terurut) dan tukar dengan elemen di posisi berikutnya.
   - Ulangi proses ini hingga seluruh array terurut.

#### Runtime :
- **Best Case**: O(n²) - Algoritma selalu melakukan jumlah perbandingan yang sama, tidak peduli bagaimana data diurutkan.
- **Worst Case**: O(n²) - Sama seperti best case, jumlah perbandingan tetap konstan karena sifat dari algoritma ini.

### Merge Sort

#### Alur :
1. **Divide**:
   - Bagilah array menjadi dua bagian yang sama besar secara rekursif hingga tiap bagian hanya terdiri dari satu elemen.
2. **Conquer**:
   - Gabungkan dua bagian kecil menjadi satu bagian yang terurut.
   - Ulangi proses penggabungan ini hingga seluruh array terurut.

#### Runtime :
- **Best Case**: O(n log n) - Karena proses pembagian dan penggabungan dilakukan secara konsisten terlepas dari bagaimana data diurutkan.
- **Worst Case**: O(n log n) - Sama seperti best case, waktu yang dibutuhkan untuk membagi dan menggabungkan selalu sama.

### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut (35 poin)
 
```c++
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
    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Array setelah diurutkan: ";
    printArray(arr, n);
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/14a49c3a-faa2-4d77-b77f-6e4271f3d32c)

#### Penjelasan :

Fungsi `bubbleSort(int arr[], int n)`:

1. Iterasi Luar (i):
    - Melakukan perulangan sebanyak `n-1` kali, di mana `n` adalah jumlah elemen dalam array.
    - Variabel `i` melacak indeks elemen yang sedang dibandingkan.
    - Pada setiap iterasi, diasumsikan bahwa elemen pada indeks `i` dan seterusnya sudah terurut.

2. Flag `swapped`:
    - Diinisialisasi sebagai `false`. Digunakan untuk mendeteksi apakah ada pertukaran elemen pada iterasi saat ini.

3. Iterasi Dalam (j):
    - Melakukan perulangan sebanyak `n-i-1` kali.
    - Variabel `j` melacak indeks elemen yang dibandingkan dengan elemen berikutnya.

4. Perbandingan Elemen:
    - Membandingkan elemen pada indeks `j` dengan elemen pada indeks `j+1`.
    - Jika elemen pada indeks `j` lebih besar daripada elemen pada indeks `j+1`, lakukan pertukaran.

5. Pertukaran Elemen:
    - Jika terjadi pertukaran elemen:
        - Gunakan variabel temporer `temp` untuk menyimpan nilai elemen pada indeks `j`.
        - Pindahkan nilai elemen pada indeks `j+1` ke indeks `j`.
        - Pindahkan nilai yang disimpan di `temp` ke indeks `j+1`.
        - Set flag `swapped` menjadi `true` untuk menunjukkan bahwa terjadi pertukaran.

6. Pemeriksaan Pertukaran:
    - Setelah iterasi dalam selesai, periksa nilai `swapped`.
    - Jika `swapped` tetap `false`, artinya tidak ada pertukaran elemen pada iterasi saat ini.
    - Jika tidak ada pertukaran, array sudah terurut dan loop `i` dapat dihentikan dengan menggunakan `break`.

Fungsi `printArray(int arr[], int size)`:

1. Iterasi Cetak:
    - Melakukan perulangan sebanyak `size` kali.
    - Pada setiap iterasi, mencetak nilai elemen pada indeks `i` ke konsol.

Fungsi `main()`:

1. Deklarasi Array:
    - Men deklarasikan array `arr` berisi beberapa nilai integer.
    - Menentukan variabel `n` untuk menyimpan jumlah elemen dalam array.

2. Cetak Array Awal:
    - Memanggil fungsi `printArray` untuk mencetak array `arr` sebelum diurutkan.

3. Pemanggilan Bubble Sort:
    - Memanggil fungsi `bubbleSort` untuk mengurutkan array `arr`.

4. Cetak Array Terurut:
    - Memanggil fungsi `printArray` untuk mencetak array `arr` setelah diurutkan.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/594ce6a2-538d-459c-afc6-5265558ec29a)

### 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” (30 poin)
contoh
Input string1 = “bahu” string2 = “buah”
Output: “anagram”
Input string1 = “makan” string2 = “minum”
Output: “tidak anagram”

#### Kode Program :
```c++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isAnagram(string str1, string str2) {
    // Mengkonversi String Ke Lowercase Dan Hapus Spasi
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
    str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());

    // Sort Kedua String
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Membandingkan String Yang Telah Disort
    if (str1 == str2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string str1, str2;
  
    // Input String 1 Dan String 2
    cout << "Masukkan String 1 : ";
    getline(cin, str1);
    cout << "Masukkan String 2 : ";
    getline(cin, str2);

    // Memanggil Fungsi IsAnagram
    bool isAnagramResult = isAnagram(str1, str2);

    // Menampilkan Hasil
    if (isAnagramResult) {
        cout << str1 << " Dan " << str2 << " Adalah Anagram" << endl;
    } else {
        cout << str1 << " Dan " << str2 << " Bukan Anagram" << endl;
  }

  return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/70fa1773-9a37-4c26-931b-e575ca49f4c1)

Program ini memeriksa kata tersebut apakah sebuah anagram, dua kata atau frasa yang mengandung huruf-huruf yang sama dengan jumlah yang sama tetapi dalam urutan yang berbeda. Program ini menggunakan header `<iostream>` untuk input dan output, `<algorithm>` untuk fungsi-fungsi algoritma standar seperti `transform`, `sort`, dan `remove`, serta `<string>` untuk mendukung tipe data string. Setelah menerima dua string dari pengguna, program ini mengubah semua huruf dalam string tersebut menjadi huruf kecil dan menghapus semua spasi. Kemudian, kedua string diurutkan dan dibandingkan. Jika string yang sudah diurutkan tersebut sama, maka kedua string adalah anagram dan program akan menampilkan pesan yang sesuai. Jika tidak, program akan menampilkan bahwa kedua string tersebut bukan anagram. Misalnya, jika pengguna memasukkan "listen" dan "silent", program akan menampilkan bahwa kedua string tersebut adalah anagram. Sebaliknya, jika pengguna memasukkan "hello" dan "world", program akan menampilkan bahwa kedua string tersebut bukan anagram. Program ini memperlakukan string dengan tidak sensitif terhadap huruf besar dan kecil serta mengabaikan spasi.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/2912988c-1392-40f5-bd98-d3c7f641222e)

### 4.	Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! (30 Poin)
#### Kode Program :
```c++
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
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/ee3eb156-3313-434e-9d39-faf50e0fd365)

Kode program diatas berfungsi untuk menggabungkan dua array yang sudah diurutkan, yaitu array `A` dan `B`, menjadi satu array `A`. Proses penggabungan dilakukan dengan cara membandingkan setiap elemen dari kedua array dan memasukkannya ke array `A` secara terurut. Setelah itu, array `A` yang telah digabungkan akan diurutkan kembali menggunakan fungsi `sort` dari library `<algorithm>`. Array `A` awalnya sudah memiliki ukuran 10 dan diisi dengan nilai 2, 3, 4, 5, dan 6. Sedangkan array `B` memiliki ukuran 5 dan diisi dengan nilai 20, 12, 78, 29, dan 34. Hasil penggabungan dan pengurutan kedua array tersebut kemudian dicetak ke layar. Dengan demikian, program ini memungkinkan untuk menggabungkan dan mengurutkan dua array yang sudah diurutkan sebelumnya menjadi satu array yang terurut.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/2493fa63-a29c-4972-80c6-20fa8fec91d4)


