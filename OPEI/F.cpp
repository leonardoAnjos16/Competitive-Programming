#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    string champion;
    map<string, int> cnt;

    while (cin >> champion)
        cnt[champion]++;

    for (auto [name, c]: cnt)
        cout << name << " " << c << "\n";
}