#include <iostream>
#include <string>
using namespace std;

// Asmar
const int KAPASITAS_MAKS = 50; 
int jumlahAktif = 24;

// Dzaky
string daftarJudul[KAPASITAS_MAKS] = {
    "Attack on Titan", 
    "Golden Kamuy",
    "Death Note", 
    "Kimetsu no Yaiba", 
    "Jujutsu Kaisen", 
    "Fullmetal Alchemist: Brotherhood", 
    "Your Name", 
    "Spirited Away",
    "Chainsaw Man",
    "Vinland Saga",
    "Tsuki ga Michibiku Isekai Douchuu",
    "Bleach",
    "Naruto",
    "Zero no Tsukaima: Princesses no Rondo",
    "tenki no ko",
    "Otonari no Tenshi-sama ni Itsunomanika Dame Ningen ni Sareteita Ken",
    "konosuba",
    "Inuyasha",
    "Trigun",
    "Hunter x Hunter",
    "Sword Art Online",
    "Overlord",
    "Detective Conan",
    "Hellsing Ultimate"  
};

int daftarTahun[KAPASITAS_MAKS] = {
    2013,
    2018,
    2006,
    2019,
    2020,
    2009,
    2016,
    2001,
    2022,
    2019,
    2021,
    2004,
    2002,
    2008,
    2019,
    2023,
    2016,
    2000,
    1998,
    1999,
    2012,
    2015,
    1996,
    2006  
};
//kris
bool cekAnimeSudahAda(string judulBaru) {
    for (int i = 0; i < jumlahAktif; i++) {
        if (daftarJudul[i] == judulBaru) {
            return true;
        }
    }
    return false;
}

void tambahAnime() {
    string judulBaru;

    if (jumlahAktif >= KAPASITAS_MAKS) {
        cout << "\nDatabase anime sudah penuh!\n";
        return;
    }

    cout << "\n=== TAMBAH ANIME BARU ===\n";

    cin.ignore(1000, '\n');

    cout << "Masukkan judul anime : ";
    getline(cin, judulBaru);

    if (cekAnimeSudahAda(judulBaru)) {

        cout << "\nAnime yang ditambahkan sudah ada dalam list!\n";
        return;
    }

    cout << "Masukkan tahun rilis : ";

    while (!(cin >> daftarTahun[jumlahAktif])) {
        cout << "Input salah! Masukkan tahun berupa angka: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    daftarJudul[jumlahAktif] = judulBaru;

    jumlahAktif++;

    cout << "\nAnime berhasil ditambahkan!\n";
}

void hapusAnime() {
    int tahunFilter;
    string judulHapus;
    int indeks = -1;
    bool adaTahun = false;

    if (jumlahAktif == 0) {
        cout << "\nDatabase anime masih kosong!\n";
        return;
    }

    cout << "\n=== HAPUS ANIME BERDASARKAN TAHUN ===\n";
    cout << "Masukkan tahun rilis anime yang ingin dilihat: ";
    
    while (!(cin >> tahunFilter)) {
        cout << "Input salah! Masukkan tahun berupa angka: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "\n--- Daftar Anime Tahun " << tahunFilter << " ---\n";

    for (int i = 0; i < jumlahAktif; i++) {
        if (daftarTahun[i] == tahunFilter) {
            cout << "- " << daftarJudul[i] << "\n";
            adaTahun = true;
        }
    }

    if (!adaTahun) {
        cout << "Tidak ada anime yang ditemukan pada tahun " << tahunFilter << ".\n";
        return;
    }

    cout << "\n";
    cin.ignore(1000, '\n');

    // break

    cout << "Masukkan judul anime yang ingin dihapus : ";
    getline(cin, judulHapus);

    for (int i = 0; i < jumlahAktif; i++) {
        if (daftarJudul[i] == judulHapus && daftarTahun[i] == tahunFilter) {
            indeks = i;
            break;
        }
    }

    if (indeks == -1) {
        cout << "\nAnime \"" << judulHapus << "\" pada tahun " << tahunFilter << " tidak ditemukan!\n";
        return;
    }

    for (int i = indeks; i < jumlahAktif - 1; i++) {
        daftarJudul[i] = daftarJudul[i + 1];
        daftarTahun[i] = daftarTahun[i + 1];
    }

    jumlahAktif--;

    cout << "\nAnime berhasil dihapus!\n";
}

//abdi
void cariAnimeBerdasarkanTahun(int tahunCari){

    bool statusTempat = false;
    cout << "\n--- Hasil Pencarian untuk Tahun " << tahunCari << " ---\n";
    
    for (int i = 0; i < jumlahAktif; i++) {

        if (daftarTahun[i] == tahunCari) {
            cout << "Ditemukan: " << daftarJudul[i] << " (Dirilis tahun " << daftarTahun[i] << ")\n";
            statusTempat = true;
        }        
    }   
    

    if (!statusTempat) {
        cout << "Tidak ada anime yang ditemukan pada tahun " << tahunCari << ".\n";
    }
}

int main() {
    int pilihanMenu;
    char lanjut;

    do {
        system("clear");
        cout << "========================================\n";
        cout << "       PROGRAM PENCARIAN ANIME          \n";
        cout << "========================================\n";
        cout << "1. Cari Anime Berdasarkan Tahun\n";
        cout << "2. Tambah Anime Baru\n";
        cout << "3. Hapus Anime\n";
        cout << "4. Exit\n";
        cout << "Pilih menu (1-4): ";

        while (!(cin >> pilihanMenu) || pilihanMenu < 1 || pilihanMenu > 4) {
            cout << "Pilihan salah! Masukkan angka 1, 2, 3, atau 4: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (pilihanMenu == 1) {
            int inputTahun;
            cout << "----------------------------------------\n";
            cout << "Masukkan tahun rilis anime: ";
            while (!(cin >> inputTahun)) {
                cout << "Input salah! Masukkan tahun berupa angka: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cariAnimeBerdasarkanTahun(inputTahun);
        } 
        else if (pilihanMenu == 2) {
            tambahAnime();
        } 
        else if (pilihanMenu == 3) {
            hapusAnime();
        }
        else if (pilihanMenu == 4) {
            return 0;
        }

        cout << "\n----------------------------------------\n";
        cout << "Apakah anda ingin kembali ke menu utama? (Y/t): ";
        cin >> lanjut;
        
        while (lanjut != 'Y' && lanjut != 'y' && lanjut != 'T' && lanjut != 't') {
            cout << "Pilihan salah! Masukkan Y atau T: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> lanjut;
        }
        cout << "\n";
    } while (lanjut == 'Y' || lanjut == 'y');

    return 0;
}