#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 101;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int last = 2;
    bool prime = true;

    while (last <= 10 && prime) {
        cout << "? " << last << "\n";
        cout.flush();

        string div;
        cin >> div;

        prime &= div == "no";
        if (prime) last++;
    }

    vector<int> test;
    if (last == 2) test = { 3, 4, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
    else if (last == 3) test = { 5, 7, 9, 11, 13, 17, 19, 23, 29, 31, 37 };
    else if (last == 5) test = { 7, 11, 13, 17, 19, 25 };
    else if (last == 7) test = { 11, 13, 49 };

    bool aux = false;
    for (int num: test) {
        cout << "? " << num << "\n";
        cout.flush();

        string div;
        cin >> div;

        if (div == "yes") {
            aux = true;
            break;
        }
    }

    if (!aux) prime = true;

    cout << "! " << (prime ? "prime" : "composite") << "\n";
    cout.flush();
}