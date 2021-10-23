#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[6];
    for (int i = 0; i < 6; i++)
        cin >> a[i];

    bool possible = false;
    for (int i = 0; i < (1 << 6) && !possible; i++) {
        if (__builtin_popcount(i) == 3) {
            int b = 0, c = 0;
            for (int j = 0; j < 6; j++) {
                if (i & (1 << j)) b += a[j];
                else c += a[j];
            }

            if (b == c) possible = true;
        }
    }

    cout << (possible ? "YES" : "NO") << "\n";
}