#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        char s[MAX]; scanf("%s", s);
        int n = strlen(s);

        int l = 0, r = 0, cnt[3] = {0}, ans = 0;
        while (r < n) {
            while (r < n && (!cnt[0] || !cnt[1] || !cnt[2])) cnt[s[r++] - '1']++;
            while (cnt[s[l] - '1'] > 1) cnt[s[l++] - '1']--;
            if (cnt[0] && cnt[1] && cnt[2] && (!ans || r - l < ans)) ans = r - l;
            cnt[s[l++] - '1']--;
        }

        printf("%d\n", ans);
    }
}