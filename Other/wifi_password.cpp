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

const int MAX = 1e5 + 5;
const int BITS = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("wifi.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int n, v;
        cin >> n >> v;

        int A[MAX];
        for (int i = 1; i <= n; i++)
            cin >> A[i];

        vector<vi> cnt(n + 1, vi(BITS, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < BITS; j++) {
                cnt[i][j] += cnt[i - 1][j];
                if (A[i] & (1 << j))
                    cnt[i][j]++;
            }
        }

        int l = 0, r = n, ans;
        while (l <= r) {
            int mid = (l + r) / 2;

            bool possible = false;
            for (int i = mid; i <= n && !possible; i++) {
                int or_value = 0;
                for (int j = 0; j < BITS; j++)
                    if (cnt[i][j] > cnt[i - mid][j])
                        or_value |= 1 << j;

                if (or_value <= v) possible = true;
            }

            if (!possible) r = mid - 1;
            else ans = mid, l = mid + 1;
        }

        cout << ans << "\n";
    }
}