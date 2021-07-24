#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<array<int, 5>> words(n);
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            words[i] = { 0, 0, 0, 0, 0 };
            for (char c: s) words[i][c - 'a']++;
        }

        int ans = 0;
        for (char c = 'a'; c <= 'e'; c++) {
            priority_queue<int> heap;
            for (int i = 0; i < n; i++) {
                int bonus = 0;
                for (char d = 'a'; d <= 'e'; d++) {
                    if (c == d) bonus += words[i][d - 'a'];
                    else bonus -= words[i][d - 'a'];
                }

                heap.push(bonus);
            }

            int cnt = 0, bonus = 0;
            while (!heap.empty() && bonus + heap.top() > 0)
                cnt++, bonus += heap.top(), heap.pop();

            ans = max(ans, cnt);
        }

        cout << ans << "\n";
    }
}