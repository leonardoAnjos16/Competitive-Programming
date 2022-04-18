#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, n;
    cin >> C >> n;

    int last_stayed;
    long passengers = 0LL;
    bool possible = true;

    for (int i = 0; i < n; i++) {
        int left, entered, stayed;
        cin >> left >> entered >> stayed;

        if (passengers - left < 0LL) possible = false;
        passengers -= left;

        if (passengers + entered > C) possible = false;
        passengers += entered;

        if (passengers < C && stayed > 0) possible = false;
        last_stayed = stayed;
    }

    if (passengers > 0LL || last_stayed > 0) possible = false;
    cout << (possible ? "possible" : "impossible") << "\n";
}