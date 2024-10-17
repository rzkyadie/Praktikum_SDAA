// posttest 5 struktur data
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

// Fungsi tambahan Merge Sort (Ascending)
Roti* merge(Roti* left, Roti* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->harga <= right->harga) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

void split(Roti* source, Roti** front, Roti** back) {
    Roti* fast;
    Roti* slow;
    slow = source;
    fast = source->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

void mergeSort(Roti** headRef) {
    Roti* head = *headRef;
    Roti* a;
    Roti* b;

    if (!head || !head->next) {
        return;
    }

    split(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = merge(a, b);
}

// Fungsi tambahan Quick Sort (Descending)
Roti* partition(Roti* head, Roti** front, Roti** back) {
    Roti* pivot = head;
    Roti* current = head->next;
    Roti* left = nullptr;
    Roti* right = nullptr;

    while (current != nullptr) {
        Roti* next = current->next;
        if (current->harga >= pivot->harga) {
            current->next = left;
            left = current;
        } else {
            current->next = right;
            right = current;
        }
        current = next;
    }

    *front = left;
    *back = right;
    return pivot;
}

Roti* quickSortRecursive(Roti* head) {
    if (!head || !head->next) {
        return head;
    }

    Roti* left = nullptr;
    Roti* right = nullptr;
    Roti* pivot = partition(head, &left, &right);

    left = quickSortRecursive(left);
    right = quickSortRecursive(right);

    if (left) {
        Roti* temp = left;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = pivot;
    }

    pivot->next = right;
    return left ? left : pivot;
}

void quickSort(Roti** headRef) {
    *headRef = quickSortRecursive(*headRef);
}

// Fungsi tambahan untuk menampilkan pilihan sorting
void pilihSorting(Roti*& head) {
    int pilihanSort;
    cout << "Pilih metode sorting:\n";
    cout << "1. Merge Sort (Ascending)\n";
    cout << "2. Quick Sort (Descending)\n";
    cout << "Pilihan: ";
    cin >> pilihanSort;

    switch (pilihanSort) {
        case 1:
            mergeSort(&head);
            cout << "Daftar roti berhasil diurutkan dengan Merge Sort (Ascending).\n";
            break;
        case 2:
            quickSort(&head);
            cout << "Daftar roti berhasil diurutkan dengan Quick Sort (Descending).\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }
}

// Fungsi untuk menambah roti ke daftar
void tambahRoti(Roti*& head) {
    Roti* rotiBaru = new Roti;
    cout << "Masukkan nama roti: ";
    cin.ignore();
    getline(cin, rotiBaru->nama);
    cout << "Masukkan harga roti: ";
    cin >> rotiBaru->harga;
    cout << "Masukkan jumlah stok roti: ";
    cin >> rotiBaru->stok;

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

int main() {
    Roti* head = nullptr;
    int pilihan;

    do {
        cout << "--------------------------\n";
        cout << " Menu Manajemen Toko Roti\n";
        cout << "--------------------------\n";
        cout << "1. Tambah Roti\n";
        cout << "2. Tampilkan Semua Roti\n";
        cout << "3. Urutkan Roti\n";
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
            pilihSorting(head);
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