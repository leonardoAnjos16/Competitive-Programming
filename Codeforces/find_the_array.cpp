#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int s; cin >> s;

        int ans = 1, sum = 1, curr = 3;
        while (sum + curr <= s)
            ans++, sum += curr, curr += 2;

        if (sum < s) ans++;
        cout << ans << "\n";
    }
}