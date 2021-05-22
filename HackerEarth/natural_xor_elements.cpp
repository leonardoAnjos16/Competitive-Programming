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

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;

        vi ans(2, 0);
        bitset<40> done;

        for (int i = 0; i < 2; i++) {
            for (int j = 30; j >= 0; j--) {
                if (done[j]) continue;

                int group_size = (1 << j);
                int groups = (N + group_size) / group_size;

                int ones = (groups >> 1) * group_size;
                if (!(groups & 1)) {
                    ones -= group_size;
                    ones += N % group_size + 1;
                }

                if (!(ones & 1)) done[j] = true;
                else if ((ans[i] | (1 << j)) <= N) {
                    done[j] = true;
                    ans[i] |= 1 << j;
                }
            }
        }

        int aux = !(ans[0] + ans[1]) ? 0 : (!ans[1] ? 1 : 2);

        cout << aux;
        for (int i = 0; i < aux; i++)
            cout << " " << ans[i];

        cout << "\n";
    }
}