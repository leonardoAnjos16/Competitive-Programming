#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = 0;
    set<int> notes;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;

        int l = 0;
        auto it = notes.upper_bound(a);
        if (it != notes.begin()) l = *(--it);

        int r = n + 1;
        it = notes.upper_bound(a);
        if (it != notes.end()) r = *it;

        ans += r - l - 1;
        notes.insert(a);
    }

    cout << ans << "\n";
}