// POO_proiect1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
//class PlatformaPetroliera {
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
