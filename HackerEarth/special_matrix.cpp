#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 25;
 
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
 
        int x, y;
        for (int i = 0; i < n; i++) {
            char row[MAX]; scanf("%s", row);
            for (int j = 0; j < n; j++)
                if (row[j] == '*') x = i, y = j;
        }
 
        int mid = n / 2;
        int dist = abs(mid - x) + abs(mid - y);
 
        printf("%d\n", dist);
    }
}