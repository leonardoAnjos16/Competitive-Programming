#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    set<string> names;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        if (names.count(s)) printf("YES\n");
        else printf("NO\n");

        names.insert(s);
    }
}