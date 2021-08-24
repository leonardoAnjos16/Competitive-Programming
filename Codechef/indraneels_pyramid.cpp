#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M; cin >> M;

    vector<int> mns(M);
    for (int i = 0; i < M; i++) {
        int w, h;
        cin >> w >> h;
        mns[i] = min(w, h);
    }

    sort(mns.begin(), mns.end());

    int ans = 0, idx = 0;
    while (idx < M) {
        while (idx < M && mns[idx] < ans + 1) idx++;
        if (idx < M) ans++, idx++;
    }

    cout << ans << "\n";
}