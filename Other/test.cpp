#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

ldouble dist(ldouble x1, ldouble y1, ldouble x2, ldouble y2) {
    ldouble dx = x2 - x1, dy = y2 - y1;
    return sqrtl(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
        cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
        
        int dABx = Bx - Ax, dABy = By - Ay;
        int dCDx = Dx - Cx, dCDy = Dy - Cy;
        
        ldouble l = 0.0L, r = 1.0L;
        for (int i = 0; i < 100; i++) {
            ldouble m1 = l + (r - l) / 3.0L;
            ldouble m2 = r - (r - l) / 3.0L;
            
            ldouble d1 = dist(Ax + m1 * dABx, Ay + m1 * dABy, Cx + m1 * dCDx, Cy + m1 * dCDy);
            ldouble d2 = dist(Ax + m2 * dABx, Ay + m2 * dABy, Cx + m2 * dCDx, Cy + m2 * dCDy);
            
            if (d1 > d2) l = m1;
            else r = m2;
        }
        
        ldouble ans = dist(Ax + l * dABx, Ay + l * dABy, Cx + l * dCDx, Cy + l * dCDy);
        cout << ans << "\n";
    }
}