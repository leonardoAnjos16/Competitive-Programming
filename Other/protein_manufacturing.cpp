#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

struct SparseTable {
private:
    int n;
    vector<vector<int>> table;

public:
    SparseTable() {}
    SparseTable(vector<int> &a) {
        n = a.size();
        table.assign(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            table[0][i] = a[i];

        for (int i = 1; i < LOG; i++) {
            int jump = 1 << (i - 1);
            for (int j = 0; j < n; j++) {
                table[i][j] = table[i - 1][j];
                if (j + jump < n)
                    table[i][j] = min(table[i][j], table[i - 1][j + jump]);
            }
        }
    }

    int get_min(int l, int r) {
        int idx = __lg(r - l + 1), jump = 1 << idx;
        return min(table[idx][l], table[idx][r - jump + 1]);
    }
};

struct SuffixArray {
private:
    int n, m;
    string text;
    vector<int> pstart;
    vector<int> rank, suffixes, lcp;
    SparseTable table;
    vector<int> ps;

public:
    SuffixArray(string text): text(text), m(text.size()) {}

    void add_pattern(string pattern) {
        n = text.size();
        text += "|" + pattern;
        pstart.push_back(n + 1);
    }

    void build() {
        text += '$';
        n = text.size();

        vector<pair<char, int>> letters(n);
        for (int i = 0; i < n; i++)
            letters[i] = make_pair(text[i], i);

        sort(letters.begin(), letters.end());

        int idx = 0;
        rank.resize(n);
        suffixes.resize(n);

        for (int i = 0; i < n; i++) {
            if (i && letters[i].first > letters[i - 1].first) idx++;
            suffixes[i] = letters[i].second;
            rank[suffixes[i]] = idx;
        }

        for (int p = 1; p < 2 * n; p <<= 1) {
            idx = -1;
            int end = 0;
            vector<int> nrank(n);

            while (end < n) {
                int begin = end++;
                while (end < n && rank[suffixes[end]] == rank[suffixes[end - 1]]) end++;

                vector<pair<int, int>> order(end - begin);
                for (int i = begin; i < end; i++)
                    order[i - begin] = make_pair(rank[(suffixes[i] + p) % n], suffixes[i]);

                sort(order.begin(), order.end());
                for (int i = begin; i < end; i++) {
                    if (i == begin || order[i - begin].first > order[i - begin - 1].first) idx++;
                    suffixes[i] = order[i - begin].second;
                    nrank[suffixes[i]] = idx;
                }
            }

            rank = nrank;
        }

        for (int i = 1; i < n; i++)
            assert(rank[suffixes[i]] > rank[suffixes[i - 1]]);

        ps.assign(n, 0);
        ps[0] = suffixes[0] < m;

        for (int i = 1; i < n; i++)
            ps[i] = ps[i - 1] + (suffixes[i] < m);

        build_lcp();
    }

    int matches(int l, int r, int pattern = 0) {
        int sz = r - l + 1;
        int idx = rank[pstart[pattern] + l];

        l = idx;
        int lo = 1, hi = idx;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (table.get_min(idx - mid, idx - 1) < sz) hi = mid - 1;
            else lo = mid + 1, l = idx - mid;
        }

        r = idx;
        lo = 1; hi = n - idx - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (table.get_min(idx, idx + mid - 1) < sz) hi = mid - 1;
            else lo = mid + 1, r = idx + mid;
        }

        assert(l);
        return ps[r] - ps[l - 1];
    }

private:
    void build_lcp() {
        int pref = 0;
        lcp.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (rank[i] + 1 >= n) {
                pref = 0;
                continue;
            }

            int nxt = suffixes[rank[i] + 1];
            while (text[i + pref] == text[nxt + pref]) pref++;

            lcp[rank[i]] = pref;
            if (pref) pref--;
        }

        table = SparseTable(lcp);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string S; cin >> S;
    SuffixArray sa(S);

    string T; cin >> T;
    sa.add_pattern(T);

    sa.build();

    int Q; cin >> Q;
    while (Q--) {
        int A, B;
        cin >> A >> B;

        int ans = sa.matches(A - 1, B - 1);
        cout << ans << "\n";
    }
}