#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, A, B, C;
        cin >> N >> A >> B >> C;

        cout << "Case #" << t << ": ";
        if (A + B - C > N || (A + B == 2 && N > 1)) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vector<int> ans(A - C, N - 1);
        if (C == 1 && A > 1) for (int i = 0; i < N - A - B + C; i++) ans.push_back(1);

        ans.push_back(N);
        if (C > 1) for (int i = 0; i < N - A - B + C; i++) ans.push_back(1);
        for (int i = 0; i < C - 1; i++) ans.push_back(N);

        if (C == 1 && A == 1) for (int i = 0; i < N - A - B + C; i++) ans.push_back(1);
        for (int i = 0; i < B - C; i++) ans.push_back(N - 1);

        for (auto h: ans) cout << h << " ";
        cout << "\n";
    }
}