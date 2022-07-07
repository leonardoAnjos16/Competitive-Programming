#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<int> memory;
vector<vector<int>> memo;

int find(int v) {
    int idx = lower_bound(memory.begin(), memory.end(), v) - memory.begin();
    if (idx > N || memory[idx] != v) return -1;
    return idx;
}

bool possible(int prev = 0, int curr = 1) {
    if (curr >= N) return true;

    int &ans = memo[prev][curr];
    if (~ans) return ans;

    int L = memory[curr] - memory[prev];

    int idx = find(memory[curr] + L - 1);
    if (L > 1 && idx != -1 && possible(curr, idx))
        return ans = true;

    idx = find(memory[curr] + L);
    if (idx != -1 && possible(curr, idx))
        return ans = true;

    idx = find(memory[curr] + L + 1);
    if (idx != -1 && possible(curr, idx))
        return ans = true;

    return ans = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N;

        memory.assign(N + 1, 0);
        for (int i = 1; i <= N; i++)
            cin >> memory[i];

        memo.assign(N + 1, vector<int>(N + 1, -1));

        cout << (possible() ? "YES" : "NO") << "\n";
    }
}