// posttest 2 struktur data
// mohammad rizky adie putra
// 2309106081
#include <iostream>
#include <string>
using namespace std;

struct Roti
{
    string nama;
    float harga;
    int stok;
};

void tambahRoti(Roti *daftarRoti, int &jumlahRoti)
{
    cout << "Masukkan nama roti: ";
    cin.ignore();
    getline(cin, daftarRoti[jumlahRoti].nama);
    cout << "Masukkan harga roti: ";
    cin >> daftarRoti[jumlahRoti].harga;
    cout << "Masukkan jumlah stok roti: ";
    cin >> daftarRoti[jumlahRoti].stok;
    jumlahRoti++;
    cout << "Roti berhasil ditambahkan!\n";
}

void tampilkanRoti(Roti *daftarRoti, int jumlahRoti)
{
    if (jumlahRoti == 0)
    {
        cout << "Tidak ada roti yang tersedia.\n";
        return;
    }
    for (int i = 0; i < jumlahRoti; i++)
    {
        cout << "Roti " << i + 1 << ": " << daftarRoti[i].nama << endl;
        cout << "Harga: " << daftarRoti[i].harga << endl;
        cout << "Stok: " << daftarRoti[i].stok << endl;
        cout << "---------------------------\n";
    }
}

void updateRoti(Roti *daftarRoti, int jumlahRoti)
{
    int pilihan;
    tampilkanRoti(daftarRoti, jumlahRoti);
    cout << "Pilih nomor roti yang ingin diperbarui: ";
    cin >> pilihan;
    if (pilihan > 0 && pilihan <= jumlahRoti)
    {
        int index = pilihan - 1;
        cout << "Masukkan nama baru: ";
        cin.ignore();
        getline(cin, daftarRoti[index].nama);
        cout << "Masukkan harga baru: ";
        cin >> daftarRoti[index].harga;
        cout << "Masukkan stok baru: ";
        cin >> daftarRoti[index].stok;
        cout << "Roti berhasil diperbarui!\n";
    }
    else
    {
        cout << "Pilihan tidak valid.\n";
    }
}

// Fungsi buat hapus roti
void hapusRoti(Roti *daftarRoti, int &jumlahRoti)
{
    int pilihan;
    tampilkanRoti(daftarRoti, jumlahRoti);
    cout << "Pilih nomor roti yang ingin dihapus: ";
    cin >> pilihan;
    if (pilihan > 0 && pilihan <= jumlahRoti)
    {
        int index = pilihan - 1;
        for (int i = index; i < jumlahRoti - 1; i++)
        {
            daftarRoti[i] = daftarRoti[i + 1];
        }
        jumlahRoti--;
        cout << "Roti berhasil dihapus!\n";
    }
    else
    {
        cout << "Pilihan tidak valid.\n";
    }
}

int main()
{
    const int MAX_ROTI = 100; // Batas maksimum roti
    Roti daftarRoti[MAX_ROTI]; // Array buat simpan daftar roti
    int jumlahRoti = 0; // jumlah roti
    int pilihan; // buat menu pilihan

    do
    {
        cout << "Manajemen Toko Roti\n";
        cout << "1. Tambah Roti\n";
        cout << "2. Tampilkan Semua Roti\n";
        cout << "3. Update Roti\n";
        cout << "4. Hapus Roti\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahRoti(daftarRoti, jumlahRoti);
            break;
        case 2:
            tampilkanRoti(daftarRoti, jumlahRoti);
            break;
        case 3:
            updateRoti(daftarRoti, jumlahRoti);
            break;
        case 4:
            hapusRoti(daftarRoti, jumlahRoti);
            break;
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