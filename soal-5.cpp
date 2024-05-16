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
