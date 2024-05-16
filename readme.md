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

### 5. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 
struct (singkatan dari "structure") adalah tipe data bentukan dalam bahasa pemrograman C dan beberapa bahasa lain, seperti C++. struct memungkinkan kita untuk menggabungkan berbagai tipe data menjadi satu kesatuan. Dengan struct, kita bisa membuat tipe data baru yang lebih kompleks dan merepresentasikan objek dengan berbagai atribut. struct sangat berguna ketika kita ingin menyimpan informasi yang terdiri dari beberapa bagian yang terkait. Misalnya, kita bisa menggunakan struct untuk mendefinisikan sebuah buku yang memiliki judul, penulis, dan jumlah halaman.

#### Kode Program :
```c++
#include <iostream>
#include <cstring>

using namespace std;

// Definisi struct Buku
struct Buku {
    char judul[50];
    char penulis[50];
    int jumlahHalaman;
};

int main() {
    // Membuat instance dari struct Buku
    Buku buku1;

    // Mengisi data buku1
    strcpy(buku1.judul, "Pemrograman C++ untuk Pemula");
    strcpy(buku1.penulis, "Gustav");
    buku1.jumlahHalaman = 450;

    // Menampilkan informasi buku
    cout << "Judul Buku: " << buku1.judul << endl;
    cout << "Penulis: " << buku1.penulis << endl;
    cout << "Jumlah Halaman: " << buku1.jumlahHalaman << endl;

    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/9ba338b0-60cc-4574-803f-4a21e12e0514)
Kode di atas mendefinisikan sebuah struktur `Buku` yang digunakan untuk menyimpan informasi mengenai buku, seperti judul, penulis, dan jumlah halaman. Struktur ini memiliki tiga anggota: `judul`, `penulis`, dan `jumlahHalaman`, masing-masing dengan tipe data yang sesuai untuk menyimpan string dan integer. Di dalam fungsi `main`, sebuah instance dari struktur `Buku` bernama `buku1` dibuat. Kemudian, data untuk `buku1` diisi menggunakan fungsi `strcpy` untuk menyalin string ke anggota `judul` dan `penulis`, dan langsung menetapkan nilai untuk `jumlahHalaman`.
Setelah data dimasukkan, informasi buku ditampilkan ke layar menggunakan `cout`. Program ini menampilkan judul, penulis, dan jumlah halaman buku secara berurutan. Dengan mengisi dan menampilkan data dari instance `buku1`, program ini mendemonstrasikan penggunaan dasar dari `struct` dalam C++ untuk mengelola dan menampilkan data yang terorganisir. Pada akhir fungsi `main`, program mengembalikan nilai 0 yang menunjukkan bahwa program telah berjalan dan selesai dengan sukses.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/245ad82a-851a-49c6-b827-c3e2cdd2c895)

### 6. Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! (50 Poin)
#### Kode Program :
```c++
#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(string sentence) {
    // Menghapus spasi dan karakter non-alphanumeric dari kalimat
    string cleanSentence = "";
    for (char c : sentence) {
        if (isalnum(c)) {
            cleanSentence += tolower(c);
        }
    }
    
    // Membuat objek stack
    stack<char> charStack;
    
    // Menambahkan setiap karakter ke dalam stack
    for (char c : cleanSentence) {
        charStack.push(c);
    }
    
    // Membuat kalimat terbalik dengan menggunakan stack
    string reversedSentence = "";
    while (!charStack.empty()) {
        reversedSentence += charStack.top();
        charStack.pop();
    }
    
    // Memeriksa apakah kalimat asli sama dengan kalimat terbalik
    return cleanSentence == reversedSentence;
}

int main() {
    // Input kalimat dari pengguna
    string kalimat;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);
    
    // Memeriksa apakah kalimat adalah palindrom
    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }
    
    return 0;
}
```
#### Output :
![image](https://github.com/Gustavers/Teori-Struktur-Data/assets/162097300/87b5ddf3-4e79-4bc7-a93b-22dbbcc7d24d)

Kode di atas mendefinisikan fungsi `isPalindrome` yang memeriksa apakah sebuah kalimat adalah palindrom. Fungsi ini pertama-tama membersihkan kalimat dengan menghapus spasi dan karakter non-alfanumerik, serta mengonversi semua huruf menjadi huruf kecil menggunakan loop `for` dan fungsi `isalnum` serta `tolower`. Hasilnya disimpan dalam variabel `cleanSentence`. Kemudian, setiap karakter dari `cleanSentence` dimasukkan ke dalam stack `charStack`. Dengan menggunakan stack, urutan karakter dapat dibalik dengan mudah.

Setelah semua karakter dari `cleanSentence` dimasukkan ke dalam stack, sebuah string baru `reversedSentence` dibuat dengan mengambil karakter satu per satu dari stack sampai stack kosong. Ini menghasilkan versi terbalik dari `cleanSentence`. Fungsi `isPalindrome` kemudian membandingkan `cleanSentence` dengan `reversedSentence` untuk menentukan apakah kalimat tersebut adalah palindrom. Fungsi `main` meminta input kalimat dari pengguna dan menggunakan fungsi `isPalindrome` untuk memeriksa apakah kalimat tersebut adalah palindrom, lalu mencetak hasilnya ke layar. Dengan demikian, program ini memberikan cara sederhana untuk memeriksa apakah sebuah kalimat adalah palindrom, mengabaikan spasi dan tanda baca, serta tidak membedakan huruf besar dan kecil.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Teori-Struktur-Data/assets/162097300/8bc6f8bd-ee03-4af4-a3e8-c811a2d9107e)


### 7. Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! (60 Poin)
#### Kode Program :
```c++
#include <iostream>
using namespace std;

#define MAX 1000 // Mendefinisikan kapasitas maksimum stack

class Stack {
    int top;

public:
    int a[MAX]; // Array untuk menyimpan elemen stack

    Stack() { top = -1; } // Konstruktor untuk menginisialisasi top

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
};

// Fungsi untuk menambahkan elemen ke stack
bool Stack::push(int x) {
    if (isFull()) {
        cout << "Stack overflow" << endl;
        return false;
    } else {
        a[++top] = x;
        cout << x << " pushed into stack" << endl;
        return true;
    }
}

// Fungsi untuk menghapus elemen dari stack
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow" << endl;
        return -1;
    } else {
        int x = a[top--];
        return x;
    }
}

// Fungsi untuk mengembalikan elemen teratas dari stack tanpa menghapusnya
int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    } else {
        return a[top];
    }
}

// Fungsi untuk memeriksa apakah stack kosong
bool Stack::isEmpty() {
    return (top < 0);
}

// Fungsi untuk memeriksa apakah stack penuh
bool Stack::isFull() {
    return (top >= MAX - 1);
}

// Fungsi untuk mengembalikan ukuran stack
int Stack::size() {
    return (top + 1);
}

// Fungsi utama
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is " << stack.peek() << endl;
    cout << "Stack size is " << stack.size() << endl;

    cout << stack.pop() << " popped from stack" << endl;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;

    return 0;
}

```
#### Output :
![image](https://github.com/Gustavers/Teori-Struktur-Data/assets/162097300/73b96da3-d3f6-44c2-83ef-661ea39422d0)
Kode di atas merupakan implementasi dari struktur data stack dalam bahasa pemrograman C++. Stack digunakan untuk menyimpan data dalam urutan Last-In-First-Out (LIFO), di mana elemen yang terakhir dimasukkan adalah yang pertama dikeluarkan. Implementasi stack dalam kode tersebut menggunakan array untuk menyimpan elemen-elemennya.

Kelas `Stack` memiliki atribut `top` yang merupakan indeks dari elemen teratas dalam stack. Konstruktor kelas `Stack` digunakan untuk menginisialisasi nilai `top` menjadi -1, menandakan bahwa stack awalnya kosong. Kemudian, kelas `Stack` juga memiliki beberapa metode, antara lain:
- `push(int x)`: Menambahkan elemen baru `x` ke dalam stack. Fungsi ini memeriksa apakah stack penuh sebelum menambahkan elemen baru. Jika stack penuh, maka akan mencetak pesan "Stack overflow". Jika tidak, elemen baru tersebut akan ditambahkan ke dalam stack.
- `pop()`: Menghapus dan mengembalikan elemen teratas dari stack. Fungsi ini memeriksa apakah stack kosong sebelum menghapus elemen. Jika stack kosong, maka akan mencetak pesan "Stack underflow". Jika tidak, elemen teratas akan dihapus dan nilainya dikembalikan.
- `peek()`: Mengembalikan nilai dari elemen teratas stack tanpa menghapusnya. Fungsi ini memeriksa apakah stack kosong sebelum mengakses elemen teratas.
- `isEmpty()`: Memeriksa apakah stack kosong dengan cara mengecek apakah nilai `top` kurang dari 0.
- `isFull()`: Memeriksa apakah stack penuh dengan cara mengecek apakah nilai `top` sama dengan atau lebih besar dari `MAX - 1`.
- `size()`: Mengembalikan jumlah elemen dalam stack dengan cara mengembalikan nilai `top + 1`. 

Dalam fungsi `main`, sebuah objek dari kelas `Stack` dibuat. Kemudian, beberapa operasi dasar stack dilakukan, seperti menambahkan elemen baru, menghapus elemen teratas, dan memeriksa apakah stack kosong atau penuh. Hasil dari operasi-operasi tersebut kemudian ditampilkan ke layar sebagai output program.

#### Full Code Screenshot :
![image](https://github.com/Gustavers/Teori-Struktur-Data/assets/162097300/034dbdcd-c95b-4492-932b-844cd831ccd7)

