#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N) {
        if (N == 1) cout << "1\n";
        else {
            int ans = 2 * N - 2;
            cout << ans << "\n";
        }
    }
}