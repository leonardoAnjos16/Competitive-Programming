#include <bits/stdc++.h>

using namespace std;

#define MAX 100

typedef long long int ll;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        char path[MAX]; scanf("%s", path);
        int size = strlen(path);

        pair<ll, ll> left = {0, 1}, middle = {1, 1}, right = {1, 0};
        for (int i = 0; i < size; i++) {
            if (path[i] == 'L') right = middle;
            else left = middle;

            middle = {left.first + right.first, left.second + right.second};
        }

        printf("%lld/%lld\n", middle.first, middle.second);
    }
}