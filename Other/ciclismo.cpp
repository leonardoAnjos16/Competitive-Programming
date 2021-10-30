#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    while (N--) {
        int T, S, V;
        cin >> T >> S >> V;

        if (!V) cout << (!S ? "SIM" : "NAO") << "\n";
        else {
            int need = (S + V - 1) / V;
            cout << (need <= T ? "SIM" : "NAO") << "\n";
        }
    }
}