#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (auto &ai: a)
        cin >> ai;

    vector<int> aux = a;
    sort(aux.begin(), aux.end());

    int diff = 0;
    for (int i = 0; i < n && diff <= 2; i++)
        if (aux[i] != a[i]) diff++;

    cout << (diff <= 2 ? "YES" : "NO") << "\n";
}