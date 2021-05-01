#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 1e3 + 5;

long gcd(long a, long b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long a[MAX];
    while (cin >> a[0], a[0]) {
        int sz = 1;
        while (cin >> a[sz], a[sz++]);

        sort(a, a + --sz);

        long ans = 0;
        for (int i = 1; i < sz; i++)
            ans = gcd(ans, a[i] - a[i - 1]);

        cout << ans << "\n";
    }
}