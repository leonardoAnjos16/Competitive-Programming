#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<tuple<int, int, int>> points;
vector<vector<int>> memo;

int max_points(int i = 0, int last = 0) {
    if (i >= N) return 0;

    int &ans = memo[i][last];
    if (~ans) return ans;

    int a, b, c;
    tie(a, b, c) = points[i];

    if (last != 1) ans = max(ans, a + max_points(i + 1, 1));
    if (last != 2) ans = max(ans, b + max_points(i + 1, 2));
    if (last != 3) ans = max(ans, c + max_points(i + 1, 3));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    points.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        points[i] = make_tuple(a, b, c);
    }

    memo.assign(N + 5, vector<int>(5, -1));

    int ans = max_points();
    cout << ans << "\n";
}