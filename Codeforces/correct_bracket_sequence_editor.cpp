#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 5e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;

    string s; cin >> s;

    set<int> indices;
    stack<pair<char, int>> aux;

    int matches[MAX];
    for (int i = 0; i < size(s); i++) {
        indices.insert(i);
        if (s[i] == '(') aux.push({ s[i], i });
        else {
            matches[aux.top().second] = i;
            matches[i] = aux.top().second;
            aux.pop();
        }
    }

    auto it = indices.begin();
    while (--p) it++;

    string ops; cin >> ops;
    for (auto c: ops) {
        if (c == 'L') it--;
        else if (c == 'R') it++;
        else {
            int first = *it, last = matches[*it];
            if (first > last) swap(first, last);

            indices.erase(indices.lower_bound(first), indices.upper_bound(last));

            it = indices.upper_bound(last);
            if (it == indices.end())
                it = indices.lower_bound(first), it--;
        }
    }

    for (auto idx: indices)
        cout << s[idx];

    cout << "\n";
}