#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int dist(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> centers(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        centers[i] = make_pair(X, Y);
    }

    while (Q--) {
        int x, y, d;
        cin >> x >> y >> d;

        int ans = 0;
        for (auto [X, Y]: centers)
            if (X >= x && Y >= y && dist(x, y, X, Y) <= d)
                ans++;

        cout << ans << "\n";
    }
}