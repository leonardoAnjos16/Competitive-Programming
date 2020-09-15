#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s; cin >> s;
    int n = s.size();
    
    long ans = 0LL;
    for (int i = 0; i < n; i++)
        if (stoi(s.substr(i, 1)) % 4 == 0) ans++;

    for (int i = 1; i < n; i++)
        if (stoi(s.substr(i - 1, 2)) % 4 == 0) ans += i;

    printf("%lld\n", ans);
}