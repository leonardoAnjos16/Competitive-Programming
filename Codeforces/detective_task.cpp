#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        vector<int> forward(n, 0);
        for (int i = 1; i < n; i++)
            forward[i] = forward[i - 1] + (s[i - 1] == '0');

        vector<int> backward(n, 0);
        for (int i = n - 2; i >= 0; i--)
            backward[i] = backward[i + 1] + (s[i + 1] == '1');

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += !forward[i] && !backward[i];

        cout << ans << "\n";
    }
}