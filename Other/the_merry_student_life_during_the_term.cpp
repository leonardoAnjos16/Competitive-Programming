#include <bits/stdc++.h>

using namespace std;

#define long long long int

template<typename T>
bool comp(tuple<long, long, T> &a, tuple<long, long, T> &b) {
    auto [pa, wa, ta] = a;
    auto [pb, wb, tb] = b;
    return pa * wb < pb * wa;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("student.in", "r", stdin);
    freopen("student.out", "w", stdout);

    int N; cin >> N;

    int T = 0;
    vector<int> K(N);

    for (int i = 0; i < N; i++) {
        cin >> K[i];
        T += K[i];
    }

    vector<int> ps(T);
    for (int i = 0; i < T; i++)
        cin >> ps[i];

    vector<int> ws(T);
    for (int i = 0; i < T; i++)
        cin >> ws[i];

    int idx = 0;
    vector<tuple<long, long, vector<tuple<long, long, int>>>> labs(N);

    for (int i = 0; i < N; i++) {
        long P = 0LL, W = 0LL;
        vector<tuple<long, long, int>> curr(K[i]);

        for (int j = 0; j < K[i]; j++) {
            P += ps[idx]; W += ws[idx];
            curr[j] = make_tuple(ps[idx], ws[idx], idx + 1);
            idx++;
        }

        sort(curr.begin(), curr.end(), comp<int>);
        labs[i] = make_tuple(P, W, curr);
    }

    sort(labs.begin(), labs.end(), comp<vector<tuple<long, long, int>>>);

    vector<int> indices;
    long ans = 0LL, time = 0LL;

    for (int i = 0; i < N; i++) {
        auto [P, W, v] = labs[i];
        for (auto [p, w, idx]: v) {
            time += p;
            ans += w * time;
            indices.push_back(idx);
        }
    }

    assert((int) indices.size() == T);

    cout << ans << "\n";
    for (int i = 0; i < T; i++) {
        if (i) cout << " ";
        cout << indices[i];
    }

    cout << "\n";
}