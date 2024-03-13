#include <iostream>
#include <vector>
#include<chrono>
using namespace std;
using namespace chrono;

const int ALPHABET_SIZE = 256; // A, C, G, T

void preprocessPattern(const string& pattern, vector<int>& badCharShift) {
    int m = pattern.length();

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badCharShift[i] = m;
    }

    for (int i = 0; i < m - 1; i++) {
        badCharShift[pattern[i] - 'A'] = m - 1 - i;
    }
}

void searchPattern(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> badCharShift(ALPHABET_SIZE);
    preprocessPattern(pattern, badCharShift);

    int i = 0;

    while (i <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }

        if (j < 0) {
            cout << "Pattern found at index " << i << endl;
            i += badCharShift[text[i + m - 1] - 'A'];
        } else {
            i += badCharShift[text[i + j] - 'A'];
        }
    }
}

int main() {
    string text = "ACGTACGTTGACGTACGTACGT";
    string pattern = "ACGT";
    auto start_time =high_resolution_clock::now();
    cout << "DNA Sequence: " << text << endl;
    cout << "Pattern to search: " << pattern << endl;

    searchPattern(text, pattern);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;
    return 0;
}
