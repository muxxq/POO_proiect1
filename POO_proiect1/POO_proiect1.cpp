#include <iostream>
#include <vector>
#include <string>

using namespace std;
class PlatformaPetroliera {
private:
    string id;
    int capacitateExtractie;
    int stocCurent;
    double pretPerBaril;

public:
    PlatformaPetroliera(const string& id, int capacitate, double pret)
        : id(id), capacitateExtractie(capacitate), stocCurent(0), pretPerBaril(pret) {}

    void extragePetrol(int cantitate) {
        if (cantitate > capacitateExtractie) {
            cout << "Cantitate depaseste capacitatea zilnica. Se va extrage maximul posibil.\n";
            cantitate = capacitateExtractie;
        }
        stocCurent += cantitate;
        cout << "Petrol extras: " << cantitate << " barili\n";
    }

    void setPretPerBaril(double pret) { pretPerBaril = pret; }
    void setCapacitateExtractie(int capacitate) { capacitateExtractie = capacitate; }
    void setStocCurent(int stoc) { stocCurent = stoc; }

    int getStocCurent() const { return stocCurent; }

    void afiseazaInfo() const {
        cout << "Platforma " << id << ": capacitate zilnica " << capacitateExtractie
            << " barili, stoc curent " << stocCurent << " barili, pret/baril " << pretPerBaril << "$\n";
    }
};

class Transport {
private:
    int capacitateTransport;
    string destinatie;

public:
    Transport(int capacitate, const string& destinatie)
        : capacitateTransport(capacitate), destinatie(destinatie) {}

    void setCapacitateTransport(int capacitate) { capacitateTransport = capacitate; }
    void setDestinatie(const string& dest) { destinatie = dest; }

    void transporta(int cantitate) {
        if (cantitate > capacitateTransport) {
            cout << "Cantitatea depaseste capacitatea de transport. Se va transporta maximul posibil.\n";
            cantitate = capacitateTransport;
        }
        cout << "Transport de " << cantitate << " barili catre " << destinatie << "\n";
    }
};

class Rafinare {
private:
    int capacitateRafinare;
    int stocPetrolRafinat;

public:
    Rafinare(int capacitate)
        : capacitateRafinare(capacitate), stocPetrolRafinat(0) {}

    void setCapacitateRafinare(int capacitate) { capacitateRafinare = capacitate; }

    void rafineaza(int cantitate) {
        if (cantitate > capacitateRafinare) {
            cout << "Cantitatea depaseste capacitatea de rafinare. Se va rafina maximul posibil.\n";
            cantitate = capacitateRafinare;
        }
        stocPetrolRafinat += cantitate;
        cout << "Cantitate rafinata: " << cantitate << " barili\n";
    }

    int getStocPetrolRafinat() const { return stocPetrolRafinat; }
};

void afiseazaMeniu() {
    cout << "\n--- Meniu Principal ---\n";
    cout << "1. Afiseaza informatii despre platforma petroliera\n";
    cout << "2. Extrage petrol\n";
    cout << "3. Modifica pret per baril\n";
    cout << "4. Seteaza capacitatea de extractie\n";
    cout << "5. Seteaza stocul curent\n";
    cout << "6. Transporta petrol\n";
    cout << "7. Rafineaza petrol\n";
    cout << "8. Seteaza capacitatea de rafinare\n";
    cout << "0. Iesire\n";
}

int main() {
    PlatformaPetroliera platforma("P001", 1000, 50.0);
    Transport transport(300, "Rafinaria Nord");
    Rafinare rafinare(200);

    int optiune = -1;
    while (optiune != 0) {
        afiseazaMeniu();
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
        case 1:
            platforma.afiseazaInfo();
            break;
        case 2: {
            int cantitate;
            cout << "Introduceti cantitatea de petrol de extras: ";
            cin >> cantitate;
            platforma.extragePetrol(cantitate);
            break;
        }
        case 3: {
            double pret;
            cout << "Introduceti noul pret per baril: ";
            cin >> pret;
            platforma.setPretPerBaril(pret);
            cout << "Pretul a fost actualizat.\n";
            break;
        }
        case 4: {
            int capacitate;
            cout << "Introduceti noua capacitate de extractie: ";
            cin >> capacitate;
            platforma.setCapacitateExtractie(capacitate);
            cout << "Capacitatea de extractie a fost actualizata.\n";
            break;
        }
        case 5: {
            int stoc;
            cout << "Introduceti noul stoc curent: ";
            cin >> stoc;
            platforma.setStocCurent(stoc);
            cout << "Stocul curent a fost actualizat.\n";
            break;
        }
        case 6: {
            int cantitate;
            cout << "Introduceti cantitatea de petrol de transportat: ";
            cin >> cantitate;
            transport.transporta(cantitate);
            break;
        }
        case 7: {
            int cantitate;
            cout << "Introduceti cantitatea de petrol de rafinat: ";
            cin >> cantitate;
            rafinare.rafineaza(cantitate);
            break;
        }
        case 8: {
            int capacitate;
            cout << "Introduceti noua capacitate de rafinare: ";
            cin >> capacitate;
            rafinare.setCapacitateRafinare(capacitate);
            cout << "Capacitatea de rafinare a fost actualizata.\n";
            break;
        }
        case 0:
            cout << "Iesire din program.\n";
            break;
        default:
            cout << "Optiune invalida! Incercati din nou.\n";
        }
    }

    return 0;
}
