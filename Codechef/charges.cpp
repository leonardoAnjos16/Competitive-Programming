#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        int dist = 0;
        string S; cin >> S;

        for (int i = 1; i < N; i++)
            dist += S[i] != S[i - 1] ? 1 : 2;

        while (K--) {
            int Q; cin >> Q;
            if (--Q > 0) {
                dist -= S[Q] != S[Q - 1] ? 1 : 2;
                dist += S[Q] != S[Q - 1] ? 2 : 1;
            }

            if (Q + 1 < N) {
                dist -= S[Q] != S[Q + 1] ? 1 : 2;
                dist += S[Q] != S[Q + 1] ? 2 : 1;
            }

            S[Q] = S[Q] == '0' ? '1' : '0';
            cout << dist << "\n";
        }
    }
}