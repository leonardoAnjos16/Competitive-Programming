#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        multiset<int> A;
        for (int i = 0; i < n; i++) {
            int Ai; cin >> Ai;
            A.insert(Ai);
        }

        multiset<int> B;
        for (int i = 0; i < n; i++) {
            int Bi; cin >> Bi;
            B.insert(Bi);
        }

        vector<int> rem_A;
        for (int a: A) {
            auto it = B.lower_bound(a);
            if (it != B.end() && *it == a)
                B.erase(it);
            else
                rem_A.push_back(a);
        }

        int rem = B.size();
        if (rem > 1) cout << "NO\n";
        else if (rem == 1 && abs(rem_A[0] - *B.begin()) > k) cout << "NO\n";
        else cout << "YES\n";
    }
}