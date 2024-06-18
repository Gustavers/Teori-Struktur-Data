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