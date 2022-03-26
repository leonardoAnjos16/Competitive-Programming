#include <bits/stdc++.h>

using namespace std;

#define long long long int

map<string, vector<string>> g;

bool path(set<string> &vis, string a, string b) {
    vis.insert(a);
    if (a == b) return true;

    for (auto country: g[a])
        if (!vis.count(country) && path(vis, country, b))
            return true;

    return false;
}

bool path(string a, string b) {
    set<string> vis;
    return path(vis, a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (n--) {
        string a, are, worse, than, b;
        cin >> a >> are >> worse >> than >> b;
        g[a].push_back(b);
    }

    while (m--) {
        string a, are, worse, than, b;
        cin >> a >> are >> worse >> than >> b;

        if (path(a, b)) cout << "Fact\n";
        else if (path(b, a)) cout << "Alternative Fact\n";
        else cout << "Pants on Fire\n";
    }
}