#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

typedef long long int ll;

int main() {
    int size;
    scanf("%d", &size);

    ll times[MAX];
    for (int i = 0; i < size; i++)
        scanf("%lld", &times[i]);

    sort(times, times + size);
    int counter = 0;

    ll sum = 0;
    for (int i = 0; i < size; i++) {
        if (sum > times[i]) counter++;
        else sum += times[i];
    }

    printf("%d\n", size - counter);
}