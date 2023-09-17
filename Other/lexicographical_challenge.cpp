#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S; cin >> S;
    int K; cin >> K;

    vector<string> groups(K, "");
    for (int i = 0; i < (int) S.size(); i++)
        groups[i % K] += S[i];

    for (int i = 0; i < K; i++)
        sort(groups[i].begin(), groups[i].end());

    string ans = "";
    for (int i = 0; i < (int) S.size(); i++) {
        int group = i % K, idx = i / K;
        ans += groups[group][idx];
    }

    cout << ans << "\n";
}