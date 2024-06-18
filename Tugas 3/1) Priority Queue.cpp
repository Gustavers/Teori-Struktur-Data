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