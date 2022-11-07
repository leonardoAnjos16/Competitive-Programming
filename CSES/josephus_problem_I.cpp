#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int rem = n;
    vector<bool> used(n, false);

    int seen = 0;
    while (rem) {
        for (int i = 0; i < n; i++) {
            if (!used[i])
                if (seen++ & 1) {
                    if (rem-- < n) cout << " ";
                    cout << (i + 1);
                    used[i] = true;
                }
        }
    }

    cout << "\n";
}