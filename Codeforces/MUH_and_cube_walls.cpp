#include <bits/stdc++.h>

using namespace std;

#define llong long long int

template<typename T>
struct KMP {
private:
    int n;
    T pattern;
    vector<int> border;

public:
    KMP(T pattern) {
        n = pattern.size();
        this->pattern = pattern;
        get_border();
    }

    vector<int> get_matches(T text) {
        vector<int> matches;
        int m = text.size(), last = 0;

        for (int i = 0; i < m; i++) {
            int j = last;
            while (j > 0 && (j >= n || pattern[j] != text[i]))
                j = border[j - 1];

            last = j < n && pattern[j] == text[i] ? j + 1 : 0;
            if (last == n) matches.push_back(i);
        }

        return matches;
    }

private:
    void get_border() {
        border.assign(n, 0);
        for (int i = 1; i < n; i++) {
            int j = border[i - 1];
            while (j > 0 && pattern[j] != pattern[i])
                j = border[j - 1];

            if (pattern[j] == pattern[i])
                border[i] = j + 1;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w;
    cin >> n >> w;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b(w);
    for (int i = 0; i < w; i++)
        cin >> b[i];

    if (w == 1) {
        cout << n << "\n";
        return 0;
    }

    vector<int> da(n - 1);
    for (int i = 1; i < n; i++)
        da[i - 1] = a[i] - a[i - 1];

    vector<int> db(w - 1);
    for (int i = 1; i < w; i++)
        db[i - 1] = b[i] - b[i - 1];

    KMP<vector<int>> solver(db);
    int ans = solver.get_matches(da).size();
    cout << ans << "\n";
}