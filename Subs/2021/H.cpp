#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> numbers(K, vector<int>()), positions(K, vector<int>());
    for (int i = 0; i < N; i++) {
        int n, c;
        cin >> n >> c;

        numbers[c - 1].push_back(n - 1);
        positions[c - 1].push_back(i);
    }

    bool possible = true;
    for (int i = 0; i < K && possible; i++) {
        sort(numbers[i].begin(), numbers[i].end());
        sort(positions[i].begin(), positions[i].end());
        if (numbers[i] != positions[i]) possible = false;
    }

    cout << (possible ? "Y" : "N") << "\n";
}