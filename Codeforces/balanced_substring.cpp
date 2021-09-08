#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int l = -1, r = -1;
        for (int i = 1; i < n && l == -1; i++)
            if (s[i - 1] != s[i])
                l = i, r = i + 1;

        cout << l << " " << r << "\n";
    }
}