#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, M, X;
        cin >> N >> M >> X;

        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; i++) {
            int score; cin >> score;
            A[i] = make_pair(score, i + 1);
        }

        sort(A.begin(), A.end(), greater<pair<int, int>>());

        int cnt = 0;
        vector<int> ans;

        while (cnt < N && (cnt < X || A[cnt].first >= M))
            ans.push_back(A[cnt++].second);

        sort(ans.begin(), ans.end());

        cout << cnt;
        for (auto id: ans)
            cout << " " << id;

        cout << "\n";
    }
}