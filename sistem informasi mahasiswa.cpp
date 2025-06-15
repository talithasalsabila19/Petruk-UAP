#include <iostream>
#include <vector>   
#include <cstring> // ini sbnrnya gpke jg masi bisa gt loh codingannya, kek nya,  tpi gktau basing lorang
using namespace std;

struct MataKuliah {
    char nama[50];
    int sks;
int prioritas;

MataKuliah(const char* n = "", int s =0, int p = 0){
strcpy(nama, n, sizeof(nama) - 1);
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
    char n[50];
    int sks;

    void matakuliah() {
        cout << "Masukan matakuliah: ";
        cin.getline(n, 50);
        cout << "Masukan SKS: ";
        cin >> sks;
        cin.ignore();

        cout << "\n--- Data Matkul ---\n";
        cout << "Mata kuliah : " << n << endl;
        cout << "Jumlah SKS : " << sks << endl;
    }

    void menu() {
        int pilih;
        vector<data> daftarMhs;            
        vector<string> daftarMatkul;        
        vector<int> daftarSKS;  
        //pake vector biar gampang nyimpen data banyak. ya gaksih. gak ya
        
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
                cin.getline(matkul, 50);

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

            } }else if (pilih == 4) {
                rekomendasiMatkul();
            }}else if (pilih == 5){
                    cout << "Terimakasih.\n";
                break;
            } }else {
                cout << "Error: Pilihan tidak valid." << endl;
        }
    }
};
void rekomendasiMatkul(){
int n = daftarMatkul.size():
int kapasitasSKS;
cout << "Masukkan batas maksimal SKS: ";
cin >> kapasitasSKS;

vector<vector<int>>dp(n+1,vector<int>(kapasitasSKS+1,00));
for (int i = 1; i<= n; ++i){
int w = daftarMatkul[i-1]->sks;
int v = daftarMatkul[i-1]->prioritas;
for (int j = 0; j<=kapasitasSKS;++j){
if(w<=j)
dp[i][j]=max(dp[i-1[j],dp[i-1[j-w]+v);
else dp[i][j] = dp[i-1][j];
}
}
cout << "\n >> total prioritas maksimal: " << dp[n] [kapasitasSKS]<< endl;
cout << " >> MAtkul yang direkomendasikan:\n";

int j = kapasitasSKS;
for (int i = n; i>0 && j > 0; --i){
if (dp[i][j]!= dp [i-1][j]){
MataKuliah* mk = daftarMatkul[i-1];
cout << "- "<<mk->nama<<" (SKS: " << mk->sks<<",Prioritas: " << mk->prioritas << ")\n";
j-=mk->sks;
}
}
}
};

int main() {
    Matkul app;
    app.menu();

    return 0;
}
