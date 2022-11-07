#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = 1, l = 0;
    map<int, int> last;

    for (int i = 0; i < n; i++) {
        int k; cin >> k;

        if (last.count(k))
            l = max(l, last[k] + 1);

        ans = max(ans, i - l + 1);
        last[k] = i;
    }

    cout << ans << "\n";
}