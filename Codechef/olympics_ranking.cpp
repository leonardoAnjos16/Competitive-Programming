#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int G1, S1, B1, G2, S2, B2;
        cin >> G1 >> S1 >> B1 >> G2 >> S2 >> B2;

        int T1 = G1 + S1 + B1;
        int T2 = G2 + S2 + B2;

        cout << (T1 > T2 ? "1" : "2") << "\n";
    }
}