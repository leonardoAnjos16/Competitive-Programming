#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int A, B, C, D, E;
        cin >> A >> B >> C >> D >> E;

        if (A + B <= D && C <= E) cout << "YES\n";
        else if (A + C <= D && B <= E) cout << "YES\n";
        else if (B + C <= D && A <= E) cout << "YES\n";
        else cout << "NO\n";
    }
}