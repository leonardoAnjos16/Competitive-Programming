#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void merge(lli *left, int size_left, lli *right, int size_right, lli *both) {
    int indices[] = { 0, 0, 0 };
    while (indices[0] < size_left && indices[1] < size_right) {
        if (left[indices[0]] > right[indices[1]]) both[indices[2]++] = left[indices[0]++];
        else both[indices[2]++] = right[indices[1]++];
    }

    if (indices[0] >= size_left)
        for (int i = indices[1]; i < size_right; i++) both[indices[2]++] = right[i];
    else for (int i = indices[0]; i < size_left; i++) both[indices[2]++] = left[i];
}

void merge_sort(lli *prices, int size) {
    if (size > 1) {
        int half = size / 2;
        lli *left = new lli[half];
        for (int i = 0; i < half; i++) left[i] = prices[i];

        lli *right = new lli[size - half];
        for (int i = 0; i < size - half; i++) right[i] = prices[half + i];

        merge_sort(left, half);
        merge_sort(right, size - half);
        merge(left, half, right, size - half, prices);
    }
}

int main() {
    int size;
    scanf("%d", &size);

    lli *bars = new lli[size];
    lli sum = 0;

    for (int i = 0; i < size; i++) {
        scanf("%lld", &bars[i]);
        sum += bars[i];
    }

    merge_sort(bars, size);

    int numCoupons;
    scanf("%d", &numCoupons);

    for (int i = 0; i < numCoupons; i++) {
        int coupon;
        scanf("%d", &coupon);

        lli price = sum - bars[coupon - 1];
        printf("%lld\n", price);
    }
}