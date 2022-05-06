#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int books[3];
    for (int i = 0; i < 3; i++)
        cin >> books[i];

    int ans = INT_MAX;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) {
                int prices[3] = {0};
                prices[i] += books[0];
                prices[j] += books[1];
                prices[k] += books[2];

                int total = 0;
                for (int l = 0; l < 3; l++)
                    total += prices[l] >= 500 ? prices[l] - 100 : prices[l];

                ans = min(ans, total);
            }

    cout << ans << "\n";
}