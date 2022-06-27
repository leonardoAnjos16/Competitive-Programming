#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    long sum = N * (N + 1LL) / 2LL;

    if (sum & 1LL) cout << "-1\n";
    else {
        sum /= 2LL;
        string ans = "";
        
        for (int i = N; i > 0; i--) {
            if (i > sum) ans += "-";
            else ans += "+", sum -= i;
        }

        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}