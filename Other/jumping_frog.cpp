#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S; cin >> S;
    int N = S.size();

    bool all_r = true;
    for (int i = 0; i < N && all_r; i++)
        if (S[i] != 'R') all_r = false;

    if (all_r) cout << (N - 1) << "\n";
    else {
        map<int, int> aux;
        for (int i = 2; i < N; i++) {
            int g = gcd(N, i);
            if (g > 1) aux[g]++;
        }

        int ans = 0;
        for (auto [g, cnt]: aux) {
            int size = N / g;
            int jump = (N - size) / size + 1;

            bool possible = false;
            vector<bool> vis(N, false);

            for (int i = 0; !vis[i] && !possible; i++) {
                possible = true;
                for (int j = i; !vis[j]; j = (j + jump) % N) {
                    if (S[j] == 'P')
                        possible = false;
                    
                    vis[j] = true;
                }
            }

            if (possible) ans += cnt;
        }

        cout << ans << "\n";
    }
}