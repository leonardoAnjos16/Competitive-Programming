#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    bool friends[5][5] = {0};
    while (n--) {
        int a, b;
        cin >> a >> b;
        friends[a - 1][b - 1] = friends[b - 1][a - 1] = true;
    }

    bool possible = false;
    for (int i = 0; i < (1 << 5) && !possible; i++) {
        vector<int> dogs;
        for (int j = 0; j < 5; j++)
            if (i & (1 << j)) dogs.push_back(j);

        if ((int) dogs.size() != 3) continue;

        possible = true;
        for (int j = 0; j < 3 && possible; j++)
            for (int k = j + 1; k < 3 && possible; k++)
                if (!friends[dogs[j]][dogs[k]]) possible = false;

        if (!possible) {
            possible = true;
            for (int j = 0; j < 3 && possible; j++)
                for (int k = j + 1; k < 3 && possible; k++)
                    if (friends[dogs[j]][dogs[k]]) possible = false;
        }
    }

    cout << (possible ? "Happy Doggos!" : "Sad Doggos...") << "\n";
}