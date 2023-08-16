#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 4e5 + 5;

struct SuffixArray {
private:
    const int SEP = 300;

    int n, sep, text[MAX];
    vector<int> p, c, lcp;

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

    llong count_substrings() {
        llong ans = 0LL;
        for (int i = 1; i < n; i++)
            ans += n - p[i] - lcp[i - 1] - 1;

        return ans;
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
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    SuffixArray solver;
    solver.add(s);
    solver.build();

    llong ans = solver.count_substrings();
    cout << ans << "\n";
}