#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 0;
        for (int i = 1; i < 5; i++) {
            for (int j = i - 1; j < n; j++) {
                bool good = true;
                for (int k = j - i + 1; k <= j && good; k++)
                    for (int l = k + 1; l <= j && good; l++)
                        for (int m = l + 1; m <= j && good; m++) {
                            if (a[k] <= a[l] && a[l] <= a[m]) good = false;
                            else if (a[k] >= a[l] && a[l] >= a[m]) good = false;
                        }

                ans += good;
            }
        }

        cout << ans << "\n";
    }
}