#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<bool> swapped;

bool match(vector<tuple<int, int, int>> &dominoes) {
    for (int i = 1; i < N; i++) {
        int prev = swapped[i - 1] ? get<0>(dominoes[i - 1]) : get<1>(dominoes[i - 1]);
        int curr = swapped[i] ? get<1>(dominoes[i]) : get<0>(dominoes[i]);
        if (prev != curr) return false;
    }

    return true;
}

bool solve(vector<tuple<int, int, int>> &dominoes, int i = 0) {
    if (i >= N) return match(dominoes);

    if (solve(dominoes, i + 1)) return true;

    swapped[i] = true;
    if (solve(dominoes, i + 1)) return true;
    swapped[i] = false;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<tuple<int, int, int>> dominoes(N);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        dominoes[i] = make_tuple(u, v, i + 1);
    }

    bool done = false;
    sort(dominoes.begin(), dominoes.end());

    do {
        swapped.assign(N, false);
        if (solve(dominoes)) done = true;
    } while (!done && next_permutation(dominoes.begin(), dominoes.end()));

    assert(done);

    vector<pair<int, char>> ans(N);
    for (int i = 0; i < N; i++) {
        int idx = get<2>(dominoes[i]);
        char c = swapped[i] ? 'a' : 'b';
        ans[i] = make_pair(idx, c);
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < N; i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
}