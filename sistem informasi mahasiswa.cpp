#include <iostream>
#include <vector>   
#include <cstring> // ini sbnrnya gpke jg masi bisa gt loh codingannya, kek nya,  tpi gktau basing lorang
using namespace std;

struct MataKuliah {
    char nama[50];
    int sks;
    int prioritas;

MataKuliah(const char* n = "", int s = 0, int p = 0){
    strncpy(nama, n, sizeof(nama) - 1);
nama[sizeof(nama)-1]='\0';
sks = s;
prioritas = p;
}
};
struct Mahasiswa{
char nama[50];
string npm;
};
class Matkul {
public:
    vector<Mahasiswa*> daftarMhs;
    vector<Mahasiswa*> daftarMAtkul;

       ~Matkul() {
        for (auto mhs : daftarMhs) delete mhs;
        for (auto mk : daftarMatkul) delete mk;
    }

    void menu() {
        int pilih;
        while (true) {
            cout << "\n=== Sistem Informasi Mahasiswa ===" << endl;
            cout << "1. Daftar Mahasigma" << endl;
            cout << "2. Tambahkan mata kuliah" << endl;
            cout << "3. Tampilkan semua data" << endl;
            cout << "4. Rekomendasi Mata KUliah"<<endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih : ";
            cin >> pilih;
            cin.ignore();

            if (pilih == 1) {
                Mahasiswa* mhs = new Mahasiswa;
                cout << "Masukan nama : ";
                cin.getline(mhs->nama, 50);

                cout << "Masukan npm : ";
                cin >> mhs->npm;
                cin.ignore();

                daftarMhs.push_back(mhs);  //masukin 1 data mhs yg baru ke dlm daftarMhs

               

            } else if (pilih == 2) {
                char nama[50];
                int sks, prioritas;

                cout << "Masukan matakuliah: ";
                cin.getline(nama, 50);

                cout << "Masukan SKS: ";
                cin >> sks;
                cout << "MAsukkan Prioritas(1-10): ";
                cin >> prioritas;
                cin.ignore();

                daftarMatkul.push_back(new MataKuliah(nama, sks, prioritas));  
                
                // push_back tu buat nambah data ke belakang vector

              

            } else if (pilih == 3) {
                cout << "\n--- Semua Data Mahasiswa ---" << endl;
                for (int i = 0; i < daftarMhs.size(); ++i) { // nampilin dta dri awal smpe akhir, klo gapke size() kita gak tau harus ulang berapa kali, karena jumlah datanya bisa berubah-ubah.
                    cout << i + 1 << ". Nama: " << daftarMhs[i]->nama // biar penomorannya dari 1 bukan 0
                         << ", NPM: " << daftarMhs[i]->npm << endl;
                }

                cout << "\n--- Daftar MAta KUliah ---" << endl;
                for (int i = 0; i < daftarMatkul.size(); ++i) { //sama
                    cout << i + 1 << ". " << daftarMatkul[i]->nama  // sama
                         << " - SKS: " << daftarSKS[i]->sks
                        << " - Prioritas: " << daftarMatkul[i]->prioritas << endl;
                }

            } else if (pilih == 4) {
                rekomendasiMatkul();

            } else if (pilih == 5) {
                mergeSortMatkul(0, daftarMatkul.size() - 1);
                cout << "Mata kuliah berhasil diurutkan berdasarkan prioritas tertinggi.\n";

            } else if (pilih == 6) {
                cout << "Terima kasih.\n";
                break;

            } else {
                cout << "Pilihan tidak valid.\n";
        }
    }
}
void rekomendasiMatkul(){
int n = daftarMatkul.size():
int kapasitasSKS;
cout << "Masukkan batas maksimal SKS: ";
cin >> kapasitasSKS;

vector<vector<int>>dp(n+1,vector<int>(kapasitasSKS + 1, 0));
for (int i = 1; i<= n; ++i){
int w = daftarMatkul[i-1]->sks;
int v = daftarMatkul[i-1]->prioritas;
for (int j = 0; j<=kapasitasSKS;++j){
if(w<=j)
dp[i][j] = max(dp[i-1[j],dp[i-1[j-w]+v);
else 
    dp[i][j] = dp[i-1][j];
}
}
cout << "\n >> total prioritas maksimal: " << dp[n] [kapasitasSKS]<< endl;
cout << " >> MAtkul yang direkomendasikan:\n";

int j = kapasitasSKS;
for (int i = n; i>0 && j > 0; --i){
if (dp[i][j]!= dp [i-1][j]){
MataKuliah* mk = daftarMatkul[i-1];
cout << "- "<<mk->nama<<" (SKS: " << mk->sks
    <<",Prioritas: " << mk->prioritas << ")\n";
j-=mk->sks;
}
}
}

    // === Merge Sort: Divide & Conquer berdasarkan PRIORITAS tertinggi ===
    void mergeSortMatkul(int left, int right) {
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergeSortMatkul(left, mid);
        mergeSortMatkul(mid + 1, right);
        merge(left, mid, right);
    }

    void merge(int left, int mid, int right) {
        vector<MataKuliah*> L(daftarMatkul.begin() + left, daftarMatkul.begin() + mid + 1);
        vector<MataKuliah*> R(daftarMatkul.begin() + mid + 1, daftarMatkul.begin() + right + 1);

        int i = 0, j = 0, k = left;
        while (i < L.size() && j < R.size()) {
            if (L[i]->prioritas >= R[j]->prioritas)
                daftarMatkul[k++] = L[i++];
            else
                daftarMatkul[k++] = R[j++];
        }

        while (i < L.size()) daftarMatkul[k++] = L[i++];
        while (j < R.size()) daftarMatkul[k++] = R[j++];
    }
};

int main() {
    Matkul app;
    app.menu();

    return 0;
}
