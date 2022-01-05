#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> pets;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pets.emplace_back(a, b);
    }

    sort(pets.begin(), pets.end());

    bool possible = false;
    for (int i = 1; i < n && !possible; i++)
        if (pets[i - 1].first < pets[i].first && pets[i - 1].second > pets[i].second) possible = true;

    cout << (possible ? "yes" : "no") << "\n";
}