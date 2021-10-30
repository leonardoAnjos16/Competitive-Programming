#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q; cin >> Q;
    while (Q--) {
        int n; cin >> n;

        int cnt = 0, mid = 0;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            int m = s.size();

            for (int j = 0; j < m / 2; j++)
                if (s[j] != s[m - j - 1]) cnt++;

            if (m & 1) mid++;
        }

        if (!(cnt & 1)) cout << n << "\n";
        else {
            if (mid) cout << n << "\n";
            else cout << (n - 1) << "\n";
        }
    }
}