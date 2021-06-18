#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int M, K, N;
        cin >> M >> K >> N;

        vector<pair<double, int>> m(M);
        for (int i = 0; i < M; i++) {
            double mass; cin >> mass;
            m[i] = make_pair(mass, i);
        }

        sort(m.begin(), m.end());

        vector<double> a(K);
        for (int i = 0; i < K; i++)
            cin >> a[i];

        for (int i = 0; i < N; i++) {
            double s; cin >> s;

            int j, k;
            double delta = 2e6;

            for (int l = 0; l < K; l++) {
                auto it = lower_bound(m.begin(), m.end(), make_pair(s - a[l], 0));
                if (it != m.end() && it->first + a[l] > 0.0 && abs(s - (it->first + a[l])) < delta)
                    j = it->second + 1, k = l + 1, delta = abs(s - (it->first + a[l]));

                if (it != m.begin()) it--;
                if (it->first + a[l] > 0.0 && abs(s - (it->first + a[l])) < delta)
                    j = it->second + 1, k = l + 1, delta = abs(s - (it->first + a[l]));
            }

            cout << j << " " << k << "\n";
        }
    }
}