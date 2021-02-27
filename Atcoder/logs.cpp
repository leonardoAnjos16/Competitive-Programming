#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define heap(ds, cmp) priority_queue<ds, vector<ds>, cmp>

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K; cin >> N >> K;

    double A[MAX];
    int r = INT_MIN;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        r = max(r, (int) A[i]);
    }

    int l = 1, ans = r;
    while (l <= r) {
        long mid = (l + r) / 2;

        long sum = 0LL;
        for (int i = 0; i < N && sum <= K; i++)
            sum += (int) ceil(A[i] / mid) - 1;
        
        if (sum > K) l = mid + 1;
        else ans = mid, r = mid - 1;
    }

    cout << ans << "\n";
}