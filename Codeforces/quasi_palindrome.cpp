#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x; cin >> x;
    int n = x.size();

    int idx = n;
    while (idx > 0 && x[idx - 1] == '0') idx--;

    string aux = x.substr(0, idx);
    string rev = aux;
    reverse(aux.begin(), aux.end());

    if (aux == rev) cout << "YES\n";
    else cout << "NO\n";
}