#include <iostream>
using namespace std;

int main() {
    double temperatura;
    bool czyPadaSnieg;

    // Pobranie danych od użytkownika
    cout << "Podaj temperature (°C): ";
    cin >> temperatura;

    cout << "Czy pada snieg? (1 = tak, 0 = nie): ";
    cin >> czyPadaSnieg;

    // Reguły systemu
    if (temperatura < 0) {
        cout << "Jest mroz" << endl;
    }

    if (czyPadaSnieg) {
        cout << "Drogi moga byc sliskie" << endl;
    }

    // Opcjonalnie: brak spełnionych warunków
    if (temperatura >= 0 && !czyPadaSnieg) {
        cout << "Brak szczegolnych warunkow pogodowych" << endl;
    }

    return 0;
}