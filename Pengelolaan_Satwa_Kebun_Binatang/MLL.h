#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

struct elmParent;
struct elmChild;

typedef elmParent *adrParent;
typedef elmChild *adrChild;

struct infoParent {
    int idJenis;
    char namaJenis[50];
};

struct infoChild {
    int idSatwa;
    char namaSatwa[50];
    int umur;
    float berat;
};

struct elmChild {
    infoChild info;
    adrChild next;
};

struct elmParent {
    infoParent info;
    adrParent next;
    adrChild firstChild;
};

struct ListParent {
    adrParent first;
};

// Inisialisasi list
void createList(ListParent &L);

// Alokasi
adrParent allocateParent(infoParent x);
adrChild allocateChild(infoChild x);

// Insert
void insertFirstParent(ListParent &L, adrParent P);
void insertLastChild(adrParent P, adrChild C);

// Searching
adrParent findParent(ListParent L, int idJenis);
adrChild findChild(adrParent P, int idSatwa);
adrChild findSatwa(ListParent L, int idSatwa);

// Delete
void deleteChild(adrParent P, int idSatwa, adrChild &C);
void deleteParent(ListParent &L, int idJenis, adrParent &P);

// Print
void showChild(adrParent P);
void showAll(ListParent L);

// Update
int countChild(adrParent P);
void updateChild(adrChild C, infoChild x);

#endif // MLL_H_INCLUDED
