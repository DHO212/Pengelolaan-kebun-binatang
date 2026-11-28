#include "MLL.h"

// I.S. : List L belum terinisialisasi.
// F.S. : List L kosong.
void createList(ListParent &L) {
    L.first = nullptr;
}

// I.S. : Data jenis satwa x tersedia.
// F.S. : Mengembalikan address parent baru.
adrParent allocateParent(infoParent x) {
    adrParent P = new elmParent;

    P->info = x;
    P->next = nullptr;
    P->firstChild = nullptr;

    return P;
}

// I.S. : Data individu satwa x tersedia.
// F.S. : Mengembalikan address child baru.
adrChild allocateChild(infoChild x) {
    adrChild C = new elmChild;

    C->info = x;
    C->next = nullptr;

    return C;
}

// I.S. : List L mungkin kosong, P sudah dialokasikan.
// F.S. : P menjadi elemen pertama list parent.
void insertFirstParent(ListParent &L, adrParent P) {
    P->next = L.first;
    L.first = P;
}

// I.S. : P merupakan parent valid, C sudah dialokasikan.
// F.S. : C menjadi elemen terakhir list child milik P.
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

// I.S. : List L mungkin kosong.
// F.S. : Mengembalikan address parent dengan ID yang
//        sesuai atau nullptr jika tidak ditemukan.
adrParent findParent(ListParent L, int idJenis) {
    adrParent P = L.first;

    while (P != nullptr &&
           P->info.idJenis != idJenis) {
        P = P->next;
    }

    return P;
}

// I.S. : P merupakan parent atau nullptr.
// F.S. : Mengembalikan address child dengan ID yang
//        sesuai atau nullptr jika tidak ditemukan.
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

// I.S. : List L mungkin kosong.
// F.S. : Mengembalikan address satwa dari seluruh
//        parent atau nullptr jika tidak ditemukan.
adrChild findSatwa(ListParent L, int idSatwa) {
    adrParent P = L.first;
    adrChild C = nullptr;

    while (P != nullptr && C == nullptr) {
        C = findChild(P, idSatwa);
        P = P->next;
    }

    return C;
}
