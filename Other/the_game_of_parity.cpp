#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a & 1) odd++;
        else even++;
    }

    int moves = n - k;
    bool stannis = true;

    if (!moves) {
        if (!(odd & 1)) stannis = false;
    }
    else if (moves & 1) {
        if ((k & 1) && moves / 2 >= odd) stannis = false;
        else if (!(k & 1) && (moves / 2 >= even || moves / 2 >= odd)) stannis = false;
    }
    else if (!(k & 1) || moves / 2 < even) stannis = false;

    cout << (stannis ? "Stannis" : "Daenerys") << "\n";
}