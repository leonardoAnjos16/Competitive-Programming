#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<set<int>> a(n);
    for (int i = 0; i < n; i++) {
        int m; cin >> m;

        while (m--) {
            int ai; cin >> ai;
            a[i].insert(ai);
        }
    }

    for (int i = 0; i < n; i++) {
        bool possible = true;
        for (int j = 0; j < n && possible; j++) {
            if (i == j) continue;

            possible = false;
            for (auto ai: a[j])
                if (!a[i].count(ai))
                    possible = true;
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}