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

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int diff[MAX];
        for (int i = 0; i < n; i++) {
            cin >> diff[i];
            diff[i] -= i;
        }

        long ans = 0LL;
        map<int, int> cnt;

        for (int i = 0; i < n; i++)
            ans += cnt[diff[i]]++;

        cout << ans << "\n";
    }
}