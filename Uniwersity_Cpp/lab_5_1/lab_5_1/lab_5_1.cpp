#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

void generuj(vector<int>& tab) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);

    for (int i = 0; i < 1000; ++i) {
        tab.push_back(dis(gen));
    }
}

void show(const vector<int>& tab) {

    for (const auto& num : tab) {
        cout << num << " ";
    }
    cout << endl << endl;
}

void sortuj(vector<int>& tab, int start, int stop) {

    sort(tab.begin() + start, tab.begin() + stop);

}

int main() {

    vector<int> bufor;

    generuj(bufor);

    cout << "Tablica przed sortowaniem:\n";
    show(bufor);

    thread t1(sortuj, ref(bufor), 0, 250);
    thread t2(sortuj, ref(bufor), 250, 500);
    thread t3(sortuj, ref(bufor), 500, 750);
    thread t4(sortuj, ref(bufor), 750, 1000);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // scalanie posortowanych fragmentów
    inplace_merge(bufor.begin(), bufor.begin() + 250, bufor.begin() + 500);
    inplace_merge(bufor.begin() + 500, bufor.begin() + 750, bufor.end());
    inplace_merge(bufor.begin(), bufor.begin() + 500, bufor.end());

    cout << "Tablica po sortowaniu:\n";
    show(bufor);

    return 0;
}