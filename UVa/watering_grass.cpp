#include <bits/stdc++.h>

using namespace std;

#define seg pair<double, double>
#define L first
#define R second

int main() {
    int n; double l, w;
    while (scanf("%d %lf %lf", &n, &l, &w) != EOF) {
        vector<seg> segs;
        for (int i = 0; i < n; i++) {
            double x, r; scanf("%lf %lf", &x, &r);

            if (r >= w / 2) {
                double ext = sqrt(r * r - w * w / 4);
                segs.push_back({x - ext, x + ext});
            }
        }

        n = segs.size();
        sort(segs.begin(), segs.end());

        double covered = 0.0;
        int idx = 0, ans = 0;

        while (idx < n) {
            double max_r = covered;
            while (idx < n && segs[idx].L <= covered)
                max_r = max(max_r, segs[idx++].R);

            if (max_r == covered) break;
            else {
                covered = max_r; ans++;
                if (covered >= l) break;
            }
        }

        if (covered < l) printf("-1\n");
        else printf("%d\n", ans);
    }
}