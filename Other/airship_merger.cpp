#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        pos[a] = i;
    }

    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        int b; cin >> b;
        c[i] = pos[b];
    }

    vector<int> aux;
    for (int i = 0; i < N; i++) {
        int idx = upper_bound(aux.begin(), aux.end(), c[i]) - aux.begin();
        if (idx < (int) aux.size()) aux[idx] = c[i];
        else aux.push_back(c[i]);
    }

    int ans = aux.size();
    cout << ans << "\n";
}