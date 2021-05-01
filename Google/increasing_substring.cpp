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
        int N; cin >> N;
        string S; cin >> S;

        int ans[MAX] = {1};
        for (int i = 1; i < N; i++)
            ans[i] = S[i] <= S[i - 1] ? 1 : ans[i - 1] + 1;

        cout << "Case #" << t << ":";
        for (int i = 0; i < N; i++)
            cout << " " << ans[i];

        cout << "\n";
    }
}