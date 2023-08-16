#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;
const int MAX = 4e5 + 5;

struct SparseTable {
private:
    int n;
    vector<vector<int>> table;

public:
    SparseTable() {}
    SparseTable(vector<int> &a) {
        n = a.size();
        table.assign(LOG, vector<int>(n));
        table[0] = a;

        for (int i = 1; i < LOG; i++)
            for (int j = 0; j < n; j++) {
                int jump = 1 << (i - 1);
                table[i][j] = table[i - 1][j];

                if (j + jump < n)
                    table[i][j] = min(table[i][j], table[i - 1][j + jump]);
            }
    }

    int get_min(int l, int r) {
        int idx = __lg(r - l + 1), jump = 1 << idx;
        return min(table[idx][l], table[idx][r - jump + 1]);
    }
};

struct SuffixArray {
private:
    const int SEP = 300;

    int n, sep, text[MAX];
    vector<int> p, c, lcp;
    SparseTable table;

public:
    SuffixArray(): n(0), sep(SEP) {}

    void add(string &s) {
        if (n) text[n++] = sep++;
        for (char c: s) text[n++] = c;
    }

    void build() {
        text[n++] = 0;

        p.resize(n);
        c.resize(n);

        for (int i = 0; i < n; i++) {
            p[i] = i;
            c[i] = text[i];
        }

        sort();
        get_classes(0);

        for (int len = 1; c[p[n - 1]] + 1 < n; len <<= 1) {
            for (int i = 0; i < n; i++) {
                p[i] -= len;
                p[i] = (p[i] % n + n) % n;
            }

            sort();
            get_classes(len);
        }

        build_lcp();
    }

    int get_lcp(int i, int j) {
        i = c[i]; j = c[j];
        if (i > j) swap(i, j);
        return table.get_min(i, j - 1);
    }

private:
    void sort() {
        int mx = *max_element(c.begin(), c.end());
        vector<int> cnt(mx + 1, 0);

        for (int i = 0; i < n; i++)
            cnt[c[p[i]]]++;

        for (int i = 1; i <= mx; i++)
            cnt[i] += cnt[i - 1];

        vector<int> np(n);
        for (int i = n - 1; i >= 0; i--)
            np[--cnt[c[p[i]]]] = p[i];

        p.swap(np);
    }

    void get_classes(int len) {
        vector<int> nc(n, 0);
        for (int i = 1; i < n; i++)
            nc[p[i]] = c[p[i]] == c[p[i - 1]] && c[(p[i] + len) % n] == c[(p[i - 1] + len) % n] ? nc[p[i - 1]] : nc[p[i - 1]] + 1;

        c.swap(nc);
    }

    void build_lcp() {
        int pref = 0;
        lcp.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (c[i] + 1 >= n) {
                pref = 0;
                continue;
            }

            int nxt = p[c[i] + 1];
            while (text[i + pref] == text[nxt + pref]) pref++;

            lcp[c[i]] = pref;
            if (pref) pref--;
        }

        table = SparseTable(lcp);
    }
};

int largest_palindrome(SuffixArray &solver, int n, int i, int j) {
    if (i < 0 || j >= n) return 0;
    return solver.get_lcp(j, 2 * n - i);
}

int largest_quasi(SuffixArray &solver, int n, int i, int j) {
    int ans = largest_palindrome(solver, n, i, j);
    if (i - ans >= 0 && j + ans < n)
        ans += largest_palindrome(solver, n, i - ans - 1, j + ans + 1) + 1;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    SuffixArray solver;
    solver.add(s);

    reverse(s.begin(), s.end());
    solver.add(s);

    llong ans = 0LL;
    solver.build();

    for (int i = 0; i < n; i++) {
        ans += largest_quasi(solver, n, i, i);
        if (i) ans += largest_quasi(solver, n, i - 1, i);
    }

    cout << ans << "\n";
}