#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <stdexcept>
#include "staque1.h"
using namespace std;

// elementis konstruqtori
Elementi::Elementi(int mnish, unsigned long long idx) : mnishvneloba(mnish), indeqsi(idx), wina(nullptr), shemdgomi(nullptr) {}

// private metodebi
bool Staquee::contains(int mnishvneloba) const {
    Elementi* axlandeli = marcxenaBolo;
    while (axlandeli != nullptr) {
        if (axlandeli->mnishvneloba == mnishvneloba) {
            return true;
        }
        axlandeli = axlandeli->shemdgomi;
    }
    return false;
}

Elementi* Staquee::getBolosDamatebuliElementi() const {
    return bolosDamatebuli;
}

int Staquee::luwisTvla() const {
    int count{};
    Elementi* axlandeli = marcxenaBolo;
    while (axlandeli != nullptr) {
        if (axlandeli->mnishvneloba % 2 == 0) count++;
        axlandeli = axlandeli->shemdgomi;
    }
    return count;
}

int Staquee::kentisTvla() const {
    int count{};
    Elementi* axlandeli = marcxenaBolo;
    while (axlandeli != nullptr) {
        if (axlandeli->mnishvneloba % 2 != 0) count++;
        axlandeli = axlandeli->shemdgomi;
    }
    return count;
}

void Staquee::MarjvnidanLuwisWashla() {
    Elementi* axlandeli = marjvenaBolo;
    while (axlandeli != nullptr && axlandeli->mnishvneloba % 2 != 0) {
        axlandeli = axlandeli->wina;
    }
    if (axlandeli != nullptr) {
        washaleElemeneti(axlandeli);
    }
}

void Staquee::MarcxnidanKentisWashla() {
    Elementi* axlandeli = marcxenaBolo;
    while (axlandeli != nullptr && axlandeli->mnishvneloba % 2 == 0) {
        axlandeli = axlandeli->shemdgomi;
    }
    if (axlandeli != nullptr) {
        washaleElemeneti(axlandeli);
    }
}

void Staquee::LIFOwashla() {
    if (bolosDamatebuli == nullptr) return;  // gamoviyenot pointeri
    Elementi* toDelete = bolosDamatebuli;
    washaleElemeneti(toDelete);
}

void Staquee::washaleElemeneti(Elementi* elementi) {
    if (elementi == nullptr) return;

    if (elementi == bolosDamatebuli) {
        bolosDamatebuli = nullptr;
        // Vipovot bolos damatebuli elementi
        Elementi* axlandeli = marcxenaBolo;
        Elementi* newLast = nullptr;
        unsigned long long maxIndex = 0;

        while (axlandeli != nullptr) {
            if (axlandeli->indeqsi > maxIndex && axlandeli != elementi) {
                maxIndex = axlandeli->indeqsi;
                newLast = axlandeli;
            }
            axlandeli = axlandeli->shemdgomi;
        }
        bolosDamatebuli = newLast;
    }

    if (elementi->wina != nullptr) {
        elementi->wina->shemdgomi = elementi->shemdgomi;
    }
    else {
        marcxenaBolo = elementi->shemdgomi;
    }

    if (elementi->shemdgomi != nullptr) {
        elementi->shemdgomi->wina = elementi->wina;
    }
    else {
        marjvenaBolo = elementi->wina;
    }

    delete elementi;
    zoma--;
}

// konstruqtorebi da destruqtorebi

Staquee::Staquee() : marcxenaBolo(nullptr), marjvenaBolo(nullptr), bolosDamatebuli(nullptr), zoma(0), axaliIndeqsi(0) {}

Staquee::Staquee(const Staquee& other) : marcxenaBolo(nullptr), marjvenaBolo(nullptr), bolosDamatebuli(nullptr), zoma(0), axaliIndeqsi(other.axaliIndeqsi) {
    Elementi* axlandeli = other.marcxenaBolo;

    while (axlandeli != nullptr) {
        Elementi* axaliElementi = new Elementi(axlandeli->mnishvneloba, axlandeli->indeqsi);

        if (marcxenaBolo == nullptr) {
            marcxenaBolo = marjvenaBolo = axaliElementi;
        }
        else {
            marjvenaBolo->shemdgomi = axaliElementi;
            axaliElementi->wina = marjvenaBolo;
            marjvenaBolo = axaliElementi;
        }

        if (other.bolosDamatebuli != nullptr &&
            axlandeli->indeqsi == other.bolosDamatebuli->indeqsi) {
            bolosDamatebuli = axaliElementi;
        }

        zoma++;
        axlandeli = axlandeli->shemdgomi;
    }
}

void Staquee::swap(Staquee& other) noexcept {
    using std::swap;
    swap(marcxenaBolo, other.marcxenaBolo);
    swap(marjvenaBolo, other.marjvenaBolo);
    swap(bolosDamatebuli, other.bolosDamatebuli);
    swap(zoma, other.zoma);
    swap(axaliIndeqsi, other.axaliIndeqsi);
}

Staquee& Staquee::operator=(Staquee other) {
    swap(other);
    return *this;
}

Staquee::~Staquee() {
    clear();
}

// sajaro/public metodebi
void Staquee::clear() {
    while (marcxenaBolo != nullptr) {
        Elementi* temp = marcxenaBolo;
        marcxenaBolo = marcxenaBolo->shemdgomi;
        delete temp;
    }
    marjvenaBolo = nullptr;
    bolosDamatebuli = nullptr;
    zoma = 0;
    axaliIndeqsi = 0;
}

bool Staquee::isEmpty() const {
    return zoma == 0;
}

bool Staquee::add(int mnishvneloba) {
    if (contains(mnishvneloba)) {
        return false;
    }

    Elementi* axaliElementi = new Elementi(mnishvneloba, axaliIndeqsi++);
    bolosDamatebuli = axaliElementi;

    if (marcxenaBolo == nullptr) {
        marcxenaBolo = marjvenaBolo = axaliElementi;
    }
    else if (mnishvneloba % 2 == 0) {
        marjvenaBolo->shemdgomi = axaliElementi;
        axaliElementi->wina = marjvenaBolo;
        marjvenaBolo = axaliElementi;
    }
    else {
        axaliElementi->shemdgomi = marcxenaBolo;
        marcxenaBolo->wina = axaliElementi;
        marcxenaBolo = axaliElementi;
    }
    zoma++;
    return true;
}

int Staquee::getLastAdded() const {
    if (isEmpty() || bolosDamatebuli == nullptr) {
        throw runtime_error("Steki gvaqvs carieli da ver vighebt bolo elements!");
    }
    return bolosDamatebuli->mnishvneloba;
}

bool Staquee::search(int mnishvneloba) const {
    if (mnishvneloba % 2 == 0) {
        Elementi* axlandeli = marjvenaBolo;
        while (axlandeli != nullptr) {
            if (axlandeli->mnishvneloba % 2 != 0) break; // programa pirvel kentze gacherdeba
            if (axlandeli->mnishvneloba == mnishvneloba) {
                return true;
            }
            axlandeli = axlandeli->wina;
        }
    }
    else {
        Elementi* axlandeli = marcxenaBolo;
        while (axlandeli != nullptr) {
            if (axlandeli->mnishvneloba % 2 == 0) break; // programa pirvel luwze gacherdeba
            if (axlandeli->mnishvneloba == mnishvneloba) {
                return true;
            }
            axlandeli = axlandeli->shemdgomi;
        }
    }
    return false;
}

void Staquee::remove(int luwisTvlaParam, int kentisTvlaParam, int totalCount) {
    int positiveParams = (luwisTvlaParam > 0 ? 1 : 0) + (kentisTvlaParam > 0 ? 1 : 0) + (totalCount > 0 ? 1 : 0);

    if (positiveParams == 0) {
        cout << "Araperi washlila da yvela parametris mnishvneloba nulia" << endl;
        return;
    }

    if (positiveParams > 1) {
        cout << "Shecdoma, mxolod erti parametri unda iyos dadebiti" << endl;
        return;
    }

    if (luwisTvlaParam > 0) {
        int xelmisawvdLuwi = luwisTvla();
        if (xelmisawvdLuwi < luwisTvlaParam) {
            cout << "Xelmisawvdomia: " << xelmisawvdLuwi << ", Motxovnilia: " << luwisTvlaParam << endl;
            return;
        }
        for (int i{}; i < luwisTvlaParam; i++) {
            MarjvnidanLuwisWashla();
        }
        cout << "Waishala " << luwisTvlaParam << " marjvnidan luwi elementebi" << endl;
    }
    else if (kentisTvlaParam > 0) {
        int xelmisawvdKenti = kentisTvla();
        if (xelmisawvdKenti < kentisTvlaParam) {
            cout << "Xelmisawvdomia: " << xelmisawvdKenti << ", Motxovnilia: " << kentisTvlaParam << endl;
            return;
        }
        for (int i{}; i < kentisTvlaParam; i++) {
            MarcxnidanKentisWashla();  // FIXED: Changed from MarjvnidanKentisWashla
        }
        cout << "Waishala " << kentisTvlaParam << " marcnidan kenti elementebi" << endl;  // FIXED: Updated message
    }
    else if (totalCount > 0) {
        if (zoma < totalCount) {
            cout << "Xelmisawvdomia: " << zoma << ", Motxovnilia: " << totalCount << ". Ishleba yvela elemeneti." << endl;
            clear();
            return;
        }
        for (int i{}; i < totalCount; i++) {
            LIFOwashla();
        }
        cout << "Waishala " << totalCount << " am odenobis elementi LIFO-s principit" << endl;
    }
}

vector<int> Staquee::getValues(bool getEven) const {
    vector<int> shedegi;
    Elementi* axlandeli = marcxenaBolo;

    while (axlandeli != nullptr) {
        if ((getEven && axlandeli->mnishvneloba % 2 == 0) ||
            (!getEven && axlandeli->mnishvneloba % 2 != 0)) {
            shedegi.push_back(axlandeli->mnishvneloba);
        }
        axlandeli = axlandeli->shemdgomi;
    }
    return shedegi;
}

// operatorebi
ostream& operator<<(ostream& os, const Staquee& staque) {
    Elementi* axlandeli = staque.marcxenaBolo;
    os << "Staque [";
    while (axlandeli != nullptr) {
        os << axlandeli->mnishvneloba;
        if (axlandeli->shemdgomi != nullptr) os << ", ";
        axlandeli = axlandeli->shemdgomi;
    }
    os << "]";
    return os;
}

// getterebi
int Staquee::getZoma() const { return zoma; }
int Staquee::getEvenCount() const { return luwisTvla(); }
int Staquee::getOddCount() const { return kentisTvla(); }

int main() {
    default_random_engine dre(time(nullptr));
    uniform_int_distribution<int> dis(1, 100);

    // 50 elementit inicializacia
    Staquee staqueBase;
    cout << "50 random elementi [1-100]" << endl;

    int added = 0;
    while (added < 50) {
        if (staqueBase.add(dis(dre))) {
            added++;
        }
    }

    cout << "Zoma: " << staqueBase.getZoma() << endl;
    cout << "  Luwi: " << staqueBase.getEvenCount() << ", Kenti: " << staqueBase.getOddCount() << endl;

    // Bolos damatebuli elementi 
    try {
        cout << "Bolo damatebuli: " << staqueBase.getLastAdded() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Shecdoma: " << e.what() << endl;
    }

    // Dzebnis punqcia
    cout << "Dzebna:" << endl;
    vector<int> luwi = staqueBase.getValues(true);
    vector<int> kenti = staqueBase.getValues(false);

    if (!luwi.empty()) {
        int target = luwi[luwi.size() / 2];
        cout << "Luwi " << target << ": " << (staqueBase.search(target) ? "Vipovet" : "Ver vipovet") << endl;
    }
    if (!kenti.empty()) {
        int target = kenti[kenti.size() / 2];
        cout << "Kenti " << target << ": " << (staqueBase.search(target) ? "Vipovet" : "Ver vipovet") << endl;
    }
    cout << "999: " << (staqueBase.search(999) ? "Vipovet" : "Ver vipovet") << endl;

    // Copy konstruqtori
    Staquee staqueCopy(staqueBase);
    cout << "Tavdapirveli: " << staqueBase.getZoma() << ", kopia: " << staqueCopy.getZoma() << endl;
    staqueCopy.add(999);
    cout << "999-is damatebis shemdeg:" << endl;
    cout << "  Tavdapirveli: " << staqueBase.getZoma() << " (ucvleli)" << endl;
    cout << "  copy-s shemdeg: " << staqueCopy.getZoma() << " (shecvlili)" << endl;

    // Minichebis operatori
    Staquee minichebuliStaque;
    minichebuliStaque.add(1);
    minichebuliStaque.add(2);
    cout << "Zoma minichebamde: " << minichebuliStaque.getZoma() << endl;
    minichebuliStaque = staqueBase;
    cout << "Zoma minichebis shemdeg: " << minichebuliStaque.getZoma() << endl;

    // 6. getValues punqcia
    vector<int> luwmnishvnelobiani = staqueBase.getValues(true);
    vector<int> kentmnishvnelobiani = staqueBase.getValues(false);

    cout << "Luwi (" << luwmnishvnelobiani.size() << "): [";
    for (size_t i{}; i < min((size_t)10, luwmnishvnelobiani.size()); i++) {
        cout << luwmnishvnelobiani[i];
        if (i < min((size_t)10, luwmnishvnelobiani.size()) - 1) cout << ", ";
    }
    if (luwmnishvnelobiani.size() > 10) cout << "]" << endl;

    cout << "Kenti (" << kentmnishvnelobiani.size() << "): [";
    for (size_t i{}; i < min((size_t)10, kentmnishvnelobiani.size()); i++) {
        cout << kentmnishvnelobiani[i];
        if (i < min((size_t)10, kentmnishvnelobiani.size()) - 1) cout << ", ";
    }
    if (kentmnishvnelobiani.size() > 10) cout << "]" << endl;

    // Washlis punqciebi
    // 10 luwis da 10 kentis washla
    Staquee staque1 = staqueBase;
    cout << "Manamde zoma: " << staque1.getZoma() << ", Luwi=" << staque1.getEvenCount() << ", Kenti=" << staque1.getOddCount() << endl;
    staque1.remove(10, 0, 0);
    cout << "Shemdeg zoma: " << staque1.getZoma() << ", Luwi=" << staque1.getEvenCount() << endl;
    staque1.remove(0, 10, 0);
    cout << "Bolos zoma: " << staque1.getZoma() << ", Kenti=" << staque1.getOddCount() << endl;

    //20 kentis amoshla
    Staquee staque2 = staqueBase;
    cout << "Manamde zoma: " << staque2.getZoma() << ", Kenti=" << staque2.getOddCount() << endl;
    staque2.remove(0, 20, 0);
    cout << "Shemdeg zoma: " << staque2.getZoma() << ", Kenti=" << staque2.getOddCount() << endl;
    //30 elementis washla LIFO
    Staquee staque3 = staqueBase;
    cout << "Manamde zoma: " << staque3.getZoma() << endl;
    staque3.remove(0, 0, 30);
    cout << "Shemdeg zoma: " << staque3.getZoma() << endl;

    // Gamotanis operatori
    Staquee mcireStaque;
    mcireStaque.add(5);
    mcireStaque.add(10);
    mcireStaque.add(15);
    mcireStaque.add(20);
    cout << "Mcire staque: " << mcireStaque << endl;

    // Destruqtori
    Staquee tempStaque;
    tempStaque.add(1);
    tempStaque.add(2);
    tempStaque.add(3);
    cout << "Droebiti: " << tempStaque << endl;
    cout << "scope-dan gasvlisas destruqtori gamoidzaxeba da mexsiereba tavisupldeba" << endl;

    cout << "Cariel Staque-ze getLastAdded():" << endl;
    Staquee emptyStaque;
    try {
        emptyStaque.getLastAdded();
    }
    catch (const runtime_error& e) {
        cout << "Shecdomis dapiqsireba: " << e.what() << endl;
    }

    cout << "arasakmarisi elemenetebis washlis mcdeloba:" << endl;
    Staquee staqueTest;
    staqueTest.add(2);
    staqueTest.add(4);
    cout << "Staque (2 luwi): " << staqueTest << endl;
    staqueTest.remove(5, 0, 0);

    cout << "Mravali parametris gadacema:" << endl;
    staqueTest.remove(1, 1, 0);
}
