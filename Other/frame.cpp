#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("D.in", "r", stdin);

    long x, y;
    cin >> x >> y;

    int n; cin >> n;
    while (n--) {
        int Ak; cin >> Ak;

        bool ans = false;
        for (int i = 0; i < 2 && !ans; i++, swap(x, y)) {
            if (x % Ak <= 1) {
                int aux = 1 - x % Ak;
                if ((y - aux) % Ak <= 1) {
                    aux = 1 - (y - aux) % Ak;
                    if ((x - aux) % Ak <= 1) {
                        aux = 1 - (x - aux) % Ak;
                        if (!((y - 1 - aux) % Ak)) ans = true;
                    }
                }
            }
        }

        cout << (ans ? "YES" : "NO") << "\n";
    }
}