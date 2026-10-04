#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Class SistemAkademik (Berisi Method UI & Dashboard Web)
class PortalAkademik {
public:
    // 1. Non-Return Type Method tanpa Parameter (Header & Watermark)
    void tampilkanHeaderWeb() {
        cout << "==========================================================" << endl;
        cout << "              PORTAL AKADEMIK MAHASISWA                   " << endl;
        cout << "             [ S I A P Undip - KELOMPOK 36 ]                " << endl;
        cout << "==========================================================" << endl;
    }

    // 2. Non-Return Type Method berparameter (Tampilan Dashboard Hasil Web)
    void cetakDashboard(string nama, string nim, float ipk, int sksDiambil, int maxSks, string status) {
        cout << "\n==========================================================" << endl;
        cout << "                 DASHBOARD KRS MAHASISWA                  " << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << " Nama Mahasiswa  : " << nama << endl;
        cout << " NIM             : " << nim << endl;
        cout << " IPS Semester    : " << fixed << setprecision(2) << ipk << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << " Jatah Maks SKS  : " << maxSks << " SKS" << endl;
        cout << " SKS Rencana     : " << sksDiambil << " SKS" << endl;
        cout << " Status KRS      : [ " << status << " ]" << endl;
        cout << "==========================================================" << endl;
    }
};

// ------------------------------------------------------------------------

// 3. Return Type Function Tanpa Parameter (Navigasi Menu Web)
int pilihMenuWeb() {
    int pilihan;
    cout << "\n[NAVIGASI MENU]" << endl;
    cout << "1. Input Rencana Studi (KRS)" << endl;
    cout << "2. Keluar Portal" << endl;
    cout << "Pilih Menu (1-2): ";
    cin >> pilihan;
    return pilihan;
}

// 4. Return Type Function Berparameter (Logika penentuan Maks SKS dari IPK)
int hitungMaksSKS(float ipk) {
    // Pengkondisian Rentang IPK (Modul 1/2)
    if (ipk >= 3.00) {
        return 24;
    } else if (ipk >= 2.50) {
        return 22;
    } else if (ipk >= 2.00) {
        return 18;
    } else {
        return 15;
    }
}

// ------------------------------------------------------------------------

int main() {
    PortalAkademik siakad;
    int opsi;

    // Perulangan (Modul 3)
    do {
        siakad.tampilkanHeaderWeb(); // Method Non-Return tanpa parameter
        opsi = pilihMenuWeb();        // Function Return tanpa parameter

        if (opsi == 1) {
            string nama, nim;
            float ipk;
            int sksRencana;

            // Bersihkan buffer enter
            cin.ignore();

            cout << "\n[FORM INPUT DATA MAHASISWA]" << endl;
            cout << "▸ Nama Lengkap : ";
            getline(cin, nama);

            cout << "▸ NIM          : ";
            getline(cin, nim);

            cout << "▸ IPS Semester : ";
            cin >> ipk;

            cout << "▸ SKS Diambil  : ";
            cin >> sksRencana;

            // Validasi batas IPK
            if (ipk < 0.0 || ipk > 4.0) {
                cout << "\n[SYSTEM ERROR] Nilai IPK tidak valid ( 2.00 - 4.00 )!" << endl;
            } else {
                // Function Return berparameter
                int batasSks = hitungMaksSKS(ipk);
                string statusKRS;

                // Pengkondisian Status Validasi KRS
                if (sksRencana <= batasSks) {
                    statusKRS = "APPROVED (KRS Valid)";
                } else {
                    statusKRS = "REJECTED (SKS Melebihi Batas!)";
                }

                // Method Non-Return berparameter (Cetak UI Dashboard)
                siakad.cetakDashboard(nama, nim, ipk, sksRencana, batasSks, statusKRS);
            }

        } else if (opsi != 2) {
            cout << "\n[SYSTEM ERROR] Opsi menu tidak tersedia!" << endl;
        }

        cout << endl;
    } while (opsi != 2);

    cout << "Terima kasih telah menggunakan Portal SIAKAD." << endl;
    return 0;
}
