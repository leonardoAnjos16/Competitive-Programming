#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int n, k;
vector<string> s;
vector<int> memo, nxt;

int width(int i = 0) {
    if (i >= n) return -1;

    int &ans = memo[i];
    if (~ans) return ans;

    int mx = 0;
    ans = INF;

    for (int j = 0; j < k && i + j < n; j++) {
        mx = max(mx, (int) s[i + j].size());

        int aux = width(i + j + 1) + mx + 1;
        if (aux < ans) {
            ans = aux;
            nxt[i] = j;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w;
    cin >> n >> w;

    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<int> sizes;
    int l = 1, r = n, rows = -1;

    while (l <= r) {
        int mid = (l + r) / 2;

        k = mid;
        memo.assign(n + 5, -1);
        nxt.assign(n + 5, -1);

        if (width() > w) l = mid + 1;
        else r = mid - 1, rows = mid, sizes = nxt;
    }

    int idx = 0;
    vector<int> a;
    vector<vector<string>> ans;

    while (idx < n) {
        int mx = 0;
        vector<string> curr;

        for (int i = 0; i <= sizes[idx]; i++) {
            curr.push_back(s[idx + i]);
            mx = max(mx, (int) s[idx + i].size());
        }

        a.push_back(mx);
        ans.push_back(curr);
        idx += sizes[idx] + 1;
    }

    int cols = ans.size();
    cout << rows << " " << cols << "\n";

    for (int i = 0; i < cols; i++) {
        if (i) cout << " ";
        cout << a[i];
    }

    cout << "\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            string file = i < (int) ans[j].size() ? ans[j][i] : "";
            file += string(a[j] - (int) file.size(), ' ');
            cout << file << " ";
        }

        cout << "\n";
    }
}