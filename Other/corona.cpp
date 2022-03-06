#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n;
string s;
vector<int> prefix;

void get_prefix(int start) {
    prefix[start] = 0;
    for (int i = start + 1; i < n; i++) {
        int k = prefix[i - 1];
        while (k > 0 && s[start + k] != s[i])
            k = prefix[start + k - 1];

        if (s[start + k] == s[i]) k++;
        prefix[i] = k;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> s) {
        n = s.size();
        prefix.resize(n);

        long ans = 0LL;
        for (int i = 0; i < n; i++) {
            get_prefix(i);
            for (int j = i; j < n; j++)
                ans += prefix[j];
        }

        cout << ans << "\n";
    }
}