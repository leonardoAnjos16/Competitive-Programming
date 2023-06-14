#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int q; cin >> q;

        vector<int> A;
        bool na = false;

        while (q--) {
            int x; cin >> x;

            if (A.empty() || (!na && x >= A.back())) {
                cout << "1";
                A.push_back(x);
            } else if (!na && x <= A[0]) {
                cout << "1";
                A.push_back(x);
                na = true;
            } else if (na && x >= A.back() && x <= A[0]) {
                cout << "1";
                A.push_back(x);
            } else {
                cout << "0";
            }
        }

        cout << "\n";
    }
}