#include <bits/stdc++.h>

using namespace std;

int main() {
    int sizeInput;
    cin >> sizeInput;

    map<string, int> counter;
    for (int i = 0; i < sizeInput; i++) {
        string input;
        cin >> input;

        if (counter.count(input)) counter[input]++;
        else counter[input] = 1;
    }

    int sizeQueries;
    cin >> sizeQueries;

    for (int i = 0; i < sizeQueries; i++) { 
        string querie;
        cin >> querie;

        if (counter.count(querie)) cout << counter[querie] << endl;
        else cout << 0 << endl;
    }

    return 0;
}