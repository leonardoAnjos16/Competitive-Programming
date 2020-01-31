#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000005
 
int main() {
    int size; double prob;
    double probs[MAX] = { 0.0 };
    
    scanf("%d %lf", &size, &prob);
    prob /= 100;
    
    probs[0] = 1.0;
    for (int i = 0; i < size; i++) {
        probs[i + 2] += probs[i] * prob;
        probs[i + 3] += probs[i] * (1 - prob);
    }
    
    printf("%.6lf\n", probs[size]);
}