#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define heap(ds, cmp) priority_queue<ds, vector<ds>, cmp>

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S; cin >> S;
    if (size(S) < 3) {
        if (stoi(S) % 8 == 0) cout << "Yes\n";
        else if (reverse(all(S)), stoi(S) % 8) cout << "No\n";
        else cout << "Yes\n";
        return 0;
    }

    vector<string> mults;
    for (int i = 100; i < 1000; i++)
        if (i % 8 == 0) mults.push_back(to_string(i));

    int cnt[10] = {0};
    for (char c: S) cnt[c - '0']++;

    for (string mult: mults) {
        int aux[10] = {0};
        for (char c: mult) aux[c - '0']++;

        bool possible = true;
        for (int i = 0; i < 10 && possible; i++)
            if (aux[i] > cnt[i]) possible = false;

        if (possible) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
}