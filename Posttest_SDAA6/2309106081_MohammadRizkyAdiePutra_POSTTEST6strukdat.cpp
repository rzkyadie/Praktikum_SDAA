// posttest 6 struktur data
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

// Fungsi untuk Fibonacci Search (di data stok)
int fibonacciSearch(int arr[], int n, int x) {
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib2 + fib1;
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else
            return i;
    }

    if (fib1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

// Fungsi untuk Jump Search (di data stok)
int jumpSearch(int arr[], int n, int x) {
    int step = 2;
    int prev = 0;

    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += 2;
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

// Fungsi untuk Boyer-Moore (pada data nama)
int boyerMooreSearch(string text, string pattern) {
    int m = pattern.length();
    int n = text.length();
    int badChar[256];

    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < m; i++)
        badChar[(int) pattern[i]] = i;

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            return s;
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {
            s += max(1, j - badChar[text[s + j]]);
        }
    }

    return -1;
}

// Fungsi untuk mencari roti berdasarkan stok (menggunakan Fibonacci/Jump Search)
void cariRotiBerdasarkanStok(Roti* head, int stokDicari) {
    Roti* temp = head;
    int arr[100], index = 0;

    while (temp != nullptr) {
        arr[index++] = temp->stok;
        temp = temp->next;
    }

    // Cari menggunakan Fibonacci Search atau Jump Search
    cout << "Menggunakan Fibonacci Search...\n";
    int hasilFibonacci = fibonacciSearch(arr, index, stokDicari);
    if (hasilFibonacci != -1) {
        cout << "Stok ditemukan dengan Fibonacci Search di index: " << hasilFibonacci << endl;
    } else {
        cout << "Stok tidak ditemukan dengan Fibonacci Search.\n";
    }

    cout << "Menggunakan Jump Search...\n";
    int hasilJump = jumpSearch(arr, index, stokDicari);
    if (hasilJump != -1) {
        cout << "Stok ditemukan dengan Jump Search di index: " << hasilJump << endl;
    } else {
        cout << "Stok tidak ditemukan dengan Jump Search.\n";
    }
}

// Fungsi untuk mencari roti berdasarkan nama (menggunakan Boyer-Moore)
void cariRotiBerdasarkanNama(Roti* head, string namaDicari) {
    Roti* temp = head;

    while (temp != nullptr) {
        int hasil = boyerMooreSearch(temp->nama, namaDicari);
        if (hasil != -1) {
            cout << "Nama roti ditemukan: " << temp->nama << endl;
        } else {
            cout << "Nama roti tidak ditemukan pada: " << temp->nama << endl;
        }
        temp = temp->next;
    }
}

int main() {
    Roti* head = nullptr;
    int pilihan;

    do {
        cout << "\nMenu Manajemen Toko Roti\n";
        cout << "1. Tambah Roti\n";
        cout << "2. Tampilkan Semua Roti\n";
        cout << "3. Cari Berdasarkan Stok (Fibonacci & Jump Search)\n";
        cout << "4. Cari Berdasarkan Nama (Boyer-Moore)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahRoti(head);
            break;
        case 2:
            tampilkanRoti(head);
            break;
        case 3: {
            int stokDicari;
            cout << "Masukkan stok yang dicari: ";
            cin >> stokDicari;
            cariRotiBerdasarkanStok(head, stokDicari);
            break;
        }
        case 4: {
            string namaDicari;
            cout << "Masukkan nama roti yang dicari: ";
            cin.ignore();
            getline(cin, namaDicari);
            cariRotiBerdasarkanNama(head, namaDicari);
            break;
        }
        case 5:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (pilihan != 5);

    return 0;
}