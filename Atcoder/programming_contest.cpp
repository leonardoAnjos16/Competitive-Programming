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

const int MAX = 45;

int T, A[MAX];

void sums(vector<int> &ans, int i, int r, int sum = 0) {
    if (sum > T) return;

    if (i > r || sum == T) ans.push_back(sum);
    else {
        sums(ans, i + 1, r, sum);
        sums(ans, i + 1, r, sum + A[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N >> T;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> l, r;
    int half = N / 2;

    sums(l, 0, half);
    sort(all(l));

    sums(r, half + 1, N - 1);
    sort(all(r));

    int ans = INT_MIN;
    for (int sum: l) {
        auto it = upper_bound(all(r), T - sum);
        if (it == r.begin()) ans = max(ans, sum);
        else ans = max(ans, sum + *(--it));
    }

    cout << ans << "\n";
}