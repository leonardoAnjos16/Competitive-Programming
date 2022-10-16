#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<pair<int, int>> solve(int n, int a = 1, int b = 2, int c = 3) {
    if (n == 1) return { make_pair(a, c) };

    vector<pair<int, int>> ans = solve(n - 1, a, c, b);
    ans.emplace_back(a, c);

    vector<pair<int, int>> aux = solve(n - 1, b, a, c);
    for (pair<int, int> move: aux) ans.push_back(move);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> ans = solve(n);

    int size = ans.size();
    cout << size << "\n";

    for (auto [s, t]: ans)
        cout << s << " " << t << "\n";
}