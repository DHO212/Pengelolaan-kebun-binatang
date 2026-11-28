#include <iostream>
#include "MLL.h"

int main() {
    ListParent L;
    createList(L);

    int pilihan, idJenis, idSatwa;
    infoParent jenis;
    infoChild satwa;
    adrParent P;
    adrChild C;

    do {
        cout << "\n===== PENGELOLAAN DATA SATWA =====" << endl;
        cout << "1. Tambah jenis satwa" << endl;
        cout << "2. Tambah individu satwa" << endl;
        cout << "3. Cari jenis satwa" << endl;
        cout << "4. Cari individu satwa" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "ID jenis: ";
                cin >> jenis.idJenis;

                P = findParent(L, jenis.idJenis);

                if (P == nullptr) {
                    cout << "Nama jenis: ";
                    cin >> jenis.namaJenis;

                    P = allocateParent(jenis);
                    insertFirstParent(L, P);

                    cout << "Jenis berhasil ditambahkan." << endl;
                } else {
                    cout << "ID jenis sudah tersedia." << endl;
                }
                break;

            case 2:
                cout << "ID jenis: ";
                cin >> idJenis;

                P = findParent(L, idJenis);

                if (P != nullptr) {
                    cout << "ID satwa: ";
                    cin >> satwa.idSatwa;

                    C = findSatwa(L, satwa.idSatwa);

                    if (C == nullptr) {
                        cout << "Nama satwa: ";
                        cin >> satwa.namaSatwa;

                        cout << "Umur: ";
                        cin >> satwa.umur;

                        cout << "Berat: ";
                        cin >> satwa.berat;

                        C = allocateChild(satwa);
                        insertLastChild(P, C);

                        cout << "Satwa berhasil ditambahkan." << endl;
                    } else {
                        cout << "ID satwa sudah tersedia." << endl;
                    }
                } else {
                    cout << "Jenis satwa tidak ditemukan." << endl;
                }
                break;

            case 3:
                cout << "ID jenis: ";
                cin >> idJenis;

                P = findParent(L, idJenis);

                if (P != nullptr) {
                    cout << "ID jenis: " << P->info.idJenis << endl;
                    cout << "Nama jenis: " << P->info.namaJenis << endl;
                } else {
                    cout << "Jenis tidak ditemukan." << endl;
                }
                break;

            case 4:
                cout << "ID satwa: ";
                cin >> idSatwa;

                C = findSatwa(L, idSatwa);

                if (C != nullptr) {
                    cout << "ID satwa: " << C->info.idSatwa << endl;
                    cout << "Nama: " << C->info.namaSatwa << endl;
                    cout << "Umur: " << C->info.umur << endl;
                    cout << "Berat: " << C->info.berat << " kg" << endl;
                } else {
                    cout << "Satwa tidak ditemukan." << endl;
                }
                break;

            case 0:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 0);

    return 0;
}
