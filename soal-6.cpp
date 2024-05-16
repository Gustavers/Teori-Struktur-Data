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