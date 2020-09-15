#include <bits/stdc++.h>
 
using namespace std;
 
bool diff(int h, int m, int s) {
    if (!h || !m || !s) return false;
 
    bitset<10> used;
 
    if (h < 10) used[0] = true;
    while (h) {
        int d = h % 10;
        if (used[d]) return false;
 
        used[d] = true;
        h /= 10;
    }
 
    if (m < 10) {
        if (used[0]) return false;
        used[0] = true;
    }
 
    while (m) {
        int d = m % 10;
        if (used[d]) return false;
 
        used[d] = true;
        m /= 10;
    }
 
    if (s < 10) {
        if (used[0]) return false;
        used[0] = true;
    }
 
    while (s) {
        int d = s % 10;
        if (used[d]) return false;
 
        used[d] = true;
        s /= 10;
    }
 
    return true;
}
 
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int h, m, s; scanf("%d:%d:%d", &h, &m, &s);
        while (!diff(h, m, s)) {
            if (++s >= 60) {
                s = 0;
                if (++m >= 60) {
                    m = 00;
                    if (++h >= 24)
                        h = 0;
                }
            }
        }
 
        printf("%02d:%02d:%02d\n", h, m, s);
    }
}