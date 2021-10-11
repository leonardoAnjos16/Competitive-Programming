#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    map<int, int> xs, ys;
    vector<pair<int, int>> points(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        xs[x]++; ys[y]++;
        points[i] = make_pair(x, y);
    }

    sort(points.begin(), points.end());
    /* for (auto &[y, x]: xs)
        sort(x.begin(), x.end());

    for (auto &[x, y]: ys)
        sort(y.begin(), y.end()); */

    long ans = 0LL;
    for (int i = 0; i < N; i++) {
        auto A = points[i];
        for (int j = 0; j < N; j++) {
            auto B = points[j];
            if (A.second == B.second && A.first < B.first) {
                int diff = B.first - A.first;
                if (diff & 1) continue;
                diff >>= 1;

                if (binary_search(points.begin(), points.end(), make_pair(A.first + diff, A.second)))
                    ans += xs[A.first + diff] - 1;
            } else if (A.first == B.first && A.second < B.second) {
                int diff = B.second - A.second;
                if (diff & 1) continue;
                diff >>= 1;

                if (binary_search(points.begin(), points.end(), make_pair(A.first, A.second + diff)))
                    ans += ys[A.second + diff] - 1;
            }
        }
    }

    cout << ans << "\n";
}