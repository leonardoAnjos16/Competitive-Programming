#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> x(n + 1);
    vector<llong> ps(n + 1, 0LL);
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        ps[i] = ps[i - 1] + x[i];
    }

    multiset<llong> sums;
    sums.insert(0LL);

    llong ans = ps[a];
    for (int i = a + 1; i <= n; i++) {
        if (i > b) sums.erase(sums.find(ps[i - b - 1]));
        sums.insert(ps[i - a]);

        ans = max(ans, ps[i] - *sums.begin());
    }

    cout << ans << "\n";
}