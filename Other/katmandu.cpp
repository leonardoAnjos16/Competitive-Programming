#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, D, M;
    cin >> T >> D >> M;

    if (!M) cout << (T <= D ? "Y" : "N") << "\n";
    else {
        int last = 0, mx = 0;
        for (int i = 0; i < M; i++) {
            int y; cin >> y;
            mx = max(mx, y - last);
            last = y;
        }

        mx = max(mx, D - last);
        cout << (mx >= T ? "Y" : "N") << "\n";
    }
}