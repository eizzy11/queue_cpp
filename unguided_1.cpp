//FAUZI IRFAN SYAPUTRA
//21103071
//SI05C

#include <iostream>
#include <stdlib.h>

using namespace std;

int maks_antrian = 100;
int pilihan;
bool keluar = false;
char ya_tidak;
string data_masuk;

void menu_keluar () {
    cout << "Keluar (y/t) ?";
    cin >> ya_tidak;
    if (ya_tidak == 'y' || ya_tidak == 'Y') {
        cout << "Sampai Jumpa Kembali" << endl;
        keluar = true;
    } else {
        system ("clear");
    }
}

struct antrian {
    int depan;
    int belakang;
    string *tempat = new string[maks_antrian];
} wahana;

void nilai_awal () {
    wahana.depan = -1;
    wahana.belakang = -1;
}

bool antrian_penuh () {
    if (wahana.belakang == maks_antrian - 1) {
        return true;
    } else {
        return false;
    }
}

bool antrian_kosong () {
    if (wahana.depan == -1 && wahana.belakang == -1) {
        return true;
    } else {
        return false;
    }
}

void enqueue_antrian (string dataMasuk) {
    if (antrian_kosong () == true) {
        wahana.depan = 0;
        wahana.belakang = 0;
        wahana.tempat[wahana.belakang] = dataMasuk;
    } else if (antrian_penuh () == false) {
        wahana.belakang++;
        wahana.tempat[wahana.belakang] = dataMasuk;
        cout << "Data sudah masuk" << endl;
    } else {
        cout << "Antrian sudah penuh" << endl;
    }
}


void dequeue_antrian_tong () {
    if (antrian_kosong () == false) {
        for (int x = wahana.depan; x <= wahana.belakang; x++) {
            wahana.tempat[x] = wahana.tempat[x + 10]; 
        }
        wahana.belakang--;
        cout << "Data sudah terhapus" << endl;
    } else {
        cout << "Tidak ada data pada antrian" << endl;
    }
}

void dequeue_antrian_rumah () {
    if (antrian_kosong () == false) {
        for (int x = wahana.depan; x <= wahana.belakang; x++) {
            wahana.tempat[x] = wahana.tempat[x + 2]; 
        }
        wahana.belakang--;
        cout << "Data sudah terhapus" << endl;
    } else {
        cout << "Tidak ada data pada antrian" << endl;
    }
}

void dequeue_antrian_bianglala () {
    if (antrian_kosong () == false) {
        for (int x = wahana.depan; x <= wahana.belakang; x++) {
            wahana.tempat[x] = wahana.tempat[x + 15]; 
        }
        wahana.belakang--;
        cout << "Data sudah terhapus" << endl;
    } else {
        cout << "Tidak ada data pada antrian" << endl;
    }
}

void dequeue_antrian_ombak () {
    if (antrian_kosong () == false) {
        for (int x = wahana.depan; x <= wahana.belakang; x++) {
            wahana.tempat[x] = wahana.tempat[x + 5]; 
        }
        wahana.belakang--;
        cout << "Data sudah terhapus" << endl;
    } else {
        cout << "Tidak ada data pada antrian" << endl;
    }
}

void tampil_data () {
    if (antrian_kosong () == false) {
        for (int z = wahana.depan; z <= wahana.belakang; z++) {
            cout << wahana.tempat[z] << " ";
        }
        cout << endl;
    } else {
        cout << "Tidak ada data pada antrian" << endl;
    }
}

void atur_antri () {
    cout << "Masukkan jumlah antrian pada wahana : ";
    cin >> maks_antrian;
    cout << "Pengaturan selesai" << endl;
    cout << "Antrian pada wahana " << maks_antrian << " " << endl;
}

void menu_tong () {
    do {
        cout << "1. Masukkan data dalam antrian" << endl;
        cout << "2. Hapus data pada antrian" << endl;
        cout << "3. Tampil data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data pada antrian : ";
                cin >> data_masuk;
                enqueue_antrian (data_masuk);
                menu_keluar ();
                break;

            case 2:
                dequeue_antrian_tong ();
                menu_keluar ();
                break;

            case 3:
                tampil_data ();
                menu_keluar ();
                break;

            case 4:
                menu_keluar ();
                break;

            default:
                cout << "Pilihan tidak ada" << endl;
                menu_keluar ();
                break;
        }
    } while (keluar == false);
} 

void menu_rumah () {
    do {
        cout << "1. Masukkan data dalam antrian" << endl;
        cout << "2. Hapus data pada antrian" << endl;
        cout << "3. Tampil data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data pada antrian : ";
                cin >> data_masuk;
                enqueue_antrian (data_masuk);
                menu_keluar ();
                break;

            case 2:
                dequeue_antrian_rumah ();
                menu_keluar ();
                break;

            case 3:
                tampil_data ();
                menu_keluar ();
                break;

            case 4:
                menu_keluar ();
                break;

            default:
                cout << "Pilihan tidak ada" << endl;
                menu_keluar ();
                break;
        }
    } while (keluar == false);
}

void menu_bianglala () {
    do {
        cout << "1. Masukkan data dalam antrian" << endl;
        cout << "2. Hapus data pada antrian" << endl;
        cout << "3. Tampil data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data pada antrian : ";
                cin >> data_masuk;
                enqueue_antrian (data_masuk);
                menu_keluar ();
                break;

            case 2:
                dequeue_antrian_bianglala ();
                menu_keluar ();
                break;

            case 3:
                tampil_data ();
                menu_keluar ();
                break;

            case 4:
                menu_keluar ();
                break;

            default:
                cout << "Pilihan tidak ada" << endl;
                menu_keluar ();
                break;
        }
    } while (keluar == false);
}

void menu_ombak () {
    do {
        cout << "1. Masukkan data dalam antrian" << endl;
        cout << "2. Hapus data pada antrian" << endl;
        cout << "3. Tampil data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data pada antrian : ";
                cin >> data_masuk;
                enqueue_antrian (data_masuk);
                menu_keluar ();
                break;

            case 2:
                dequeue_antrian_ombak ();
                menu_keluar ();
                break;

            case 3:
                tampil_data ();
                menu_keluar ();
                break;

            case 4:
                menu_keluar ();
                break;

            default:
                cout << "Pilihan tidak ada" << endl;
                menu_keluar ();
                break;
        }
    } while (keluar == false);
}

int main ()
{
    nilai_awal ();

    do {
        cout << "Selamat Datang di Wahana" << endl;
        cout << "1. Tong Setan" << endl;
        cout << "2. Rumah Hantu" << endl;
        cout << "3. Bianglala" << endl;
        cout << "4. Ombak Banyu" << endl;
        cout << "5. Keluar" << endl;
        cout << "Silahkan pilih menu (1-5) : ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "Wahana Tong Setan" << endl;
                atur_antri ();
                menu_tong ();
                break;
            
            case 2:
                cout << "Wahana Rumah Hantu" << endl;
                atur_antri ();
                menu_rumah ();
                break;

            case 3:
                cout << "Wahana Bianglala" << endl;
                atur_antri ();
                menu_bianglala ();
                break;

            case 4:
                cout << "Wahana Ombak Banyu" << endl;
                atur_antri ();
                menu_ombak ();
                break;

            case 5:
                menu_keluar ();
                break;

            default:
                cout << "Pilihan tidak tersedia" << endl;
                menu_keluar ();
                break;
        }

    } while (keluar == false);

    return 0;
}
