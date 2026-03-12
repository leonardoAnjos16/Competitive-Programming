#include <bits/stdc++.h>

using namespace std;

int to_int(string s) {
    int ans = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        ans <<= 1;
        if (s[i] == '1')
            ans++;
    }

    return ans;
}

bool is_divisible(string M, string N) {
    reverse(N.begin(), N.end());
    while (N.back() == '0') N.pop_back();
    reverse(N.begin(), N.end());

    int idx = 0, msz = M.size(), nsz = N.size(), divisor = to_int(N);
    while (idx < msz) {
        while (idx < msz && M[idx] == '0') idx++;

        if (idx >= msz) return true;
        if (msz - idx < nsz) return false;

        int diff = to_int(M.substr(idx, nsz)) - divisor;
        if (diff >= 0) {
            for (int i = 0; i < nsz; i++) {
                int cidx = idx + nsz - i - 1;
                M[cidx] = diff & (1 << i) ? '1' : '0';
            }
        } else {
            if (msz - idx < nsz + 1) return false;

            diff = to_int(M.substr(idx, nsz + 1)) - divisor;
            for (int i = 0; i < nsz + 1; i++) {
                int cidx = idx + nsz - i;
                M[cidx] = diff & (1 << i) ? '1' : '0';
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string M, N;
    cin >> M >> N;

    vector<int> mindices;
    for (int i = 0; i < (int) M.size(); i++)
        if (M[i] == '*') mindices.push_back(i);

    vector<int> nindices;
    for (int i = 0; i < (int) N.size(); i++)
        if (N[i] == '*') nindices.push_back(i);

    string ans = "";
    bool found = false;
    int mcnt = mindices.size(), ncnt = nindices.size();

    for (int i = 0; i < (1 << mcnt) && !found; i++) {
        string curr_M = M;
        for (int j = 0; j < mcnt; j++)
            curr_M[mindices[j]] = i & (1 << j) ? '1' : '0';

        for (int j = 0; j < (1 << ncnt) && !found; j++) {
            string curr_N = N;
            for (int k = 0; k < ncnt; k++)
                curr_N[nindices[k]] = j & (1 << k) ? '1' : '0';

            if (is_divisible(curr_M, curr_N)) {
                found = true;
                ans = curr_M;
            }
        }
    }

    if (found) cout << ans << "\n";
    else {
        assert(mindices.empty());
        cout << M << "\n";
    }
}