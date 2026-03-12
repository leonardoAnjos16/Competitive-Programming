#include <bits/stdc++.h>

using namespace std;

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s; cin >> s;

        int cnt[MAX] = {0};
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;

        int kfront = (k + 1) / 2;
        int taken_front[MAX] = {0};
        string front = "";

        for (char c = 'a'; c <= 'z'; c++) {
            int taken = min(kfront, cnt[c - 'a']);
            taken_front[c - 'a'] = taken;
            front += string(taken, c);
            kfront -= taken;
        }

        int kback = k / 2;
        multiset<pair<int, char>> back;

        for (int i = n - 1; i >= 0; i--) {
            if (!taken_front[s[i] - 'a']) back.emplace(i, s[i]);
            else taken_front[s[i] - 'a']--;
        }

        int id = n;
        auto it = back.begin();

        while (it != back.end() && next(it) != back.end() && kback) {
            auto nxt = next(it);
            if (it->second <= nxt->second) it++;
            else {
                nxt = it != back.begin() ? prev(it) : next(it);
                back.emplace(id, it->second);
                back.erase(it);
                it = nxt;
                kback--;
            }
        }

        string ans = front;
        for (auto [_, c]: back)
            ans += c;

        cout << ans << "\n";
    }
}