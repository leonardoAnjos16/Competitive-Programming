#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct RabinKarp {
private:
    string s;
    int n, base, mod;
    vector<long> p, h;

public:
    RabinKarp(string &s, int base = 243, int mod = 1e9 + 7) {
        this->s = s;
        this->n = s.size();

        this->base = base;
        this->mod = mod;

        build();
    }

    RabinKarp(int n, string &s, int base = 243, int mod = 1e9 + 7) {
        this->s = s;
        this->n = n;

        this->base = base;
        this->mod = mod;

        build();
    }

    int hash(int l, int r) {
        if (!l) return h[r];
        return (h[r] - ((h[l - 1] * p[r - l + 1]) % mod) + mod) % mod;
    }

private:
    void build() {
        p.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            p[i] = (p[i - 1] * base) % mod;

        h.assign(n, s[0]);
        for (int i = 1; i < n; i++)
            h[i] = (h[i - 1] * base + s[i]) % mod;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<pair<int, int>> lists(N);
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            int n = s.size();
            lists[i].first = RabinKarp(n, s).hash(0, n - 1);
        }

        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            int n = s.size();
            lists[i].second = RabinKarp(n, s).hash(0, n - 1);
        }

        int cnt = 0;
        set<int> aux;

        vector<int> ans;
        for (int i = 0; i < N; i++) {
            cnt++;
            if (!aux.count(lists[i].first)) aux.insert(lists[i].first);
            else aux.erase(lists[i].first);

            if (!aux.count(lists[i].second)) aux.insert(lists[i].second);
            else aux.erase(lists[i].second);

            if (aux.empty()) {
                ans.push_back(cnt);
                cnt = 0;
            }
        }

        for (int i = 0; i < (int) ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}