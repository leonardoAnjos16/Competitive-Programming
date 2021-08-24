#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<vector<int>> rows(N);
    for (int i = 0; i < N; i++) {
        int A;
        while (cin >> A, ~A)
            rows[i].push_back(A);
    }

    sort(rows.begin(), rows.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int) rows[i].size(); j++) {
            if (j) cout << " ";
            cout << rows[i][j];
        }

        cout << "\n";
    }
}