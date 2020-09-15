#include <bits/stdc++.h>

using namespace std;

map<string, string> A;
map<string, int> memo;

void next_row(string &cell) {
    int idx = 0;
    while (cell[idx] >= 'A' && cell[idx] <= 'Z') idx++;
    cell = "A" + to_string(stoi(cell.substr(idx)) + 1);
}

void next_col(string &cell) {
    int idx = 0;
    while (cell[idx] >= 'A' && cell[idx] <= 'Z') idx++;
    while (cell[--idx] == 'Z') cell[idx] = 'A';

    if (idx < 0) cell = "A" + cell;
    else cell[idx]++;
}

void indices(string cell, int &i, int &j) {
    int idx = 0, mult = 1; i = 0;
    while (cell[idx] >= 'A' && cell[idx] <= 'Z') {
        i += (cell[idx++] - 'A') * mult;
        mult *= 26;
    }

    j = stoi(cell.substr(idx));
}

int compute(string cell) {
    string value = A[cell];
    if (value[0] != '=') return stoi(value);

    if (memo.count(cell)) return memo[cell];

    string aux = "";
    value += '+';

    int ans = 0;
    for (int i = 1; i < (int) value.size(); i++) {
        if (value[i] != '+') aux += value[i];
        else ans += compute(aux), aux = "";
    }

    return memo[cell] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int c, r; cin >> c >> r;

        string cell = "A1";
        for (int i = 0; i < r; i++, next_row(cell))
            for (int j = 0; j < c; j++, next_col(cell))
                cin >> A[cell];

        cell = "A1";
        for (int i = 0; i < r; i++, next_row(cell)) {
            for (int j = 0; j < c; j++, next_col(cell)) {
                if (j) cout << " ";

                if (A[cell][0] != '=') cout << A[cell];
                else cout << compute(cell);
            }

            cout << "\n";
        }

        A.clear();
        memo.clear();
    }
}