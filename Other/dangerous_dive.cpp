#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R;
    cin >> N >> R;

    vector<bool> returned(N);
    for (int i = 0; i < R; i++) {
        int id; cin >> id;
        returned[id - 1] = true;
    }

    vector<int> ans;
    for (int i = 0; i < N; i++)
        if (!returned[i])
            ans.push_back(i + 1);

    int size = ans.size();
    if (!size) cout << "*\n";
    else {
        for (int i = 0; i < size; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}