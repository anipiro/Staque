#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

struct Elementi {
    int mnishvneloba;
    unsigned long long indeqsi;
    Elementi* wina;
    Elementi* shemdgomi;
    Elementi(int mnish, unsigned long long idx);
};

class Staquee {
private:
    Elementi* marcxenaBolo;
    Elementi* marjvenaBolo;
    Elementi* bolosDamatebuli;
    int zoma;
    unsigned long long axaliIndeqsi;

    bool contains(int mnishvneloba) const;
    Elementi* getBolosDamatebuliElementi() const;
    int luwisTvla() const;
    int kentisTvla() const;
    void MarjvnidanLuwisWashla();
    void MarcxnidanKentisWashla();
    void LIFOwashla();
    void washaleElemeneti(Elementi* elementi);

public:
    Staquee();
    Staquee(const Staquee& other);
    Staquee& operator=(Staquee other);
    ~Staquee();

    void swap(Staquee& other) noexcept;
    void clear();
    bool add(int mnishvneloba);
    int getLastAdded() const;
    bool isEmpty() const;
    bool search(int mnishvneloba) const;
    void remove(int luwisTvlaParam = 0, int kentisTvlaParam = 0, int totalCount = 0);
    vector<int> getValues(bool getEven = true) const;

    friend ostream& operator<<(ostream& os, const Staquee& staquee);
    int getZoma() const;
    int getEvenCount() const;
    int getOddCount() const;
};
