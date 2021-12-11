#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, K;
    cin >> M >> N >> K;

    vector<int> changes(M);
    for (int i = 0; i < M; i++)
        cin >> changes[i];

    sort(changes.begin(), changes.end());

    vector<int> speeds(N);
    for (int i = 0; i < N; i++)
        cin >> speeds[i];

    bool red = true;
    vector<int> dist(N, 0);

    for (int i = 0; i < M; i++) {
        if (red) red = false;
        else {
            red = true;
            for (int j = 0; j < N; j++)
                dist[j] += speeds[j] * (changes[i] - changes[i - 1]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << (dist[i] >= K ? "1" : "0");
    }

    cout << "\n";
}