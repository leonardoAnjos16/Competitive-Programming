#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        multiset<int> even, odd;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (a & 1) odd.insert(a);
            else even.insert(a);
        }


        int num_even = even.size();
        int num_odd = odd.size();

        if (!(num_even & 1) && !(num_odd & 1)) printf("YES\n");
        else {
            bool possible = false;
            for (auto it = odd.begin(); it != odd.end() && !possible; it++)
                if (even.count(*it - 1) || even.count(*it + 1))
                    possible = true;

            printf("%s\n", possible ? "YES" : "NO");
        }
    }
}