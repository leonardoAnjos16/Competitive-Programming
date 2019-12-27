#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100000
 
typedef long long int long_int;
 
int binary_search(double numbers[], int size, double number) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        
        if (numbers[middle] == number) {
            while (middle < size && numbers[middle] == number)
                middle++;
                
            return middle;
        } 
        
        if (numbers[middle] > number) right = middle - 1;
        else left = middle + 1;
    }
    
    return left;
}
 
int main() {
    int num_coords;
    scanf("%d", &num_coords);
    
    double coords[MAX];
    for (int i = 0; i < num_coords; i++) {
        long_int x_coord, y_coord;
        scanf("%lld %lld", &x_coord, &y_coord);
        
        x_coord *= x_coord;
        y_coord *= y_coord;
        
        coords[i] = sqrt(x_coord + y_coord);
    }
        
    int num_queries;
    scanf("%d", &num_queries);
    
    sort(coords, coords + num_coords);
    for (int i = 0; i < num_queries; i++) {
        long_int radius;
        scanf("%lld", &radius);
        
        int coords_within_radius = binary_search(coords, num_coords, radius);
        printf("%d\n", coords_within_radius);
    }
}