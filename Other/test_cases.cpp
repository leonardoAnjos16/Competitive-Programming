#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define rall(ds) (ds).rbegin(), (ds).rend()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("cases.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        int a[MAX];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int cnt[MAX] = {0}, ans = 0;
        for (int i = 0; i < n; i++) {
            int even = 1, odd = 0;
            for (int j = i; j < n; j++) {
                if (cnt[a[j]]++ & 1) even++, odd--;
                else even--, odd++;

                if (odd == 1) ans++;
            }

            for (int j = i; j < n; j++)
                cnt[a[j]]--;
        }

        cout << ans << "\n";
    }
}