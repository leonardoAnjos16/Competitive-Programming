#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; long K;
    cin >> N >> K;

    long a[MAX];
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a, a + N);

    long l = a[0] + a[1], r = a[N - 2] + a[N - 1], ans;
    while (l <= r) {
        long mid = (l + r) / 2;

        long pos = 0;
        for (int i = 0; i < N && a[i] <= mid; i++) {
            int cnt = upper_bound(a, a + N, mid - a[i]) - a;
            if (mid - a[i] >= a[i]) pos--; pos += cnt;
        }

        pos /= 2;
        if (pos < K) l = mid + 1;
        else ans = mid, r = mid - 1;
    }

    cout << ans << "\n";
}