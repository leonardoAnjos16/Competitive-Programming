#include <bits/stdc++.h>

using namespace std;

int N, M, L;
vector<bool> vis;

void visit(int i = 0) {
    if (i < 0 || i > L || vis[i]) return;

    vis[i] = true;
    visit(i + N);
    visit(i - M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int F;
    cin >> N >> M >> L >> F;

    vis.assign(L + 1, false);
    visit();

    int ans = 0;
    while (F--) {
        int f; cin >> f;
        ans += vis[f];
    }

    cout << ans << "\n";
}