#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;
    cin >> N >> C;

    int matches = 0;
    string ans = "";
    map<string, int> cnt;

    for (int i = 0; i < N; i++) {
        string S; cin >> S;

        int idx = 0;
        while (idx < C && S[idx] != '*') idx++;
        assert(idx < C);

        for (char c = 'a'; c <= 'z'; c++) {
            S[idx] = c;
            cnt[S]++;

            if (cnt[S] > matches || (cnt[S] == matches && S < ans))
                matches = cnt[S], ans = S;
        }
    }

    cout << ans << " " << matches << "\n";
}