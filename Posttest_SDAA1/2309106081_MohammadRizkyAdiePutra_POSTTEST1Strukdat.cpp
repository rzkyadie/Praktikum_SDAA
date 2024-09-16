// posttest 1 struktur data
// mohammad rizky adie putra
// 2309106081
#include <iostream>
using namespace std;

int pindahkanPiringan(int jumlahPiringan, string menaraAsal, string menaraTujuan, string menaraSementara) {
    if (jumlahPiringan == 1) {
        cout << "Pindahkan piringan dari " << menaraAsal << " ke " << menaraTujuan << endl;
        return 1;
    }
    int langkah1 = pindahkanPiringan(jumlahPiringan - 1, menaraAsal, menaraSementara, menaraTujuan);
    cout << "Pindahkan piringan dari " << menaraAsal << " ke " << menaraTujuan << endl;
    int langkah2 = 1;
    int langkah3 = pindahkanPiringan(jumlahPiringan - 1, menaraSementara, menaraTujuan, menaraAsal);
    return langkah1 + langkah2 + langkah3;
}
int main() {
    int jumlahPiringan = 3;
    int totalLangkah = pindahkanPiringan(jumlahPiringan, "Menara Asal", "Menara Tujuan", "Menara Sementara");
    cout << "Jumlah langkah yang diperlukan: " << totalLangkah << endl;

    return 0;
}