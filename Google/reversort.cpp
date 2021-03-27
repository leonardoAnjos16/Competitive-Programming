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

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;

        int L[MAX];
        for (int i = 0; i < N; i++)
            cin >> L[i];

        int ans = 0;
        for (int i = 0; i < N - 1; i++) {
            int idx = i;
            for (int j = i + 1; j < N; j++)
                if (L[j] < L[idx]) idx = j;

            ans += idx - i + 1;
            reverse(L + i, L + idx + 1);
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}