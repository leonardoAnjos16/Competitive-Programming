#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int flow = 0;
    vector<int> rows(n, 0);
    deque<vector<int>> cols(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string row; cin >> row;
        for (int j = 0; j < n; j++) {
            rows[i] += row[j] - '0';
            cols[j][i] = row[j] - '0';
        }

        flow += rows[i] == n;
    }

    for (int i = 0; i < n; i++) {
        int ones = 0;
        for (int j = 0; j < n; j++)
            ones += cols[i][j];

        flow += ones == n;
    }

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int i, j, b;
            cin >> i >> j >> b;
            i--; j--;

            if (rows[i] == n) flow--;
            if (cols[j][i]) rows[i]--;

            int ones = 0;
            for (int k = 0; k < n; k++)
                ones += cols[j][k];

            if (ones == n) flow--;
            if (cols[j][i]) ones--;

            cols[j][i] = b;
            if (b) rows[i]++;
            if (rows[i] == n) flow++;

            if (b) ones++;
            if (ones == n) flow++;
        } else {
            int b; cin >> b;

            int ones = 0;
            vector<int> col;
            col.push_back(b);

            for (int i = 0; i < n; i++) {
                ones += cols[n - 1][i];
                if (rows[i] == n) flow--;
                if (cols[n - 1][i]) rows[i]--;

                if (i < n - 1)
                    col.push_back(cols[n - 1][i]);
            }

            if (ones == n) flow--;
            if (cols[n - 1][n - 1]) ones--;

            cols.pop_back();
            cols.push_front(col);

            if (b) ones++;
            if (ones == n) flow++;

            for (int i = 0; i < n; i++) {
                if (cols[0][i]) rows[i]++;
                if (rows[i] == n) flow++;
            }
        }

        cout << flow << "\n";
    }
}