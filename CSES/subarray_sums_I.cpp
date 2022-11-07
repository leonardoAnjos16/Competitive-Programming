#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x;
    cin >> n >> x;
 
    long long int ans = 0LL, sum = 0LL;
    map<long long int, int> cnt;
    cnt[0LL] = 1;
 
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
 
        sum += a;
        ans += cnt[sum - x];
        cnt[sum]++;
    }
 
    cout << ans << "\n";
}