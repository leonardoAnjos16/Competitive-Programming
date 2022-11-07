#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    vector<int> x(n);
    vector<bool> seen(n + 1, false);
    
    map<int, int> indices;
    indices[n + 1] = n + 1;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (!seen[x[i] - 1]) ans++;
        indices[x[i]] = i + 1;
        seen[x[i]] = true;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        int va = x[a - 1];
        bool aa = indices[va] > indices[va - 1];
        bool ba = indices[va] < indices[va + 1];

        int vb = x[b - 1];
        bool ab = indices[vb] > indices[vb - 1];
        bool bb = indices[vb] < indices[vb + 1];

        indices[va] = b;
        indices[vb] = a;
        swap(x[a - 1], x[b - 1]);

        if (aa && indices[va] < indices[va - 1]) ans++;
        else if (!aa && indices[va] > indices[va - 1]) ans--;

        if (ba && indices[va] > indices[va + 1]) ans++;
        else if (!ba && indices[va] < indices[va + 1]) ans--;

        if (vb != va + 1) {
            if (ab && indices[vb] < indices[vb - 1]) ans++;
            else if (!ab && indices[vb] > indices[vb - 1]) ans--;
        }

        if (va != vb + 1) {
            if (bb && indices[vb] > indices[vb + 1]) ans++;
            else if (!bb && indices[vb] < indices[vb + 1]) ans--;
        }

        cout << ans << "\n";
    }
}