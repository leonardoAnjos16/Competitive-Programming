#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 30;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x = 0, sz = 0, basis[MAX] = {0};
    for (int i = 0; i < n; i++) {
        x ^= a[i];

        int v = x;
        bool done = false;

        for (int j = 0; j < MAX && !done; j++) {
            if (!(v & (1 << j))) continue;

            if (basis[j]) v ^= basis[j];
            else basis[j] = v, sz++, done = true;
        }
    }

    if (!x) cout << "-1\n";
    else cout << sz << "\n";
}