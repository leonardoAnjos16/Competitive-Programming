#include <bits/stdc++.h>

using namespace std;

#define long unsigned long long int

const int MAX = 11;

int digits(int n) {
    int ans = 0;
    while (n) {
        ans++;
        n /= 10;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, int> mods[MAX];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mods[digits(a[i])][a[i] % k]++;
    }

    long ans = 0LL;
    for (int i = 0; i < n; i++) {
        long aux = a[i] * 10LL;
        for (int j = 1; j < MAX; j++, aux *= 10LL) {
            int mod = (k - aux % k) % k;
            ans += mods[j][mod];
            if (digits(a[i]) == j && a[i] % k == mod) ans--;
        }
    }

    cout << ans << "\n";
}