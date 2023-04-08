#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        if (!(n & 1)) cout << "-1\n";
        else {
            vector<int> moves;

            int p = 1;
            while ((p << 1) < n)
                p <<= 1;

            while (p > 2) {
                int diff = n - p;
                bool second = (diff >> 1) & 1;
                moves.push_back(second ? 2 : 1);

                if (!second) n++;
                n >>= 1;
                p >>= 1;
            }

            moves.push_back(2);
            reverse(moves.begin(), moves.end());

            int cnt = moves.size();
            cout << cnt << "\n";

            for (int i = 0; i < cnt; i++) {
                if (i) cout << " ";
                cout << moves[i];
            }

            cout << "\n";
        }
    }
}