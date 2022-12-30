#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int cnt[MAX] = {0};
    while (N--) {
        int M; cin >> M;
        cin.ignore();

        while (M--) {
            string line;
            getline(cin, line);

            for (char c: line) {
                if (c >= 'a' && c <= 'z') cnt[c - 'a']++;
                else if (c >= 'A' && c <= 'Z') cnt[c - 'A']++;
            }
        }
    }

    int need[MAX] = {0};
    string target = "merrychristmas";

    for (char c: target)
        need[c - 'a']++;

    int ans = INT_MAX;
    for (char c: target)
        ans = min(ans, cnt[c - 'a'] / need[c - 'a']);

    cout << ans << "\n";
}