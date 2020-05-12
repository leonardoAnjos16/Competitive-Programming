#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s, t;
    while (cin >> s >> t) {
        int idx = 0;
        string aux = "";

        for (int i = 0; i < (int) s.size() && idx < (int) t.size(); i++, idx++) {
            while (idx < (int) t.size() && s[i] != t[idx]) idx++;
            if (idx < (int) t.size()) aux += t[idx];
        }

        bool sub = aux == s;
        printf("%s\n", sub ? "Yes" : "No");
    }
}