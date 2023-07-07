#include <bits/stdc++.h>

using namespace std;

int surface_area(int h, int w, int l) {
    int ans = 2 * w * l;
    ans += 2 * h * w;
    ans += 2 * h * l;
    return ans;
}

int solve(int h, int area) {
    int ans = INT_MAX;
    for (int w = 1; w * w <= area; w++)
        if (!(area % w))
            ans = min(ans, surface_area(h, w, area / w));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V; cin >> V;

    int ans = INT_MAX;
    for (int h = 1; h * h <= V; h++)
        if (!(V % h)) {
            ans = min(ans, solve(h, V / h));
            ans = min(ans, solve(V / h, h));
        }

    cout << ans << "\n";
}