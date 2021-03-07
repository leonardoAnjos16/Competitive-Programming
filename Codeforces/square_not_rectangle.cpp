#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 3e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int H[MAX] = {0}, r = INT_MIN;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        r = max(r, H[i]);
    }

    int l = 1, ans;
    while (l <= r) {
        int mid = (l + r) / 2;

        int cnt = 0, mx = INT_MIN;
        for (int i = 0; i <= N; i++) {
            if (H[i] >= mid) cnt++;
            else mx = max(mx, cnt), cnt = 0;
        }

        if (mx < mid) r = mid - 1;
        else ans = mid, l = mid + 1;
    }

    cout << ans << "\n";
}