#include <bits/stdc++.h>

using namespace std;

#define MAX 500005

int main() {
    int num_points;
    scanf("%d", &num_points);
    
    double total_dist = 0.0;
    for (int i = 0; i < num_points; i++) {
        int point; scanf("%d", &point);
        total_dist += (num_points - 1) * sin(point) * cos(point);
    }
            
    printf("%.2lf\n", total_dist);
}