// Program      : Palindrom
// Deskripsi    : Menentukan apakah string yang diinputkan merupakan palindrom.
// Tanggal      : 01/11/2023
// Versioning   : 1.0.0
// Penyusun     : Rayhan Rizqi Zamzamy, Khoirur Rohman, Ardyan Bagas Trihutama.

#include <iostream>
#include <string>
#include <cctype>
// Definisi logika komparatif untuk menentukan apakah
// Karakter berada di range alfabet dan angka.
#define IS_ALPHA(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
#define IS_NUM(c) (c >= '0' && c <= '9')
#define IS_ALPHANUM(c) (IS_ALPHA(c) || IS_NUM(c))

using namespace std;
// Enumerasi set karakter yang akan digunakan sebagai mode
// palindrom. Bisa alfabetik, numerik, maupun alfanumerik.
enum charSet{ALPHABETICAL, NUMERICAL, ALPHANUMERICAL};
// Variabel kerja.
string text;
// Mode yang bisa digunakan:
// - (0) ALPHABETICAL <enum>: Hanya periksa karakter alfabet.
// - (1) NUMERICAL <enum>: Hanya periksa karakter angka.
// - (2) ALPHANUMERICAL <enum>: Hanya periksa karakter alfabet dan angka.
// Di luar enumerasi yang ada, seluruh karakter diperiksa.
// Bisa menggunakan kode integer (lihat dalam kurung). Nilai selain 0..2,
// dianggap mode lainnya (seluruh karakter diperiksa).
int mode = ALPHANUMERICAL;

// Fungsi untuk menentukan palindrom dari sebuah teks.
// Parameter
// - txt <string>: Teks yang akan diperiksa.
// - cSet <int>: Set karakter yang digunakan (enumerasi). Default: ALPHANUMERICAL.
// - cSens <bool>: Apakah pemeriksaan case-sensitive? Default: false.
// Return value
// - true <bool>: Jika teks sama ketika dibaca maju maupun mundur.
// - false <bool>: Jika teks kosong, di luar set karakter, atau tidak memenuhi kriteria true.
bool palindrom(string txt, int cSet = ALPHANUMERICAL, bool cSens = false){
    // Iterasi untuk setiap karakter di txt. Hanya ambil karakter yang sesuai
    // dengan set karakter dan simpan di filtered. Abaikan karakter lainnya.
    string filtered;
    for(char c : txt){
        switch(cSet){
            case ALPHABETICAL: if(IS_ALPHA(c)) filtered += c; break;
            case NUMERICAL: if(IS_NUM(c)) filtered += c; break;
            case ALPHANUMERICAL: if(IS_ALPHANUM(c)) filtered += c; break;
            default: filtered += c; break;
        }
    }
    // Jika pemeriksaan tidak case-sensitive, ubah semua karakter ke lowercase.
    // Iterasikan untuk semua karakter di filtered. Hasil kembali ke filtered.
    if(!cSens)
        for (char &i : filtered)
            i = tolower(i);
    // Periksa palidrom dari teks yang sudah disaring. Jika semua karakter
    // tersaring, kembalikan false. Iterasi karakter mulai dari ujung (awal & akhir)
    // hingga ke tengah. Jika saat pemeriksaan sepasang karakter tidak sama,
    // kembalikan false. Jika semua karakter melewati pemeriksaan, kambalikan true.
    if(filtered.empty()) return false;
    for(int start = 0, end = filtered.length() - 1;start < end; start++, end--)
        if(filtered[start] != filtered[end]) return false;
    return true;
}

int main(){
    // Input.
    cout << "Masukan teks:" << endl;
    getline(cin, text);
    // Proses & Output.
    cout << "Teks " << "\"" << text << "\" "
         << ((palindrom(text, mode)) ? "palindrom" : "bukan palidrom")
         << " secara " << ((mode == ALPHABETICAL) ? "alfabetik" :
                           (mode == NUMERICAL) ? "numerik" : 
                           (mode == ALPHANUMERICAL) ? "alfanumerik" : 
                           "keseluruhan") << ".";

    return 0;
}
