#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Buduje tablicę prefiksową (tzw. "lps" – longest prefix suffix)
vector<int> buildLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);

    int len = 0; // długość poprzedniego najdłuższego prefiksu
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }

    return lps;
}

// Algorytm KMP: zwraca pozycje wystąpień wzorca w tekście
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> result;
    if (pattern.empty()) return result;

    int n = text.length();
    int m = pattern.length();
    vector<int> lps = buildLPS(pattern);

    int i = 0; // indeks tekstu
    int j = 0; // indeks wzorca

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }

        if (j == m) {
            result.push_back(i - j); // dopasowanie
            j = lps[j - 1]; // szukaj dalej
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return result;
}

int main() {
    ifstream file("plik.txt");
    if (!file) {
        cerr << "Nie można otworzyć pliku!" << endl;
        return 1;
    }

    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    string pattern;
    cout << "Podaj wzorzec do wyszukania: ";
    getline(cin, pattern);

    vector<int> positions = kmpSearch(text, pattern);

    if (positions.empty()) {
        cout << "Wzorzec nie został znaleziony." << endl;
    }
    else {
        cout << "Znaleziono wzorzec na pozycjach: ";
        for (int pos : positions)
            cout << pos << " ";
        cout << endl;
    }

    return 0;
}
