#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        if (N == 1) cout << "1\n";
        else if (N == 2) cout << "4\n";
        else if (N == 3) cout << "10\n";
        else if (N == 4) cout << "18\n";
        else {
            int ans = 18 + 9 * (N - 4);
            cout << ans << "\n";
        }
    }
}