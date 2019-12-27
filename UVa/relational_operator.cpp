#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;

    for (int i = 0; i < num_cases; i++) {
        int first, second;
        cin >> first >> second;

        if (first < second) cout << "<" << endl;
        else if (first > second) cout << ">" << endl;
        else cout << "=" << endl;
    }
}