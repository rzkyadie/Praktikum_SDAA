// posttest 4 struktur data
// mohammad rizky adie putra
// 2309106081
#include <iostream>
#include <string>
using namespace std;

// Struktur buat menyimpan data roti
struct Roti {
    string nama;
    float harga;
    int stok;
    Roti* next;
};

// Struktur buat menyimpan data buat undo
struct Stack {
    Roti* roti;
    Stack* next;
};

// Struktur buat menyimpan data antrian pembeli
struct Queue {
    string namaPembeli;
    Queue* next;
};

// Fungsi buat menambah roti ke daftar
void tambahRoti(Roti*& head) {
    Roti* rotiBaru = new Roti;
    cout << "Masukkan nama roti: ";
    cin.ignore();
    getline(cin, rotiBaru->nama);
    cout << "Masukkan harga roti: ";
    cin >> rotiBaru->harga;
    cout << "Masukkan jumlah stok roti: ";
    cin >> rotiBaru->stok;

    // Menambahkan roti baru ke akhir daftar
    rotiBaru->next = nullptr;
    if (head == nullptr) {
        head = rotiBaru;
    } else {
        Roti* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = rotiBaru;
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

// Fungsi untuk menghapus roti dan menyimpan di stack buat undo
void hapusRoti(Roti*& head, Stack*& top) {
    if (head == nullptr) {
        cout << "Tidak ada roti yang bisa dihapus.\n";
        return;
    }

    int nomor;
    cout << "Masukkan nomor roti yang ingin dihapus: ";
    cin >> nomor;

    Roti* temp = head;
    Roti* prev = nullptr;

    // Mencari roti yang bakal dihapus
    for (int i = 1; i < nomor && temp != nullptr; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != nullptr) {
        // Simpan roti yang dihapus ke stack buat di undo
        Stack* nodeBaru = new Stack;
        nodeBaru->roti = temp;
        nodeBaru->next = top;
        top = nodeBaru;
        
        // Hapus roti dari linked list
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        cout << "Roti berhasil dihapus dan disimpan di stack (untuk undo).\n";
    } else {
        cout << "Nomor roti tidak ditemukan.\n";
    }
}

// Fungsi untuk undo penghapusan roti, diambil dari stack
void undoHapusRoti(Roti*& head, Stack*& top) {
    if (top == nullptr) {
        cout << "Tidak ada penghapusan yang bisa di-undo.\n";
        return;
    }

    // Mengembalikan roti dari stack ke daftar roti
    Roti* rotiDikembalikan = top->roti;
    top = top->next;

    if (head == nullptr) {
        head = rotiDikembalikan;
    } else {
        Roti* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = rotiDikembalikan;
    }

    cout << "Roti berhasil dikembalikan ke daftar.\n";
}

// Fungsi untuk menambahkan pembeli ke antrian (queue)
void tambahPembeli(Queue*& front, Queue*& rear) {
    Queue* pembeliBaru = new Queue;
    cout << "Masukkan nama pembeli: ";
    cin.ignore();
    getline(cin, pembeliBaru->namaPembeli);
    pembeliBaru->next = nullptr;

    // Tambah ke antrian (queue)
    if (rear == nullptr) {
        front = rear = pembeliBaru;
    } else {
        rear->next = pembeliBaru;
        rear = pembeliBaru;
    }

    cout << "Pembeli berhasil ditambahkan ke antrian.\n";
}

// Fungsi buat layani pembeli dari antrian
void layaniPembeli(Queue*& front, Queue*& rear) {
    if (front == nullptr) {
        cout << "Tidak ada pembeli dalam antrian.\n";
        return;
    }

    // Layani pembeli di antrian pertama atau dequeue
    Queue* temp = front;
    cout << "Melayani pembeli: " << temp->namaPembeli << endl;

    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
}

int main() {
    Roti* head = nullptr;
    Stack* top = nullptr;
    Queue* front = nullptr;
    Queue* rear = nullptr;
    int pilihan;

    do {
        cout << "--------------------------\n";
        cout << " Menu Manajemen Toko Roti\n";
        cout << "--------------------------\n";
        cout << "1. Tambah Roti\n";
        cout << "2. Tampilkan Semua Roti\n";
        cout << "3. Hapus Roti\n";
        cout << "4. Undo Hapus Roti\n";
        cout << "5. Tambah Pembeli ke Antrian\n";
        cout << "6. Layani Pembeli\n";
        cout << "7. Keluar\n";
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
            hapusRoti(head, top);
            break;
        case 4:
            undoHapusRoti(head, top);
            break;
        case 5:
            tambahPembeli(front, rear);
            break;
        case 6:
            layaniPembeli(front, rear);
            break;
        case 7:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (pilihan != 7);

    return 0;
}