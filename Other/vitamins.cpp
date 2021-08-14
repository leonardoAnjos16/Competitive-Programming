#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct DSU {
private:
    int n;
    vector<int> ds, sz;

public:
    DSU(int n) {
        this->n = n;
        ds.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++)
            ds[i] = i, sz[i] = 1;
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    void join(int i, int j) {
        i = find(i); j = find(j);
        if (sz[i] < sz[j]) swap(i, j);
        if (i != j) sz[i] += sz[j];
        ds[j] = i;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> gt, eq;
    while (m--) {
        string s;
        cin >> s;

        int sep = -1;
        for (int i = 0; i < (int) s.size(); i++)
            if (s[i] == '<' || s[i] == '>' || s[i] == '=')
                sep = i;

        int a = stoi(s.substr(0, sep));
        int b = stoi(s.substr(sep + 1));

        a--; b--;
        if (s[sep] == '<') swap(a, b);

        if (s[sep] == '=') eq.emplace_back(a, b);
        else gt.emplace_back(a, b);
    }

    DSU dsu(n);
    for (auto p: eq)
        dsu.join(p.first, p.second);

    vector<set<int>> nxt(n, set<int>());
    for (auto p: gt)
        nxt[dsu.find(p.first)].insert(dsu.find(p.second));

    set<int> whites, reds, blues;
    for (int i = 0; i < n; i++)
        for (auto j: nxt[i])
            for (auto k: nxt[j]) {
                whites.insert(i);
                reds.insert(j);
                blues.insert(k);
            }

    for (int i = 0; i < n; i++) {
        bool white = false;
        for (auto j: nxt[i])
            if (reds.count(j))
                white = true;

        if (white) whites.insert(i);
    }

    for (int i = 0; i < n; i++) {
        bool red = false;
        for (auto j: whites)
            if (nxt[j].count(i))
                for (auto k: nxt[i])
                    if (blues.count(k))
                        red = true;

        if (red) reds.insert(i);
    }

    for (int i = 0; i < n; i++) {
        bool blue = false;
        for (auto j: reds)
            if (nxt[j].count(i))
                blue = true;

        if (blue) blues.insert(i);
    }

    string s(n, '?');
    for (int i = 0; i < n; i++) {
        if (whites.count(dsu.find(i))) s[i] = 'W';
        else if (reds.count(dsu.find(i))) s[i] = 'R';
        else if (blues.count(dsu.find(i))) s[i] = 'B';
    }

    cout << s << "\n";
}