#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        if (n == 3) cout << "-1\n";
        else {
            for (int i = 0; i < n / 2; i++)
                cout << (n - i) << " ";

            for (int i = n / 2; i < n; i++) {
                if (i > n / 2) cout << " ";
                cout << (i - n / 2 + 1);
            }

            cout << "\n";
        }
    }
}