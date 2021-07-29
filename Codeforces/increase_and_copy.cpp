#include <bits/stdc++.h>

using namespace std;

#define long long long int

int moves(int n, int x) {
    return x + (n + x - 1) / x - 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int l = 1, r = n;
        while (l < r) {
            int aux = (r - l) / 3;
            int m1 = l + aux, m2 = r - aux;

            if (moves(n, m1) < moves(n, m2)) r = m2 - 1;
            else if (moves(n, m1) > moves(n, m2)) l = m1 + 1;
            else {
                int i = m1 - 1, j = m2 + 1;
                while (i >= l && j <= r && moves(n, i) == moves(n, j))
                    i--, j++;

                if (i < l || j > r) l = m1 + 1;
                else if (moves(n, i) < moves(n, j)) r = m2 - 1;
                else l = m1 + 1;
            }
        }

        int ans = l + (n + l - 1) / l - 2;
        cout << ans << "\n";
    }
}