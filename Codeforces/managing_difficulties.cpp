#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int a[MAX];
        unordered_map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        int ans = 0LL;
        for (int i = 0; i < n; i++) {
            cnt[a[i]]--;
            for (int j = i + 1; j < n; j++) {
                cnt[a[j]]--;
                int diff = a[j] - a[i];
                ans += cnt[a[j] + diff];
            }

            for (int j = i + 1; j < n; j++)
                cnt[a[j]]++;
        }

        cout << ans << "\n";
    }
}