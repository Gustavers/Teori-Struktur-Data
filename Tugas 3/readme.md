# <h1 align="center">Tugas 3 ALgoritma dan Struktur Data</h1>
<p align="center">Ahmad Fariz Gustav</p>
<p align="center">2311110012</p>
<p align="center">S1SD-04-A</p>

## 1. Priority Queue
Priority Queue adalah suatu bentuk struktur data yang berbasiskan struktur Queue pada umumnya. Pada priority Queue, terdapat salah satu bentuk implementasi yaitu implementasi menggunakan struktur data heaps. Dalam implementasi ini ada 3 pokok atribut yaitu heaps, comparator, dan last. Dengan menggunakan fasilitas heap ini kita bisa melakukan insert atau remove elemen dalam kompleksitas waktu logaritmik. Pada priority Queue ini, secara keseluruhan akan dibentuk sebuah pohon biner yang seimbang. Dalam pembuatan pohon biner ini diusahakan ketinggian yang terbentuk adalah minimum. Keminimuman tinggi pohon inilah yang menyebabkan kompleksitas waktu dalam memanipulasi daun menjadi fungsi logaritmik[1]. Priority Queue adalah struktur data abstrak yang memungkinkan penyimpanan dan pengambilan elemen berdasarkan prioritasnya. Elemen dengan prioritas tertinggi diakses dan dihapus terlebih dahulu. Heap (tumpukan) adalah salah satu implementasi populer dari antrian prioritas [2].

**Heap adalah struktur data pohon biner lengkap yang memenuhi dua properti:**

- Heap Max: Nilai pada setiap node tidak boleh lebih kecil dari nilai anak-anaknya.
- Heap Min: Nilai pada setiap node tidak boleh lebih besar dari nilai anak-anaknya. Dalam heap max, elemen dengan prioritas tertinggi terletak di root (puncak) pohon.
- Heap min, di sisi lain, memiliki elemen dengan prioritas terendah di root.

**Operasi Dasar pada Antrian Prioritas :**

- Insert(x): Memasukkan elemen baru x ke dalam antrian prioritas.
- ExtractMax(): Mengambil dan menghapus elemen dengan prioritas tertinggi dari antrian prioritas.
- DecreaseKey(i, newPriority): Menurunkan prioritas elemen pada indeks i ke nilai baru newPriority.
- IncreaseKey(i, newPriority): Menaikkan prioritas elemen pada indeks i ke nilai baru newPriority.
- PeekMax(): Mengembalikan elemen dengan prioritas tertinggi tanpa menghapusnya.

**Kelebihan Priority Queue :**

- Efisiensi : Priority queue memungkinkan akses dan penghapusan elemen dengan prioritas tertinggi dengan efisiensi waktu O(log n), di mana n adalah jumlah elemen dalam antrian.
- Fleksibilitas : Priority queue dapat digunakan untuk menyimpan elemen dengan berbagai jenis prioritas.
Kemudahan Penggunaan : Adanya kelas std::priority_queue yang mudah digunakan untuk mengimplementasikan priority queue.

**Kekurangan Priority Queue :**

- Kompleksitas : Implementasi priority queue lebih kompleks dibandingkan array dan list.
- Penggunaan Memori : Priority queue umumnya membutuhkan lebih banyak memori dibandingkan array dan list

### Kode Program :
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept> // Tambahkan Header Berikut Untuk std::runtime_error

class Heap {
private:
    std::vector<int> elements;
    int heapSize;

    int parent(int i) const {
        return (i - 1) / 2;
    }

    int leftChild(int i) const {
        return (2 * i) + 1;
    }

    int rightChild(int i) const {
        return (2 * i) + 2;
    }

    void shiftUp(int i) {
        while (i > 0 && elements[parent(i)] < elements[i]) {
            std::swap(elements[parent(i)], elements[i]);
            i = parent(i);
        }
    }

    void shiftDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        if (l < heapSize && elements[l] > elements[maxIndex]) {
            maxIndex = l;
        }
        int r = rightChild(i);
        if (r < heapSize && elements[r] > elements[maxIndex]) {
            maxIndex = r;
        }
        if (i != maxIndex) {
            std::swap(elements[i], elements[maxIndex]);
            shiftDown(maxIndex);
        }
    }

public:
    Heap() : heapSize(-1) {}

    void insert(int priority) {
        heapSize++;
        elements.push_back(priority);
        shiftUp(heapSize);
    }

    int ambilMaks() {
        if (heapSize < 0) {
            throw std::runtime_error("Heap Kosong");
        }
        int hasil = elements[0];
        elements[0] = elements[heapSize];
        heapSize--;
        shiftDown(0);
        return hasil;
    }

    void ubahPrioritas(int i, int prioritasBaru) {
        int prioritasLama = elements[i];
        elements[i] = prioritasBaru;
        if (prioritasBaru > prioritasLama) {
            shiftUp(i);
        } else {
            shiftDown(i);
        }
    }

    int dapatMaks() const {
        if (heapSize < 0) {
            throw std::runtime_error("Heap Kosong");
        }
        return elements[0];
    }

    void hapus(int i) {
        if (i < 0 || i > heapSize) {
            throw std::runtime_error("Indeks Tidak Valid");
        }
        elements[i] = dapatMaks() + 1;
        shiftUp(i);
        ambilMaks();
    }

    // Menambahkan Fungsi Untuk Mendapatkan Ukuran Heap
    int ukuran() const {
        return heapSize + 1;
    }

    // Menambahkan Fungsi Untuk Mendapatkan Elemen Heap
    const std::vector<int>& dapatElemen() const {
        return elements;
    }
};

int main() {
    Heap heap;
    heap.insert(67);
    heap.insert(26);
    heap.insert(54);
    heap.insert(38);
    heap.insert(19);
    heap.insert(27);
    heap.insert(35);
    heap.insert(41);
    heap.insert(17);
    heap.insert(32);

    std::cout << "Antrian Prioritas : ";
    for (int i = 0; i < heap.ukuran(); ++i) {
        std::cout << heap.dapatElemen()[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node Dengan Prioritas Tertinggi : " << heap.ambilMaks() << "\n";

    std::cout << "Antrian Prioritas Setelah Mengambil Prioritas Tertinggi : ";
    for (int i = 0; i < heap.ukuran(); ++i) {
        std::cout << heap.dapatElemen()[i] << " ";
    }
    std::cout << "\n";

    heap.ubahPrioritas(5, 47);
    std::cout << "Antrian Prioritas Setelah Mengubah Prioritas : ";
    for (int i = 0; i < heap.ukuran(); ++i) {
        std::cout << heap.dapatElemen()[i] << " ";
    }
    std::cout << "\n";

    heap.hapus(5);
    std::cout << "Antrian Prioritas Setelah Menghapus Elemen Pada Indeks Ke-5 : ";
    for (int i = 0; i < heap.ukuran(); ++i) {
        std::cout << heap.dapatElemen()[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

```
Output :

![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/0483ed1d-4eac-4287-ab2b-5a40d6728fcf)

**Class Heap**

- Class `Heap` merepresentasikan struktur heap (tumpukan prioritas).
- Atribut private:
    - `elements`: Vektor bilangan bulat untuk menyimpan elemen-elemen dalam heap.
    - `heapSize`: Variabel integer untuk melacak jumlah elemen saat ini dalam heap.
- Fungsi private:
    - `parent(int i)`: Menghitung indeks induk dari sebuah elemen pada indeks `i`.
    - `leftChild(int i)`: Menghitung indeks anak kiri dari sebuah elemen pada indeks `i`.
    - `rightChild(int i)`: Menghitung indeks anak kanan dari sebuah elemen pada indeks `i`.
    - `shiftUp(int i)`: Fungsi untuk memastikan properti max-heap terjaga dengan menukar elemen ke atas jika elemen anak memiliki nilai lebih tinggi daripada induknya.
    - `shiftDown(int i)`: Fungsi untuk memastikan properti max-heap terjaga dengan menukar elemen ke bawah jika elemen induk memiliki nilai lebih rendah daripada salah satu anaknya.
- Fungsi public:
    - `Heap()`: Konstruktor yang menginisialisasi `heapSize` menjadi -1.
    - `insert(int priority)`: Memasukkan elemen baru dengan prioritas tertentu (`priority`) ke dalam heap.
    - `ambilMaks()`: Mengekstrak elemen dengan prioritas tertinggi (nilai maksimum) dari heap dan mengembalikannya. Menangani kasus heap kosong dengan melempar `std::runtime_error`.
    - `ubahPrioritas(int i, int prioritasBaru)`: Mengubah prioritas elemen pada indeks `i` menjadi `prioritasBaru`. Melakukan `shiftUp` jika prioritas baru lebih tinggi, atau `shiftDown` jika prioritas baru lebih rendah.
    - `dapatMaks() const`: Mengembalikan elemen dengan prioritas tertinggi (nilai maksimum) dari heap tanpa menghapusnya. Menangani kasus heap kosong dengan melempar `std::runtime_error`.
    - `hapus(int i)`: Menghapus elemen pada indeks `i` dari heap. Menangani kasus indeks tidak valid dengan melempar `std::runtime_error`.
    - **Tambahan:**
        - `ukuran() const`: Mengembalikan ukuran heap (jumlah elemen + 1).
        - `dapatElemen() const`: Mengembalikan referensi ke vektor `elements` yang berisi elemen-elemen heap.

**Main Function**

1. Membentuk objek `heap` dari kelas `Heap`.
2. Memasukkan beberapa elemen dengan prioritas berbeda ke dalam heap menggunakan `insert`.
3. Mencetak isi heap saat ini.
4. Mengambil elemen dengan prioritas tertinggi dan mencetaknya menggunakan `ambilMaks`.
5. Mencetak isi heap setelah pengambilan elemen maksimum.
6. Mengubah prioritas elemen pada indeks ke-5 menjadi nilai baru menggunakan `ubahPrioritas`.
7. Mencetak isi heap setelah perubahan prioritas.
8. Menghapus elemen pada indeks ke-5 dari heap menggunakan `hapus`.
9. Mencetak isi heap setelah penghapusan elemen.

### Referensi
[1] Nurcholis, A., Batara, S., & Octamanullah, M. Penerapan struktur data Heap Priority Queue pada algoritma
Djikstra untuk mendapatkan kompleksitas O((n + m)log n), 2020.

[2] Wulandari, C. A., Raharjo, S., & Setiawan, D. Implementasi Priority Queue Berbasis Min-Heap untuk Optimasi Algoritma Huffman Coding. Jurnal Sains dan Teknologi Komputer, 2023.

## 2. HashTable
Hash Table adalah struktur data yang digunakan untuk menyimpan pasangan kunci-nilai. Struktur ini memungkinkan operasi penyimpanan, pencarian, dan penghapusan data dilakukan dengan sangat efisien, biasanya dalam waktu konstan (O(1))[1].
Fungsi hash table adalah sebuah fungsi yang digunakan untuk memetakan nilai kunci yang unik menjadi sebuah indeks pada sebuah tabel. Fungsi hash ini memungkinkan untuk melakukan penambahan, penghapusan, dan pencarian data dengan waktu rata-rata konstan [2]. Fungsi hash table memiliki beberapa kelebihan, seperti kemampuan untuk melakukan pencarian dan penambahan data dengan waktu rata-rata konstan, serta efisiensi dalam penggunaan memori. Namun, fungsi hash table juga memiliki beberapa kelemahan, seperti kemungkinan terjadinya tabrakan (collision) yang memerlukan penanganan khusus untuk mengatasi masalah tersebut[2]. 

Operasi-operasi yang dapat dilakukan pada hash table meliputi :
1. Search (Pencarian): Operasi ini memungkinkan pengguna untuk mencari data yang telah disimpan di dalam hash table dengan menggunakan kunci (key).

2. Insert (Penyisipan): Operasi ini memungkinkan pengguna untuk menambahkan data baru ke dalam hash table dengan menggunakan kunci (key).

3. Delete (Penghapusan): Operasi ini memungkinkan pengguna untuk menghapus data yang telah disimpan di dalam hash table dengan menggunakan kunci (key).

4. Update (Pengubahan): Operasi ini memungkinkan pengguna untuk mengubah data yang telah disimpan di dalam hash table dengan menggunakan kunci (key).

5. Collision Resolution (Penanganan Tabrakan): Operasi ini memungkinkan pengguna untuk mengatasi tabrakan (collision) yang terjadi ketika dua kunci memiliki nilai hash yang sama, sehingga memungkinkan pengguna untuk mengatur bagaimana mengatasi tabrakan tersebut dalam hash table.

Contoh Penggunaan Tabel Hash :
Tabel hash dapat digunakan dalam berbagai aplikasi, seperti:
- Sistem pengindeksan dokumen
- Sistem pengindeksan basis data
- Sistem pengindeksan kata-kata dalam bahasa
- Sistem pengindeksan nomor telepon

Keunggulan Hashtable :
- Akses dan manipulasi data yang sangat cepat.
Implementasi yang fleksibel untuk berbagai jenis data.
Kelemahan:
- Tidak ada urutan elemen yang jelas.
- Memerlukan pemilihan fungsi hash yang baik untuk mengurangi tabrakan.
- Konsumsi memori yang lebih besar dibandingkan struktur data lain.

### Kode Program :
```c++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (size_t i = 0; i < key.length(); ++i) {
            hash_val += key[i];
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (vector<HashNode*>::iterator it = table[hash_val].begin(); it != table[hash_val].end(); ++it) {
            if ((*it)->name == name) {
                (*it)->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (vector<HashNode*>::iterator it = table[hash_val].begin(); it != table[hash_val].end(); ++it) {
            if ((*it)->name == name) {
                delete *it;
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (vector<HashNode*>::iterator it = table[hash_val].begin(); it != table[hash_val].end(); ++it) {
            if ((*it)->name == name) {
                return (*it)->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";
            for (vector<HashNode*>::iterator it = table[i].begin(); it != table[i].end(); ++it) {
                if (*it != NULL) {
                    cout << "[" << (*it)->name << ", " << (*it)->phone_number << "] ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomor Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomor Hp Mistah Setelah Dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```
Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/5538cc78-97b0-40bf-897a-ea5f93352351)


1. Definisi Konstanta dan Header
    - Header file yang digunakan: iostream untuk input/output, string untuk menangani string, dan vector untuk menggunakan vektor dari STL.
    - TABLE_SIZE adalah konstanta yang menentukan ukuran tabel hash, yang diatur menjadi 11.
    - name dan phone_number adalah variabel string global yang digunakan.

2. Class HashNode
    - HashNode adalah kelas yang menyimpan pasangan nama (name) dan nomor telepon (phone_number).
    - Konstruktor kelas HashNode menginisialisasi dua atribut ini.

3. Class HashMap
    - Hash Function (hashFunc): Menghitung nilai hash berdasarkan penjumlahan nilai ASCII dari setiap karakter dalam string, kemudian - hasilnya dimodulus dengan TABLE_SIZE untuk mendapatkan indeks tabel.
    -  Insertion (insert): Menambahkan pasangan nama dan nomor telepon ke dalam hash table. Jika nama sudah ada, nomor telepon diperbarui. Jika tidak, node baru ditambahkan ke list pada indeks yang sesuai.
    - Deletion (remove): Menghapus pasangan nama dan nomor telepon dari hash table. Jika nama ditemukan, node dihapus dan memori dibebaskan.
    - Searching (searchByName): Mencari nomor telepon berdasarkan nama. Mengembalikan nomor telepon jika nama ditemukan, atau string kosong jika tidak ditemukan.
    - Print (print): Menampilkan semua elemen dalam hash table. Menampilkan indeks tabel dan pasangan nama-nomor telepon dalam format [name, phone_number].

4. Fungsi main
    - Insertion: Menambahkan tiga pasangan nama-nomor telepon (Mistah: 1234, Pastah: 5678, Ghana: 91011).
    -   Searching: Mencari nomor telepon untuk nama "Mistah" dan "Pastah".
    - Deletion: Menghapus pasangan nama-nomor telepon untuk "Mistah".
    - Print: Menampilkan semua elemen dalam hash table.

### Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.

[2] Weiss, M. A. (2012). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson. 

## 3. Rekursif
Rekursif adalah sub program yang memanggil dirinya sendiri selama kondisi pemanggilan dipenuhi. Rekursif umumnya dipakai untuk permasalahan yang memiliki langkah penyelesaian yang terpola atau langkah-langkah yang teratur. Bila ada suatu permasalahan dan sudah diketahui algoritma penyelesaiannya, maka sub program rekursif dapat menjadi pilihan untuk digunakan[1].

**Cara Kerja Rekursif**

Fungsi rekursif bekerja dengan memanggil dirinya sendiri secara berulang hingga mencapai kondisi dasar (base case). Kondisi dasar ini adalah titik henti rekursi dan memastikan bahwa fungsi tidak memanggil dirinya sendiri secara tak terbatas, mencegah stack overflow.

**Jenis-Jenis Rekursif**

Terdapat dua jenis fungsi rekursi:

- Rekursi Langsung (Direct Recursion): Fungsi memanggil dirinya sendiri secara langsung .
- Rekursi Tidak Langsung (Indirect Recursion): Fungsi memanggil dirinya sendiri secara tidak langsung melalui fungsi lain.

**Kelebihan dan Kekurangan Rekursif**

**Kelebihan:**
- Kesederhanaan: Rekursi seringkali menghasilkan kode yang lebih bersih dan mudah dipahami untuk masalah kompleks.
Penyelesaian Masalah yang Alami: Beberapa masalah, seperti traversal pohon atau algoritma Divide and Conquer (misalnya, Merge Sort), lebih mudah diimplementasikan secara rekursif [2].

**Kekurangan:**
- Overhead Memori: Setiap panggilan rekursif menyimpan status fungsi di stack, yang dapat menyebabkan penggunaan memori yang besar dan potensi stack overflow.
- Kinerja: Rekursi dapat lebih lambat dibandingkan iterasi karena overhead pemanggilan fungsi berulang kali [2].

### Kode Program
```c++
#include <iostream>
/// Rekursif Langsung
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorial(number);
        cout << "Faktorial dari " << number << " adalah: " << result << endl;
    }

    return 0;
}

```

Output :

![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/e4be85a3-6ca9-4572-a76f-af3c3ff7984e)



1. **Deklarasi dan Definisi Fungsi `factorial`**:
   - `int factorial(int n) { if (n == 0) { return 1; } return n * factorial(n - 1); }`
     - Fungsi `factorial` menerima satu argumen `n` (sebuah bilangan bulat).
     - Basis kasus: Jika `n` sama dengan 0, fungsi mengembalikan 1. Ini karena faktorial dari 0 (0!) adalah 1.
     - Rekursi: Jika `n` bukan 0, fungsi mengembalikan hasil dari `n` dikalikan dengan `factorial(n - 1)`. Ini mengimplementasikan definisi faktorial `n! = n * (n-1)!`.

2. **Fungsi `main`**:
   - `int main() { int number; cout << "Masukkan bilangan bulat positif: "; cin >> number; ... }`
     - Deklarasi variabel `number` untuk menyimpan input pengguna.
     - Mencetak pesan "Masukkan bilangan bulat positif: " untuk meminta pengguna memasukkan sebuah bilangan bulat positif.
     - Membaca input dari pengguna dan menyimpannya di `number`.

3. **Validasi Input dan Perhitungan Faktorial**:
   - `if (number < 0) { cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl; }`
     - Memeriksa apakah `number` kurang dari 0. Jika ya, mencetak pesan bahwa input tidak valid karena faktorial hanya didefinisikan untuk bilangan bulat positif (termasuk 0).
   - `else { int result = factorial(number); cout << "Faktorial dari " << number << " adalah: " << result << endl; }`
     - Jika `number` tidak kurang dari 0, maka menghitung faktorial dari `number` dengan memanggil fungsi `factorial(number)`.
     - Menyimpan hasil perhitungan dalam variabel `result`.
     - Mencetak hasil faktorial dari `number`.

4. **Pengembalian dari `main`**:
   - `return 0;`: Menandakan bahwa program selesai dengan sukses.




###  Referensi 
[1] U. Indahyanti and Y. Rahmawati, “Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++”, umsidapress, pp. 1-146, Aug. 2021.

[2] Putra, Muhammad Taufik Dwi, Munawir Munawir, and Ana Rahma Yuniarti. "BELAJAR PEMROGRAMAN LANJUT DENGAN C++." 2023.

## Graph & Tree
Graph dan tree adalah dua struktur data yang penting dalam pemrograman dan algoritma. Keduanya digunakan untuk merepresentasikan hubungan atau struktur hierarki antara entitas[1]. Meskipun keduanya memiliki persamaan dalam beberapa aspek, mereka juga memiliki perbedaan yang signifikan dalam sifat dan penggunaannya.

**Graph:**
- Graph adalah struktur data yang terdiri dari serangkaian simpul (nodes) yang terhubung oleh sisi (edges).
- Setiap sisi dapat memiliki bobot atau tidak, tergantung pada apakah grafnya berbobot atau tidak.
- Graph dapat digunakan untuk merepresentasikan berbagai jenis hubungan antara entitas, seperti jaringan sosial, jaringan komputer, rute perjalanan, dan banyak lagi.
- Graph dapat dibagi menjadi dua jenis utama:
  - Directed Graph (digraf): Graf di mana setiap sisi memiliki arah.
  - Undirected Graph (graf tak berarah): Graf di mana sisi-sisinya tidak memiliki arah.

Ada beberapa jenis graph yang umum digunakan:

- Directed Graph (Digraph): Graph di mana setiap busur memiliki arah, sehingga hubungan antara dua simpul tidak selalu saling simetris.
- Undirected Graph: Graph di mana setiap busur tidak memiliki arah, sehingga hubungan antara dua simpul bersifat simetris.
- Weighted Graph: Graph di mana setiap busur memiliki bobot yang menyatakan nilai numerik yang terkait dengan busur tersebut.
- Cyclic Graph: Graph yang memiliki setidaknya satu siklus, yaitu rangkaian simpul yang membentuk jalur tertutup.
- Acyclic Graph: Graph yang tidak memiliki siklus, sehingga tidak ada jalur yang membentuk loop.

**Tree:**
- Tree adalah jenis khusus dari graf yang tidak memiliki sirkuit tertutup (cycle), artinya tidak ada dua simpul yang terhubung oleh lebih dari satu jalur[2].
- Setiap simpul dalam tree memiliki tepat satu simpul induk (parent), kecuali simpul teratas yang disebut sebagai akar (root).
- Tree sering digunakan untuk merepresentasikan hierarki, seperti struktur file dalam sistem operasi, struktur organisasi dalam perusahaan, atau struktur gen dalam biologi.
- Beberapa jenis tree yang umum digunakan meliputi:
  - Binary Tree: Setiap simpul memiliki maksimal dua anak.
  - Binary Search Tree (BST): Binary tree di mana setiap simpul memiliki nilai yang lebih besar dari semua nilai di anak kiri dan lebih kecil dari semua nilai di anak kanan.

### Kode Program
```c++
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
```

Output :
![image](https://github.com/Gustavers/Laporan-Praktikum/assets/162097300/2b8cb4f3-37eb-4d8c-9407-4c0afcec3e45)

Kode di atas merupakan program dalam bahasa C yang memungkinkan pengguna untuk memasukkan jumlah simpul dari sebuah graf, nama-nama simpul, dan bobot antar simpul. Program kemudian menampilkan matriks bobot yang merepresentasikan graf berdasarkan masukan pengguna.

- Pertama, program meminta pengguna untuk memasukkan jumlah simpul.
- Kemudian, program meminta pengguna untuk memasukkan nama-nama simpul satu per satu.
- Selanjutnya, pengguna diminta untuk memasukkan bobot antar simpul, yang direpresentasikan sebagai matriks bobot.
- Setelah itu, program menampilkan matriks bobot tersebut di layar.
- Selanjutnya, program melakukan simulasi proses yang memakan waktu (dalam contoh ini, sebuah loop yang berjalan sebanyak 100 juta kali).
- Program juga mencatat waktu eksekusi dari awal hingga akhir proses yang memakan waktu tersebut.
- Terakhir, program mencetak waktu eksekusi yang dihabiskan dan pesan untuk menekan tombol apa pun untuk melanjutkan.

Saat dijalankan, program akan meminta input dari pengguna, menampilkan matriks bobot, mencatat waktu eksekusi dari proses simulasi, dan kemudian mengakhiri program setelah pengguna menekan tombol apa pun.

### Referensi
[1] Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. (2009). "Introduction to Algorithms, Third Edition." MIT Press.

[2] Robert Sedgewick and Kevin Wayne. (2011). "Algorithms, Fourth Edition." Addison-Wesley.
    