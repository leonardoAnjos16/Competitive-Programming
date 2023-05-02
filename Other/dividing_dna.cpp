#include <bits/stdc++.h>

using namespace std;

#define llong long long int

string ask(int l, int r) {
    cout << "? " << l << " " << r << "\n";
    cout.flush();

    string s;
    cin >> s;
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = 0, l = 0, r = 1;
    while (l < n) {
        while (r <= n && ask(l, r) == "present") r++;
        if (r <= n) ans++;
        l = r++;
    }

    cout << "! " << ans << "\n";
    cout.flush();
}