#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<long> sticks(N);
    for (int i = 0; i < N; i++)
        cin >> sticks[i];

    sort(sticks.begin(), sticks.end());

    bool possible = false;
    for (int i = 0; i < N && !possible; i++)
        for (int j = i + 1; j < N && !possible; j++) {
            auto it = lower_bound(sticks.begin() + j + 1, sticks.end(), sticks[i] + sticks[j]);
            if (it != sticks.begin() + j + 1 && *(--it) < sticks[i] + sticks[j]) possible = true;
        }

    cout << (possible ? "possible" : "impossible") << "\n";
}