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
    while (T--) {
        int N; cin >> N;

        int ans[10] = {0};
        for (int i = 1; i <= N; i++) {
            int idx = 5, aux = i;
            while (aux) {
                ans[aux % 10]++;
                aux /= 10;
            }
        }

        for (int i = 0; i < 10; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}