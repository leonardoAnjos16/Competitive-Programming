#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5 + 5;

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
    }

    int count(string &s) {
        return find(s, 1) - find(s, 0);
    }

private:
    int comp(int suffix, string &s) {
        for (int i = 0; i < n - suffix - 1 && i < (int) s.size(); i++) {
            if (text[suffix + i] < s[i]) return -1;
            else if (text[suffix + i] > s[i]) return 1;
        }

        return n - suffix - 1 >= (int) s.size() ? 0 : -1;
    }

    int find(string &s, int v) {
        int l = 1, r = n - 1, ans = n;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (comp(p[mid], s) < v) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        return ans;
    }

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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t; cin >> t;

    SuffixArray solver;
    solver.add(t);
    solver.build();

    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        cout << solver.count(s) << "\n";
    }
}