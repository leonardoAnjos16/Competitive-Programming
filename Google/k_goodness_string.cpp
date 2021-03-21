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

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;

        string S; cin >> S;

        int cnt = 0;
        for (int i = 0; i < N / 2; i++)
            cnt += S[i] != S[N - i - 1];

        int ans = abs(K - cnt);
        cout << "Case #" << t << ": " << ans << "\n";
    }
}