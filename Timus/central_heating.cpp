#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 255;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> id(N);
    vector<bitset<MAX>> used(N, bitset<MAX>());
    vector<bitset<MAX>> basis(N, bitset<MAX>());

    for (int i = 0; i < N; i++) {
        int valve;
        bitset<MAX> valves;

        while (cin >> valve, valve != -1)
            valves[valve - 1] = true;

        bitset<MAX> curr;
        bool done = false;

        for (int j = N - 1; j >= 0 && !done; j--) {
            if (!valves[j]) continue;

            if (basis[j].any()) {
                curr ^= used[j];
                valves ^= basis[j];
            } else {
                id[j] = i;
                used[j] = curr;
                used[j][j] = true;
                basis[j] = valves;
                done = true;
            }
        }
    }

    bitset<MAX> target(string(N, '1'));

    bitset<MAX> curr;
    bool independent = false;

    for (int i = N - 1; i >= 0 && !independent; i--) {
        if (!target[i]) continue;

        if (basis[i].none()) independent = true;
        else target ^= basis[i], curr ^= used[i];
    }

    if (independent) cout << "No solution\n";
    else {
        vector<int> ans;
        for (int i = 0; i < N; i++)
            if (curr[i])
                ans.push_back(id[i] + 1);

        sort(ans.begin(), ans.end());
        for (int i = 0; i < (int) ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}