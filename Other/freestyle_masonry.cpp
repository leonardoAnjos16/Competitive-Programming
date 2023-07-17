#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h;
    cin >> w >> h;

    vector<int> heights(w);
    for (int i = 0; i < w; i++)
        cin >> heights[i];

    int lowest = h;
    bool possible = true;

    for (int i = 0; i < w && possible; i++) {
        if (heights[i] > h || lowest < heights[i]) possible = false;

        int between = lowest - heights[i];
        if (between & 1) lowest--;
        else lowest = min(lowest + 1, h);
    }

    if (lowest < h) possible = false;
    cout << (possible ? "possible" : "impossible") << "\n";
}