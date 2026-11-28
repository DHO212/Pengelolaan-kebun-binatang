#include "MLL.h"

void createList(ListParent &L) {
    L.first = nullptr;
}

adrParent allocateParent(infoParent x) {
    adrParent P = new elmParent;

    P->info = x;
    P->next = nullptr;
    P->firstChild = nullptr;

    return P;
}

adrChild allocateChild(infoChild x) {
    adrChild C = new elmChild;

    C->info = x;
    C->next = nullptr;

    return C;
}

void insertFirstParent(ListParent &L, adrParent P) {
    P->next = L.first;
    L.first = P;
}

void insertLastChild(adrParent P, adrChild C) {
    if (P != nullptr && C != nullptr) {
        if (P->firstChild == nullptr) {
            P->firstChild = C;
        } else {
            adrChild Q = P->firstChild;

            while (Q->next != nullptr) {
                Q = Q->next;
            }

            Q->next = C;
        }
    }
}

adrParent findParent(ListParent L, int idJenis) {
    adrParent P = L.first;

    while (P != nullptr &&
           P->info.idJenis != idJenis) {
        P = P->next;
    }

    return P;
}

adrChild findChild(adrParent P, int idSatwa) {
    adrChild C = nullptr;

    if (P != nullptr) {
        C = P->firstChild;

        while (C != nullptr &&
               C->info.idSatwa != idSatwa) {
            C = C->next;
        }
    }

    return C;
}

adrChild findSatwa(ListParent L, int idSatwa) {
    adrParent P = L.first;
    adrChild C = nullptr;

    while (P != nullptr && C == nullptr) {
        C = findChild(P, idSatwa);
        P = P->next;
    }

    return C;
}

void showChild(adrParent P) {
    if (P != nullptr) {
        adrChild C = P->firstChild;

        if (C == nullptr) {
            cout << "Tidak ada individu satwa." << endl;
        }

        while (C != nullptr) {
            cout << "ID Satwa : " << C->info.idSatwa << endl;
            cout << "Nama     : " << C->info.namaSatwa << endl;
            cout << "Umur     : " << C->info.umur << endl;
            cout << "Berat    : " << C->info.berat << " kg" << endl;
            cout << "--------------------" << endl;

            C = C->next;
        }
    }
}

void showAll(ListParent L) {
    adrParent P = L.first;

    if (P == nullptr) {
        cout << "List kosong." << endl;
    }

    while (P != nullptr) {
        cout << "\n====================" << endl;
        cout << "ID Jenis : " << P->info.idJenis << endl;
        cout << "Jenis    : " << P->info.namaJenis << endl;
        cout << "Jumlah   : " << countChild(P) << endl;
        cout << "====================" << endl;

        showChild(P);

        P = P->next;
    }
}

int countChild(adrParent P) {
    int jumlah = 0;

    if (P != nullptr) {
        adrChild C = P->firstChild;

        while (C != nullptr) {
            jumlah++;
            C = C->next;
        }
    }

    return jumlah;
}

// operasi delete dan update nanti sekalian BST
