#include <bits/stdc++.h>

using namespace std;

int main() {
    int k; scanf("%d", &k);
    
    set<int> keys;
    for (int i = 0; i < k; i++) {
        int key; scanf("%d", &key);
        keys.insert(key);
    }

    int L; scanf("%d", &L);
    
    int num_days = 0;
    while (L--) {
        int lock; scanf("%d", &lock);
        if (keys.count(lock - 1) || keys.count(lock + 1)) num_days++;
    }

    printf("%d\n", num_days);
}