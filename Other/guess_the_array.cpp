#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    set<pair<int, int>> blocked;
    vector<llong> ps(n + 1, 0LL);

    for (int i = 1; i <= n; i++) {
        int l = 1;
        while (l <= i && blocked.count(make_pair(l, i))) l++;

        assert(l <= i);
        cout << "? " << l << " " << i << "\n";
        cout.flush();

        llong s; int lb, rb;
        cin >> s >> lb >> rb;

        blocked.emplace(lb, rb);
        int v = l == i ? s : s - ps[i - 1] + ps[l - 1];
        ps[i] = ps[i - 1] + v;
    }

    cout << "!\n";
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";

        int v = ps[i] - ps[i - 1];
        cout << v;
    }

    cout << "\n";
    cout.flush();
}