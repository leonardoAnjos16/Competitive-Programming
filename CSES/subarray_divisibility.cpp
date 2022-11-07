#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int sum = 0;
    llong ans = 0LL;

    map<int, int> cnt;
    cnt[0] = 1;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum = (((sum + a) % n) + n) % n;

        ans += cnt[sum];
        cnt[sum]++;
    }

    cout << ans << "\n";
}