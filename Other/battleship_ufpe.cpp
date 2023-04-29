#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int count(ordered_set &s, int l, int r) {
    return s.order_of_key(r) - s.order_of_key(l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;

    map<int, ordered_set> rows, cols;
    while (Q--) {
        int type, x, y, size; char ship;
        cin >> type >> ship >> x >> y >> size;

        if (type == 1) {
            if (ship == 'L') {
                if (count(rows[y], x, x + size)) {
                    cout << "-1\n";
                    continue;
                }

                for (int i = 0; i < size; i++) {
                    rows[y].insert(x + i);
                    cols[x + i].insert(y);
                }
            } else {
                if (count(cols[x], y, y + size)) {
                    cout << "-1\n";
                    continue;
                }

                for (int i = 0; i < size; i++) {
                    rows[y + i].insert(x);
                    cols[x].insert(y + i);
                }
            }
        } else {
            if (ship == 'L') {
                int ans = count(rows[y], x, x + size);
                cout << ans << "\n";
            } else {
                int ans = count(cols[x], y, y + size);
                cout << ans << "\n";
            }
        }
    }
}