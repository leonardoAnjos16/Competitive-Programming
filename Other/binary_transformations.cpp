#include <bits/stdc++.h>

using namespace std;

#define llong long long int

llong solve(multiset<int> &oz, multiset<int> &zo, multiset<int> &oo) {
    llong ans = 0LL;
    int idx = 0, cnt = oz.size();

    for (auto it = oz.rbegin(); it != oz.rend(); it++)
        ans += 1LL * idx++ * *it;

    idx = 0; cnt = zo.size();
    for (auto it = zo.begin(); it != zo.end(); it++)
        ans += 1LL * (cnt - idx++) * *it;

    cnt = oz.size() + zo.size();
    for (int c: oo)
        ans += 1LL * cnt * c;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    string a, b;
    cin >> a >> b;

    multiset<int> oz, zo, oo;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1' && b[i] == '0') oz.insert(c[i]);
        else if (a[i] == '0' && b[i] == '1') zo.insert(c[i]);
        else if (a[i] == '1') oo.insert(c[i]);
    }

    llong ans = solve(oz, zo, oo);
    while (!oo.empty()) {
        auto it = oo.end(); it--;
        oz.insert(*it);
        zo.insert(*it);
        oo.erase(it);
        ans = min(ans, solve(oz, zo, oo));
    }

    cout << ans << "\n";
}