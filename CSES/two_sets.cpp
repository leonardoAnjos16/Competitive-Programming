#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    long long int sum = n * (n + 1LL) / 2LL;
    if (sum & 1LL) cout << "NO\n";
    else {
        cout << "YES\n";

        int v = n;
        long long int curr = 0LL;

        vector<int> first;
        while (sum / 2LL - curr >= v) {
            curr += v;
            first.push_back(v--);
        }

        if (sum / 2LL - curr)
            first.push_back(sum / 2LL - curr);

        vector<int> second;
        while (v) {
            if (v == sum / 2LL - curr) v--;
            else second.push_back(v--);
        }

        int size = first.size();
        cout << size << "\n";

        for (int i = 0; i < size; i++) {
            if (i) cout << " ";
            cout << first[i];
        }

        size = second.size();
        cout << "\n" << size << "\n";

        for (int i = 0; i < size; i++) {
            if (i) cout << " ";
            cout << second[i];
        }

        cout << "\n";
    }
}