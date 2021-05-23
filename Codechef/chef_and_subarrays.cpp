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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vi A(N);
        vector<map<int, int>> cnt(K);
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            cnt[i % K][A[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < K; i++) {
            int mx = INT_MIN, total = 0;
            for (auto p: cnt[i]) {
                total += p.snd;
                mx = max(mx, p.snd);
            }

            ans += total - mx;
        }

        cout << ans << "\n";
    }
}