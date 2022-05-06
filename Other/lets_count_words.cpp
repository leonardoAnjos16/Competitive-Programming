#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    set<string> generators;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;

        string mn = s;
        int size = s.size();

        for (int i = 1; i < size; i++) {
            s = s.substr(1) + s[0];
            mn = min(mn, s);
        }

        generators.insert(mn);
    }

    int ans = generators.size();
    cout << ans << "\n";
}