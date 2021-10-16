#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int L; cin >> L;
    vector<bool> lit(M);

    while (L--) {
        int X; cin >> X;
        lit[X - 1] = true;
    }

    vector<vector<int>> switches(N);
    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        while (K--) {
            int Y; cin >> Y;
            switches[i].push_back(Y - 1);
        }
    }

    for (int i = 0; i <= 2 * N; i++) {
        bool all_zero = true;
        for (int j = 0; j < M && all_zero; j++)
            if (lit[j]) all_zero = false;

        if (all_zero) {
            cout << i << "\n";
            return 0;
        }

        int idx = i % N;
        for (auto l: switches[idx])
            lit[l] = !lit[l];
    }

    cout << "-1\n";
}