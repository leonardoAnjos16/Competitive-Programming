#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<int> ask(string s) {
    cout << "? " << s << "\n";
    cout.flush();

    int n; cin >> n;

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        cin >> ans[i];

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = ask("abcdefghijklmnopqrstuvwxyz").size();

    vector<int> queries[5];
    for (int i = 0; i < 5; i++) {
        string s = "";
        for (int j = 0; j < 26; j++)
            if (j & (1 << i)) {
                char c = 'a' + j;
                s += c;
            }

        queries[i] = ask(s);
    }

    string ans(n, '-');
    for (int i = 0; i < 26; i++) {
        vector<bool> indices(n, true);
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < n; k++) {
                bool in = binary_search(queries[j].begin(), queries[j].end(), k + 1);
                if ((i & (1 << j)) && !in) indices[k] = false;
                else if (!(i & (1 << j)) && in) indices[k] = false;
            }

        for (int j = 0; j < n; j++)
            if (indices[j]) {
                char c = 'a' + i;
                ans[j] = c;
            }
    }

    cout << "! " << ans << "\n";
    cout.flush();
}