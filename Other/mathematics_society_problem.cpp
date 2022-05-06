#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string N; cin >> N;

    int remove[MAX];
    for (int i = 0; i < MAX; i++)
        cin >> remove[i];

    int idx = 0;
    string ans = "";

    while (idx < (int) N.size()) {
        int seen[MAX] = {0}, have[MAX] = {0}, curr = idx, best = -1;
        for (int i = idx; i < (int) N.size(); i++)
            have[N[i] - '1']++;

        while (curr < (int) N.size()) {
            int d = N[curr] - '1';
            have[d]--;

            if (have[d] >= remove[d] - seen[d] && (best == -1 || N[curr] > N[best])) best = curr;
            if (++seen[d] > remove[d]) break;
            curr++;
        }

        if (best == -1) break;

        ans += N[best];
        for (int i = idx; i < best; i++)
            remove[N[i] - '1']--;

        idx = best + 1;
    }

    cout << ans << "\n";
}