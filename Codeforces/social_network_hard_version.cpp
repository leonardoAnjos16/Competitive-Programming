#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    deque<int> ans;
    set<int> used;

    while (n--) {
        int id; cin >> id;

        if (used.count(id)) continue;
        else if ((int) ans.size() >= k) {
            used.erase(ans.back());
            ans.pop_back();
        }

        ans.push_front(id);
        used.insert(id);
    }

    cout << (int) ans.size() << "\n";
    for (int id: ans) cout << id << " ";
    cout << "\n";
}