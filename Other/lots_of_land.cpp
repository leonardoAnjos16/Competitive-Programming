#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, w, n;
    cin >> l >> w >> n;

    if ((l * w) % n) cout << "IMPOSSIBLE\n";
    else {
        int a = -1, b = -1;
        int area = l * w / n;

        for (int i = 1; i <= area && a == -1; i++)
            if (!(area % i) && !(l % i) && !(w % (area / i)))
                a = i, b = area / i;

        assert(a != -1 && b != -1);

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                char c = 'A' + (i / a) * (w / b) + (j / b);
                cout << c;
            }

            cout << "\n";
        }
    }
}