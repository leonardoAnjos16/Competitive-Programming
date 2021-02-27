#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 5e3 + 5;

int n, a[MAX];

int min_moves(int l, int r, int mn = 0) {
    if (l > r) return 0;
    if (l == r && a[l]) return 1;

    int new_l = l, new_mn = INT_MAX, ans = mn;
    for (int i = l; i <= r; i++) {
        a[i] -= mn;
        if (a[i]) new_mn = min(new_mn, a[i]);
        else {
            ans += min_moves(new_l, i - 1, new_mn);
            new_l = i + 1; new_mn = INT_MAX;
        }
    }

    ans += min_moves(new_l, r, new_mn);
    return min(ans, r - l + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = min_moves(0, n - 1);
    cout << ans << "\n";
}