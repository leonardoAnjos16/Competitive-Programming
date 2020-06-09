#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e4 + 5;

int main() {
    int b, r = 1;
    scanf("%d", &b);

    while (b--) {
        int s; scanf("%d", &s);

        int n[MAX];
        for (int i = 1; i < s; i++)
            scanf("%d", &n[i]);

        pair<int, int> curr = {1, 1}, ans;
        int sum = 0, niceness = INT_MIN;

        for (int i = 1; i < s; i++) {
            sum += n[i]; curr.second++;
            
            if (sum > niceness) niceness = sum, ans = curr;
            else if (sum == niceness && curr.second - curr.first > ans.second - ans.first) ans = curr;

            if (sum < 0) sum = 0, curr.first = curr.second = i + 1;
        }

        if (niceness < 0) printf("Route %d has no nice parts\n", r++);
        else printf("The nicest part of route %d is between stops %d and %d\n", r++, ans.first, ans.second);
    }
}