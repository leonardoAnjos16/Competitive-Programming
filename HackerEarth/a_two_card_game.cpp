#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int main() {
    int n; scanf("%d", &n);
    
    int numbers[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);
        
    sort(numbers, numbers + n);
    
    double prob = 0.0;
    int last = 0;
    
    for (int i = 1; i < n; i++) {
        if (numbers[i] != numbers[last]) {
            prob += (i + .0) / (n - 1);
            last = i;
        } else prob += (last + .0) / (n - 1);
    }
    
    prob *= 1.0 / n;
    printf("%lf %lf\n", prob, prob);
}