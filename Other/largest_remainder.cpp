#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX_D = 16;
const int MAX_K = 200;
const int MAX_USED = 1 << MAX_D;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D, K;
    cin >> D >> K;
    
    int pows[MAX_D] = { 1 % K };
    for (int i = 1; i < MAX_D; i++)
        pows[i] = (10 * pows[i - 1]) % K;

    vector<int> d(D + 1, 0);
    for (int i = 0; i < D; i++)
        cin >> d[i];

    bool possible[MAX_USED][MAX_K] = {0};
    possible[0][0] = true;

    for (int i = 1; i < (1 << D); i++) {
        int cnt = __builtin_popcount(i);
        for (int j = 0; j < K; j++)
            for (int k = 0; k < D && !possible[i][j]; k++)
                if (i & (1 << k)) {
                    int mod = (j - (d[k] * pows[cnt - 1]) % K + K) % K;
                    if (possible[i ^ (1 << k)][mod]) possible[i][j] = true;
                }
    }

    int used = (1 << D) - 1, mod = K - 1;
    while (!possible[used][mod]) mod--;

    while (used) {
        int cnt = __builtin_popcount(used), digit = D;
        for (int i = 0; i < D; i++)
            if (used & (1 << i)) {
                int new_mod = (mod - (d[i] * pows[cnt - 1]) % K + K) % K;
                if (possible[used ^ (1 << i)][new_mod] && d[i] > d[digit]) digit = i;
            }

        cout << d[digit];
        used ^= 1 << digit;
        mod = (mod - (d[digit] * pows[cnt - 1]) % K + K) % K;
    }

    cout << "\n";
}