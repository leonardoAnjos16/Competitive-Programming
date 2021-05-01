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

        int a[MAX];
        map<int, int> aux;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            aux[a[i]]++;
        }

        long cnt[MAX] = {0}, sum[MAX] = {0};
        for (auto p: aux) {
            cnt[p.snd]++;
            sum[p.snd] += p.snd;
        }

        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
            sum[i] += sum[i - 1];
        }

        long ans = INT_MAX;
        for (int i = 1; i <= n; i++)
            ans = min(ans, sum[i - 1] + sum[n] - sum[i] - (cnt[n] - cnt[i]) * i);

        cout << ans << "\n";
    }
}