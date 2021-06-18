#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n, l;
        cin >> n >> l;

        vector<string> sequences(n);
        for (int i = 0; i < n; i++)
            cin >> sequences[i];

        vector<string> states;
        for (int i = 0; i < l; i++) {
            string state = "";
            for (int j = 0; j < n; j++)
                state += sequences[j][i];

            states.push_back(state);
        }

        int index = 1;
        map<string, int> to_index;

        for (string state: states)
            if (!to_index.count(state))
                to_index[state] = index++;

        int s = to_index.size();
        cout << s << "\n";

        for (int i = 0; i < (int) states.size(); i++) {
            if (i) cout << " ";
            cout << to_index[states[i]];
        }

        cout << "\n";
    }
}