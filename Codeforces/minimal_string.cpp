#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    int cnt[26] = {0};
    for (auto c: s) cnt[c - 'a']++;

    stack<char> t;
    string u;

    int idx = 0;
    while (idx < (int) s.size() || !t.empty()) {
        if (t.empty()) t.push(s[idx]), cnt[s[idx++] - 'a']--;
        else {
            bool wait = false;
            for (int i = 0; i < t.top() - 'a' && !wait; i++)
                if (cnt[i]) wait = true;

            if (!wait) u += t.top(), t.pop();
            else t.push(s[idx]), cnt[s[idx++] - 'a']--;
        }
    }

    cout << u << "\n";
}