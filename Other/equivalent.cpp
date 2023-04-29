#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S; cin >> S;
    int K; cin >> K;

    int N = S.size();
    llong ans = N;

    for (int i = 0; i < N; i++) {
        int l = i, r = i + 1, cnt = 0;
        while (l >= 0 && r < N && cnt <= K) {
            cnt += S[l] != S[r];
            if (cnt <= K) ans++;
            l--; r++;
        }

        l = i - 1; r = i + 1; cnt = 0;
        while (l >= 0 && r < N && cnt <= K) {
            cnt += S[l] != S[r];
            if (cnt <= K) ans++;
            l--; r++;
        }
    }

    cout << ans << "\n";
}