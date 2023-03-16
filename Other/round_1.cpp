#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("Round1.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        if (N <= 26) cout << "Yes\n";
        else cout << "No\n";
    }
}