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
