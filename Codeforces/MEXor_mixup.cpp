#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 3e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int aux[MAX] = {0};
    for (int i = 1; i < MAX; i++)
        aux[i] = aux[i - 1] ^ i;

    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int have = aux[a - 1];
        int need = b ^ have;

        if (have == b) cout << a << "\n";
        else if (need != a) cout << (a + 1) << "\n";
        else cout << (a + 2) << "\n";
    }
}