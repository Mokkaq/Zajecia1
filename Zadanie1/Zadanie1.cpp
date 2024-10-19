#include <iostream>
using namespace std;

/**
 * @brief Struktura reprezentująca element listy.
 */
struct Element {
    int wartosc; ///< Wartość przechowywana w elemencie.
    Element* nastepny; ///< Wskaźnik na następny element.
    Element* poprzedni; ///< Wskaźnik na poprzedni element.

    /**
     * @brief Konstruktor elementu.
     *
     * @param dane Wartość do przechowania w elemencie.
     */
    Element(int dane) : wartosc(dane), nastepny(nullptr), poprzedni(nullptr) {}
};

/**
 * @brief Klasa reprezentująca listę dwukierunkową.
 */
class Lista {
private:
    Element* poczatek; ///< Wskaźnik na pierwszy element listy.
    Element* koniec; ///< Wskaźnik na ostatni element listy.

public:
    Lista() : poczatek(nullptr), koniec(nullptr) {}

    /**
     * @brief Dodaj nowy element na początek listy.
     *
     * @param wartosc Wartość elementu do dodania.
     */
    void dodajNaPoczatek(int wartosc) {
        Element* nowy = new Element(wartosc);
        if (poczatek == nullptr) {
            poczatek = koniec = nowy;
        }
        else {
            nowy->nastepny = poczatek;
            poczatek->poprzedni = nowy;
            poczatek = nowy;
        }
    }

    /**
     * @brief Dodaj nowy element na koniec listy.
     *
     * @param wartosc Wartość elementu do dodania.
     */
    void dodajNaKoniec(int wartosc) {
        Element* nowy = new Element(wartosc);
        if (koniec == nullptr) {
            poczatek = koniec = nowy;
        }
        else {
            koniec->nastepny = nowy;
            nowy->poprzedni = koniec;
            koniec = nowy;
        }
    }

    /**
     * @brief Dodaj nowy element pod wskazany indeks.
     *
     * @param wartosc Wartość elementu do dodania.
     * @param indeks Indeks, pod którym dodać nowy element.
     */
    void dodajPodIndeks(int wartosc, int indeks) {
        if (indeks < 0) return;
        if (indeks == 0) {
            dodajNaPoczatek(wartosc);
            return;
        }

        Element* nowy = new Element(wartosc);
        Element* temp = poczatek;
        for (int i = 0; i < indeks - 1 && temp != nullptr; i++) {
            temp = temp->nastepny;
        }

        if (temp == nullptr) {
            dodajNaKoniec(wartosc);
        }
        else {
            nowy->nastepny = temp->nastepny;
            nowy->poprzedni = temp;
            temp->nastepny = nowy;
            if (nowy->nastepny != nullptr) {
                nowy->nastepny->poprzedni = nowy;
            }
        }
    }

    /**
     * @brief Usuń element z początku listy.
     */
    void usunZPoczatku() {
        if (poczatek == nullptr) return;
        Element* temp = poczatek;
        poczatek = poczatek->nastepny;
        if (poczatek != nullptr) {
            poczatek->poprzedni = nullptr;
        }
        else {
            koniec = nullptr;
        }
        delete temp;
    }

    /**
     * @brief Usuń element z końca listy.
     */
    void usunZKonca() {
        if (koniec == nullptr) return;
        Element* temp = koniec;
        koniec = koniec->poprzedni;
        if (koniec != nullptr) {
            koniec->nastepny = nullptr;
        }
        else {
            poczatek = nullptr;
        }
        delete temp;
    }

    /**
     * @brief Usuń element z podanego indeksu.
     *
     * @param indeks Indeks elementu do usunięcia.
     */
    void usunZIndeksu(int indeks) {
        if (indeks < 0) return;
        if (indeks == 0) {
            usunZPoczatku();
            return;
        }

        Element* temp = poczatek;
        for (int i = 0; i < indeks && temp != nullptr; i++) {
            temp = temp->nastepny;
        }

        if (temp != nullptr) {
            if (temp->poprzedni != nullptr) {
                temp->poprzedni->nastepny = temp->nastepny;
            }
            if (temp->nastepny != nullptr) {
                temp->nastepny->poprzedni = temp->poprzedni;
            }
            delete temp;
        }
    }

    /**
     * @brief Wyświetl wszystkie elementy listy.
     */
    void wyswietlListe() {
        Element* temp = poczatek;
        while (temp != nullptr) {
            cout << temp->wartosc << " ";
            temp = temp->nastepny;
        }
        cout << endl;
    }

    /**
     * @brief Wyświetl listę w odwrotnej kolejności.
     */
    void wyswietlOdwrotnie() {
        Element* temp = koniec;
        while (temp != nullptr) {
            cout << temp->wartosc << " ";
            temp = temp->poprzedni;
        }
        cout << endl;
    }

    /**
     * @brief Czyść całą listę.
     */
    void czyscListe() {
        while (poczatek != nullptr) {
            usunZPoczatku();
        }
    }

    /**
     * @brief Destruktor, który czyści listę przy końcu działania programu.
     */
    ~Lista() {
        czyscListe();
    }
};

/**
 * @brief Funkcja główna programu do testowania listy dwukierunkowej.
 */
int main() {
    Lista lista;

    lista.dodajNaPoczatek(10);
    lista.dodajNaPoczatek(20);
    lista.dodajNaKoniec(30);
    lista.dodajPodIndeks(25, 0); // Dodaj 25 pod indeks 0

    cout << "Lista w kolejnosci: ";
    lista.wyswietlListe();

    cout << "Lista w odwrotnej kolejnosci: ";
    lista.wyswietlOdwrotnie();

    lista.usunZPoczatku();
    cout << "Po usunieciu pierwszego: ";
    lista.wyswietlListe();

    lista.usunZKonca();
    cout << "Po usunieciu ostatniego: ";
    lista.wyswietlListe();

    lista.usunZIndeksu(1); // Usuń element pod indeksem 0
    cout << "Po usunieciu elementu z indeksu 0: ";
    lista.wyswietlListe();

    lista.czyscListe();
    cout << "Lista po wyczyszczeniu: ";
    lista.wyswietlListe();

    return 0;
<<<<<<< HEAD
}
=======
}   
>>>>>>> parent of 686e393 (siodmy commit)
