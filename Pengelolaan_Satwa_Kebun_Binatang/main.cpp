#include "MLL.h"

int main() {
    ListParent L;
    createList(L);

    infoParent jenis;
    infoChild satwa;

    adrParent P;
    adrChild C;

    int pilihan, idJenis, idSatwa;

    while (pilihan != 0) {
        cout << "\n===== PENGELOLAAN DATA SATWA =====" << endl;
        cout << "1. Tambah jenis satwa" << endl;
        cout << "2. Tambah individu satwa" << endl;
        cout << "3. Cari jenis satwa" << endl;
        cout << "4. Cari individu berdasarkan jenis" << endl;
        cout << "5. Cari individu berdasarkan ID satwa" << endl;
        cout << "6. Tampilkan individu berdasarkan jenis" << endl;
        cout << "7. Tampilkan seluruh data" << endl;
        cout << "8. Hitung jumlah individu berdasarkan jenis" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
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

        } else if (pilihan == 2) {
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

                    cout << "Individu berhasil ditambahkan." << endl;
                } else {
                    cout << "ID satwa sudah tersedia." << endl;
                }
            } else {
                cout << "Jenis tidak ditemukan." << endl;
            }

        } else if (pilihan == 3) {
            cout << "ID jenis: ";
            cin >> idJenis;

            P = findParent(L, idJenis);

            if (P != nullptr) {
                cout << "ID Jenis : " << P->info.idJenis << endl;
                cout << "Nama     : " << P->info.namaJenis << endl;
            } else {
                cout << "Jenis tidak ditemukan." << endl;
            }

        } else if (pilihan == 4) {
            cout << "ID jenis: ";
            cin >> idJenis;

            P = findParent(L, idJenis);

            if (P != nullptr) {
                cout << "ID satwa: ";
                cin >> idSatwa;

                C = findChild(P, idSatwa);

                if (C != nullptr) {
                    cout << "ID Satwa : " << C->info.idSatwa << endl;
                    cout << "Nama     : " << C->info.namaSatwa << endl;
                    cout << "Umur     : " << C->info.umur << endl;
                    cout << "Berat    : " << C->info.berat << " kg" << endl;
                } else {
                    cout << "Individu tidak ditemukan." << endl;
                }
            } else {
                cout << "Jenis tidak ditemukan." << endl;
            }

        } else if (pilihan == 5) {
            cout << "ID satwa: ";
            cin >> idSatwa;

            C = findSatwa(L, idSatwa);

            if (C != nullptr) {
                cout << "ID Satwa : " << C->info.idSatwa << endl;
                cout << "Nama     : " << C->info.namaSatwa << endl;
                cout << "Umur     : " << C->info.umur << endl;
                cout << "Berat    : " << C->info.berat << " kg" << endl;
            } else {
                cout << "Individu tidak ditemukan." << endl;
            }

        } else if (pilihan == 6) {
            cout << "ID jenis: ";
            cin >> idJenis;

            P = findParent(L, idJenis);

            if (P != nullptr) {
                cout << "Jenis: " << P->info.namaJenis << endl;
                showChild(P);
            } else {
                cout << "Jenis tidak ditemukan." << endl;
            }

        } else if (pilihan == 7) {
            showAll(L);

        } else if (pilihan == 8) {
            cout << "ID jenis: ";
            cin >> idJenis;

            P = findParent(L, idJenis);

            if (P != nullptr) {
                cout << "Jenis  : " << P->info.namaJenis << endl;
                cout << "Jumlah : " << countChild(P) << endl;
            } else {
                cout << "Jenis tidak ditemukan." << endl;
            }

        } else if (pilihan == 0) {
            cout << "Program selesai." << endl;

        } else {
            cout << "Pilihan tidak valid." << endl;
        }

    }

    return 0;
}
