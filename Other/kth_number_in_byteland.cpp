#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 25;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k; cin >> k;

    string ans = to_string(k - 1);

    string aux = ans.substr(0, (int) ans.size() - 1);
    reverse(aux.begin(), aux.end());

    ans += aux;
    cout << ans << "\n";
}