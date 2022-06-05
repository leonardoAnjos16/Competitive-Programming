#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;

        int aux = r / (b + 1);

        vector<int> sizes(b + 1, aux);
        for (int i = 0; i < r % (b + 1); i++)
            sizes[i]++;

        string ans = "";
        for (int i = 0; i < (int) sizes.size(); i++) {
            if (i) ans += "B";
            ans += string(sizes[i], 'R');
        }

        cout << ans << "\n";
    }
}