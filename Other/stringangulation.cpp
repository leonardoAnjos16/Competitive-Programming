#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();

    s += s;
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n + i; j++)
            for (int k = j + 1; k < n + i; k++) {
                string a = s.substr(i, j - i);
                string b = s.substr(j, k - j);
                string c = s.substr(k, n + i - k);
                if (a + b > c && b + c > a && c + a > b) ans++;
            }

    assert(!(ans % 3));
    ans /= 3;
    
    cout << ans << "\n";
}