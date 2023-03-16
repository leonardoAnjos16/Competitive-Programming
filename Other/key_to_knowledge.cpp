#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> answers(n), correct(n);
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            cin >> correct[i];

            answers[i] = 0;
            for (int j = 0; j < m; j++)
                if (s[j] == '1')
                    answers[i] |= (1 << j);
        }

        int half = m / 2;
        map<vector<int>, int> cnt, mask;

        for (int i = 0; i < (1 << half); i++) {
            vector<int> half_correct(n);
            for (int j = 0; j < n; j++)
                half_correct[j] = half - __builtin_popcount(i ^ (answers[j] & ((1 << half) - 1)));

            cnt[half_correct]++;
            mask[half_correct] = i;
        }

        int total = 0, chosen = -1;
        for (int i = 0; i < (1 << (m - half)); i++) {
            vector<int> need = correct;
            for (int j = 0; j < n; j++)
                need[j] -= m - half - __builtin_popcount(i ^ (answers[j] >> half));

            total += cnt[need];
            if (cnt[need] == 1)
                chosen = mask[need] | (i << half);
        }

        string ans = "";
        for (int i = 0; i < m; i++) {
            if (chosen & (1 << i)) ans += '1';
            else ans += '0';
        }

        if (total == 1) cout << ans << "\n";
        else cout << total << " solutions\n";
    }
}