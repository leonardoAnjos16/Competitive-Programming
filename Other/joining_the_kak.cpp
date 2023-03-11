#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    string s; cin >> s;
    sort(s.begin(), s.end());

    int cnt[MAX] = {0};
    for (int i = 0; i < N; i++)
        cnt[s[i] - 'a']++;

    int size = 1;
    cnt[s[0] - 'a']--;

    for (int i = 1; i < K; i++) {
        int idx = size - 1;
        while (idx >= 0) {
            int nxt = s[idx] - 'a' + 1;
            while (nxt < MAX && !cnt[nxt]) nxt++;

            cnt[s[idx] - 'a']++;
            if (nxt >= MAX) idx--;
            else {
                s[idx] = 'a' + nxt;
                cnt[nxt]--;
                break;
            }
        }

        int nxt = 0;
        if (idx < 0) size++;

        for (int i = idx + 1; i < size; i++) {
            while (nxt < MAX && !cnt[nxt]) nxt++;
            s[i] = 'a' + nxt;
            cnt[nxt]--;
        }
    }

    cout << s.substr(0, size) << "\n";
}