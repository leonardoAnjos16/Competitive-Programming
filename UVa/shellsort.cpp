#include <bits/stdc++.h>

using namespace std;

const int MAX = 205;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int K; cin >> K;
    while (K--) {
        int n; cin >> n;
        cin.ignore(MAX, '\n');

        string curr[MAX];
        for (int i = 1; i <= n; i++)
            getline(cin, curr[n - i]);

        string des[MAX];
        for (int i = 1; i <= n; i++)
            getline(cin, des[n - i]);

        int idx_curr = 0, idx_des = 0;
        while (idx_curr < n) {
            while (idx_curr < n && curr[idx_curr] == des[idx_des])
                idx_curr++, idx_des++;

            idx_curr++;
        }

        while (idx_des < n)
            cout << des[idx_des++] << "\n";

        cout << "\n";
    }
}