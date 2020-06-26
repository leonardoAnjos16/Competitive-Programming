#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        char s[MAX]; scanf("%s", s);
        int m; scanf("%d", &m);

        int b[MAX];
        for (int i = 0; i < m; i++)
            scanf("%d", &b[i]);

        int n = strlen(s);
        sort(s, s + n, [](char a, char b) { return a > b; });

        int cnt[26] = {0};
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;

        char ans[MAX] = {0};
        int idx = 0, rem = m;

        while (rem) {
            vector<int> pos;
            for (int i = 0; i < m; i++)
                if (!ans[i] && !b[i]) pos.push_back(i);

            while (cnt[s[idx] - 'a'] < (int) pos.size()) idx += cnt[s[idx] - 'a'];

            for (int i = 0; i < (int) pos.size(); i++) {
                ans[pos[i]] = s[idx]; rem--;
                for (int j = 0; j < m; j++)
                    if (b[j]) b[j] -= abs(pos[i] - j);
            }

            idx += cnt[s[idx] - 'a'];
        }

        printf("%s\n", ans);
    }
}