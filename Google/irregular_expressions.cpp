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

bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string S; cin >> S;
        int N = S.size();

        vector<int> vowels(N + 1, 0);
        for (int i = 1; i <= N; i++)
            vowels[i] = vowels[i - 1] + vowel(S[i - 1]);

        RabinKarp hasher(N, S);

        bool possible = false;
        for (int i = 0; i < N && !possible; i++)
            for (int j = i + 4; j < N && !possible; j++)
                for (int k = 2; k <= (j - i) / 2 && !possible; k++)
                    if (vowels[i + k] - vowels[i] >= 2 && vowels[j - k + 1] - vowels[i + k] >= 1)
                        if (hasher.hash(i, i + k - 1) == hasher.hash(j - k + 1, j))
                            possible = true;

        cout << "Case #" << t << ": " << (possible ? "Spell!" : "Nothing.") << "\n";
    }
}