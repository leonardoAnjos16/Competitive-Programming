#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        bool possible = true;
        vector<int> p(n, -1), q(n, -1);
        vector<int> seenp(n, -1), seenq(n, -1);

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (!possible) continue;
            if (seenp[a - 1] == -1) p[i] = a, seenp[a - 1] = i;
            else if (seenq[a - 1] == -1) q[i] = a, seenq[a - 1] = i;
            else possible = false;
        }

        int idxp = n - 1, idxq = n - 1;
        for (int i = n - 1; i >= 0 && possible; i--) {
            if (seenp[i] != -1) {
                while (idxq >= 0 && seenq[idxq] != -1) idxq--;
                if (idxq > i) possible = false;
                else q[seenp[i]] = idxq-- + 1;
            }

            if (seenq[i] != -1) {
                while (idxp >= 0 && seenp[idxp] != -1) idxp--;
                if (idxp > i) possible = false;
                else p[seenq[i]] = idxp-- + 1;
            }
        }

        if (!possible) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                cout << p[i];
            }

            cout << "\n";
            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                cout << q[i];
            }

            cout << "\n";
        }
    }
}