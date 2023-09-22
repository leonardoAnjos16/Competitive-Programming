struct SuffixArray {
private:
    const int SEP = 300;

    int n, m, sep, text[MAX];
    vector<int> p, c, lcp, pstart, ps;
    SparseTable table;

public:
    SuffixArray(string &s) {
        n = 0;
        sep = SEP;
        m = s.size();
        add(s);
    }

    void add(string &s) {
        if (n) {
            text[n++] = sep++;
            pstart.push_back(n);
        }

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

        ps.assign(n, 0);
        ps[0] = p[0] < m;

        for (int i = 1; i < n; i++)
            ps[i] = ps[i - 1] + (p[i] < m);

        build_lcp();
    }

    int matches(int l, int r, int pattern = 0) {
        int sz = r - l + 1;
        int idx = c[pstart[pattern] + l];

        l = idx - max_equal(1, idx, [&](int mid) {
            return table.get_min(idx - mid, idx - 1) >= sz;
        });

        r = idx + max_equal(1, n - idx - 1, [&](int mid) {
            return table.get_min(idx, idx + mid - 1) >= sz;
        });

        assert(l);
        return ps[r] - ps[l - 1];
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
        lcp.assign(n - 1, 0);

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

    int max_equal(int l, int r, function<bool(int)> check) {
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (!check(mid)) r = mid - 1;
            else l = mid + 1, ans = mid;
        }

        return ans;
    }
};