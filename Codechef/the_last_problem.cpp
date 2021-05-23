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

const int MAX = 1e3 + 5;

long get_sum(long start, int length) {
    long ans = (start + length - 1) * (start + length) / 2;
    return ans - (start - 1) * start / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long ans = 0LL;
        for (int i = x1; i <= x2; i++) {
            long aux = get_sum(1, y1 - 1) + 1LL;
            ans += aux + get_sum(y1 + 1, i - 1);
        }

        for (int i = y1 + 1; i <= y2; i++) {
            long aux = get_sum(1, i - 1) + 1LL;
            ans += aux + get_sum(i + 1, x2 - 1);
        }

        cout << ans << "\n";
    }
}