#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int L, N; scanf("%d %d", &L, &N);
    while (N--) {
        int W, H; scanf("%d %d", &W, &H);
        if (W < L || H < L) printf("UPLOAD ANOTHER\n");
        else if (W == H) printf("ACCEPTED\n");
        else printf("CROP IT\n");
    }
}