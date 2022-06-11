#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<tuple<int, int, int>> beacons;

bool possible(int x, int y) {
    for (int i = 1; i < N; i++) {
        auto [X, Y, D] = beacons[i];
        if (abs(X - x) + abs(Y - y) != D)
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    beacons.resize(N);
    for (int i = 0; i < N; i++) {
        int X, Y, D;
        cin >> X >> Y >> D;
        beacons[i] = make_tuple(X, Y, D);
    }

    vector<pair<int, int>> ans;
    auto [X0, Y0, D0] = beacons[0];

    for (int dx = 0; dx <= D0 && (int) ans.size() < 2; dx++) {
        int dy = D0 - dx;
        if (possible(X0 + dx, Y0 + dy)) ans.emplace_back(X0 + dx, Y0 + dy);
        if (dy && possible(X0 + dx, Y0 - dy)) ans.emplace_back(X0 + dx, Y0 - dy);
        if (dx && possible(X0 - dx, Y0 + dy)) ans.emplace_back(X0 - dx, Y0 + dy);
        if (dx && dy && possible(X0 - dx, Y0 - dy)) ans.emplace_back(X0 - dx, Y0 - dy);
    }

    if (ans.empty()) cout << "impossible\n";
    else if ((int) ans.size() > 1) cout << "uncertain\n";
    else {
        auto [x, y] = ans[0];
        cout << x << " " << y << "\n";
    }
}