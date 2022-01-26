#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        if (n <= 5) cout << "-1\n";
        else if (n & 1) cout << "3 " << (n - 3) << "\n";
        else cout << "2 " << (n - 2) << "\n";
    }
}