// posttest 3 struktur data
// mohammad rizky adie putra
// 2309106081
#include <iostream>
#include <string>
using namespace std;

// Struct buat menyimpan data roti ke data berikutnya
struct Roti {
    string nama;
    float harga;
    int stok;   
    Roti* next;  
};

// Fungsi buat menambahkan roti baru ke linked list
void tambahRoti(Roti*& head) {
    Roti* rotiBaru = new Roti; 
    cout << "Masukkan nama roti: ";
    cin.ignore();
    getline(cin, rotiBaru->nama); 
    cout << "Masukkan harga roti: ";
    cin >> rotiBaru->harga;       
    cout << "Masukkan stok roti: ";
    cin >> rotiBaru->stok;        

    rotiBaru->next = nullptr; // Set next nya menjadi nullptr (karena ini roti terakhir)

    if (head == nullptr) { // kalau belum ada roti di list
        head = rotiBaru;   // Roti baru menjadi roti pertama (head)
    } else {
        Roti* temp = head;
        while (temp->next != nullptr) { // Cari sampai akhir list nya
            temp = temp->next;
        }
        temp->next = rotiBaru; // Tambahkan roti baru di akhir list nya
    }

    cout << "Roti berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan semua roti
void tampilkanRoti(Roti* head) {
    if (head == nullptr) {
        cout << "Tidak ada roti yang tersedia.\n";
        return;
    }

    Roti* temp = head;
    int no = 1;
    while (temp != nullptr) {
        cout << "--------------------\n";
        cout << "Roti " << no << ": " << temp->nama << endl;
        cout << "Harga: " << temp->harga << endl;
        cout << "Stok: " << temp->stok << endl;
        cout << "--------------------\n";
        temp = temp->next;
        no++;
    }
}

// Fungsi buat hapus roti berdasarkan nomor urut
void hapusRoti(Roti*& head) {
    if (head == nullptr) {
        cout << "Tidak ada roti yang bisa dihapus.\n";
        return;
    }

    int nomor;
    cout << "Masukkan nomor roti yang ingin dihapus: ";
    cin >> nomor;

    if (nomor == 1) {
        Roti* temp = head;
        head = head->next; 
        delete temp;
        cout << "Roti pertama berhasil dihapus!\n";
        return;
    }

    Roti* temp = head;
    Roti* prev = nullptr;
    for (int i = 1; i < nomor && temp != nullptr; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != nullptr) {
        prev->next = temp->next;
        delete temp;
        cout << "Roti berhasil dihapus!\n";
    } else {
        cout << "Nomor roti tidak ditemukan.\n";
    }
}

int main() {
    Roti* head = nullptr;
    int pilihan;

    do {
        cout << "\nMenu Manajemen Toko Roti\n";
        cout << "1. Tambah Roti\n";
        cout << "2. Tampilkan Semua Roti\n";
        cout << "3. Hapus Roti\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahRoti(head); 
            break;
        case 2:
            tampilkanRoti(head); 
            break;
        case 3:
            hapusRoti(head);  
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (pilihan != 4);

    return 0;
}