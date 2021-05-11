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

const int MAX = 5e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, B;
    while (cin >> N >> B, ~N || ~B) {
        int a[MAX], r = INT_MIN;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            r = max(r, a[i]);
        }

        int l = 1, ans;
        while (l <= r) {
            int mid = (l + r) / 2;

            long cnt = 0LL;
            for (int i = 0; i < N; i++)
                cnt += (a[i] + mid - 1) / mid;

            if (cnt > B) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        cout << ans << "\n";
    }
}