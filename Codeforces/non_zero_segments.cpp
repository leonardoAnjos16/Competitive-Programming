#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    long sum = 0LL;
    set<long> sums;
    sums.insert(sum);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;

        if (!sums.count(sum)) sums.insert(sum);
        else {
            ans++;
            sum = a;

            sums.clear();
            sums.insert(a);
            sums.insert(0LL);
        }
    }

    cout << ans << "\n";
}