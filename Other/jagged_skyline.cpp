#include <bits/stdc++.h>

using namespace std;

#define llong long long int

bool building(int x, llong y) {
    cout << "? " << x << " " << y << "\n";
    cout.flush();

    string type; cin >> type;
    return type == "building";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(NULL));

    int w; llong h;
    cin >> w >> h;

    vector<int> indices(w);
    for (int i = 0; i < w; i++)
        indices[i] = i + 1;

    random_shuffle(indices.begin(), indices.end());

    int x = 1;
    llong y = 0LL;

    for (int i = 0; i < w && y < h; i++) {
        bool greater = building(indices[i], y + 1LL);
        if (greater) {
            llong l = y + 1LL, r = h;
            while (l <= r) {
                llong mid = (l + r) / 2LL;
                if (!building(indices[i], mid)) r = mid - 1LL;
                else l = mid + 1LL, y = mid;
            }

            x = indices[i];
        }
    }

    cout << "! " << x << " " << y << "\n";
    cout.flush();
}