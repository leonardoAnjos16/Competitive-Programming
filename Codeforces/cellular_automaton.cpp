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

    int N, K, Q;
    cin >> N >> K >> Q;

    string m; cin >> m;
    reverse(all(m));

    string s; cin >> s;

    string ans = s;
    while (Q--) {
        for (int i = 0; i < N; i++) {
            int idx = 0;
            for (int j = i - K; j <= i + K; j++) {
                idx <<= 1;
                if (s[(j + N) % N] == '1')
                    idx |= 1;
            }

            ans[i] = m[idx];
        }

        s = ans;
    }

    cout << ans << "\n";
}