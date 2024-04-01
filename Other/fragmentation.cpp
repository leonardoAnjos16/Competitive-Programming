#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int last_prime[MAX] = {0};
vector<int> pos[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < MAX; i++)
        if (!last_prime[i])
            for (int j = i; j < MAX; j += i)
                last_prime[j] = i;

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        while (a > 1) {
            int p = last_prime[a];
            pos[p].push_back(i);
            a /= p;
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int s, t, k;
        cin >> s >> t >> k;

        bool possible = true;
        while (k > 1 && possible) {
            int p = last_prime[k], need = 0;
            while (last_prime[k] == p) {
                need++;
                k /= p;
            }

            int have = upper_bound(pos[p].begin(), pos[p].end(), t - 1) - lower_bound(pos[p].begin(), pos[p].end(), s - 1);
            if (have < need) possible = false;
        }

        cout << (possible ? "Yes" : "No") << "\n";
    }
}