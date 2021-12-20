#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> row(N * N), col(N * N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int a; cin >> a;
            row[a - 1] = i;
            col[a - 1] = j;
        }

    vector<int> cnt_row(N, 0);
    vector<int> cnt_col(N, 0);

    for (int i = 0; i < N * N; i++) {
        int a; cin >> a;
        if (++cnt_row[row[a - 1]] >= N) {
            cout << a << "\n";
            return 0;
        }

        if (++cnt_col[col[a - 1]] >= N) {
            cout << a << "\n";
            return 0;
        }
    }
}