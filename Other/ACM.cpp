#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();

    bool ans = false;
    for (int i = 2; i < n && !ans; i++)
        if (s[i - 2] == 'A' && s[i - 1] == 'C' && s[i] == 'M')
            ans = true;

    cout << (ans ? "Fun!" : "boring...") << "\n";
}