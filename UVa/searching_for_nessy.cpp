#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;

    for (int i = 0; i < num_cases; i++) {
        int rows, columns;
        cin >> rows >> columns;

        int min = (rows / 3) * (columns / 3);
        cout << min << endl;
    }
}