#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        set<int> blocked;
        map<int, set<pair<char, int>>> locks;

        char mode;
        while (cin >> mode, mode != '#') {
            int transaction, data;
            cin >> transaction >> data;

            if (blocked.count(transaction)) cout << "IGNORED\n";
            else if (!locks.count(data)) {
                cout << "GRANTED\n";
                set<pair<char, int>> new_locks;
                new_locks.insert({ mode, transaction });
                locks[data] = new_locks;
            } else {
                bool conflict = false;
                for (auto lock: locks[data])
                    if (lock.second != transaction && (lock.first == 'X' || mode == 'X'))
                        conflict = true;

                if (conflict) {
                    cout << "DENIED\n";
                    blocked.insert(transaction);
                } else {
                    cout << "GRANTED\n";
                    locks[data].insert({ mode, transaction });
                }
            }
        }

        if (t) cout << "\n";
    }
}