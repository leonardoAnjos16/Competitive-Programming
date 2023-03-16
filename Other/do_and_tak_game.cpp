#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("dotak.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        if (K & 1) cout << ((N & 1) ? "Omda" : "Teemo") << "\n";
        else {
            int aux = N % (K + 1);
            if (aux == 1 || (aux && !(aux & 1))) cout << "Omda\n";
            else cout << "Teemo\n";
        }
    }
}