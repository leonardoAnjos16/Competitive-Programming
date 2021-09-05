#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("abc.in", "r", stdin);

    int n; cin >> n;
    string s; cin >> s;

    int cnt[3] = {0}, pos_b;
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
        if (s[i] == 'b') pos_b = i;
    }

    if (!cnt[0] || !cnt[2]) cout << "0\n";
    else if (!cnt[1]) cout << "-1\n";
    else {
        int fst = 0;
        for (int i = 0; i < cnt[0]; i++)
            if (s[i] != 'a') fst++;

        fst += (pos_b > cnt[0]) || (s[cnt[0]] == 'c');

        int snd = 0;
        for (int i = 0; i < cnt[2]; i++)
            if (s[i] != 'c') snd++;

        snd += (pos_b > cnt[2]) || (s[cnt[2]] == 'a');

        int ans = min(fst, snd);
        cout << ans << "\n";
    }
}