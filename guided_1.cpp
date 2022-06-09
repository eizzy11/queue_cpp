#include <iostream>

using namespace std;

const int maksimal_antrian = 17;
bool keluar = false;
char ya_tidak;
int pilihan;
string data_masuk;

struct antrian {
    int depan;
    int belakang;
    string nama [maksimal_antrian];
} mahasiswa;

void nilai_awal () {
    mahasiswa.depan = -1;
    mahasiswa.belakang = -1;
}

bool antrian_penuh () {
    if (mahasiswa.belakang == maksimal_antrian - 1) {
        return true;
    } else {
        return false;
    }
}

bool antrian_kosong () {
    if (mahasiswa.depan == -1 && mahasiswa.belakang == -1) {
        return true;
    } else {
        return false;
    }
}

void enqueue_antrian (string dataMasukkan) {
    if (antrian_kosong () == true) {
        mahasiswa.depan = 0;
        mahasiswa.belakang = 0;
        mahasiswa.nama[mahasiswa.belakang] = dataMasukkan;
    } else if (antrian_penuh () == false) {
        mahasiswa.belakang++;
        mahasiswa.nama[mahasiswa.belakang] = dataMasukkan;
    } else {
        cout << "Antrian sudah penuh" << endl;
    }
}

void dequeue_antrian () {
    if (antrian_kosong () == false) {
        for (int x = mahasiswa.depan; x <= mahasiswa.belakang; x++) {
            mahasiswa.nama[x] = mahasiswa.nama[x + 1];
        }
        mahasiswa.belakang--;
        cout << "Satu data sudah terhapus" << endl;
    } else {
        cout << "Tidak ada data pada antrian" << endl;
    }
}

void tampil_data () {
    if (antrian_kosong () == false) {
        for (int z = mahasiswa.depan; z <= mahasiswa.belakang; z++) {
            cout << mahasiswa.nama[z] << " ";
        }
        cout << endl;
    } else {
        cout << "Tidak ada data pada antrian" << endl;
    }
}

int main () {
    nilai_awal ();

    do {
        cout << "\t" << "Queue Apps" << endl;
        cout << "1. Masukkan data kedalam queue" << endl;
        cout << "2. Hapus data dari queue" << endl;
        cout << "3. Tampilkan data queue" << endl;
        cout << "4. Keluar" << endl;
        cout << "Silahkan pilih (1-4) : ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "Silahkan masukkan data : ";
                cin >> data_masuk;
                enqueue_antrian (data_masuk);
                cout << "Keluar (y/t) ? ";
                cin >> ya_tidak;
                if (ya_tidak == 'y' || ya_tidak == 'Y') {
                    cout << "Jumpa kembali" << endl;
                    keluar = true;
                } else {
                    system ("clear");
                }
                break;
            
            case 2:
                dequeue_antrian ();
                cout<<"Keluar (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Terima kasih"<<endl;
                    keluar = true;
                }else{
                    system("clear");
                }
                break;

            case 3:
                tampil_data();
                cout<<"Keluar (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Terima kasih"<<endl;
                    keluar = true;
                }else{
                    system("clear");
                }
                break;

            case 4:
                cout<<"Yakin ingin keluar (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Terima kasih"<<endl;
                    keluar = true;
                }
                system("clear");
                break;
            
            default:
                cout<<"Pilihan tidak tersedia..."<<endl;
                cout<<"Keluar (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Terima kasih"<<endl;
                    keluar = true;
                }else{
                    system("clear");
                }

                break;
        }
    } while (keluar == false);
    return 0;
}