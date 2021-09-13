#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, X;
        cin >> N >> X;

        map<int, int> cnt_all, cnt_xor;
        for (int i = 0; i < N; i++) {
            int A; cin >> A;
            int aux = A ^ X;

            cnt_all[A]++;
            if (A != aux) {
                cnt_all[aux]++;
                cnt_xor[aux]++;
            }
        }

        int mx = 1, mn = 0;
        for (auto p: cnt_all)
            if (p.second > mx || (p.second == mx && cnt_xor[p.first] < mn))
                mx = p.second, mn = cnt_xor[p.first];

        cout << mx << " " << mn << "\n";
    }
}