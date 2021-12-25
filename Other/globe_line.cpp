#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    set<int, greater<int>> aux;
    while (N--) {
        int ticket; cin >> ticket;
        auto it = aux.upper_bound(ticket);

        if (it == aux.end()) cout << "-1\n";
        else cout << *it << "\n";

        aux.insert(ticket);
    }
}