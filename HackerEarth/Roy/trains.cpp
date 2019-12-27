#include <bits/stdc++.h>
 
using namespace std;
 
int ceiling(double number) {
    int result = (int) number;
    if (result < number) return (result + 1);
    else return result;
}
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int to_station, time_1, time_2, speed_1, speed_2, distance;
        scanf("%d %d %d %d %d %d", &to_station, &time_1, &time_2, &speed_1, &speed_2, &distance);
        
        if (time_1 < to_station && time_2 < to_station) printf("-1\n");
        else {
            double to_city_1 = ((double) distance) / speed_1;
            double to_city_2 = ((double) distance) / speed_2;
            
            int min_to_city_1 = ceiling(to_city_1 * 60);
            int min_to_city_2 = ceiling(to_city_2 * 60);
            
            if (time_1 < to_station) printf("%d\n", time_2 + min_to_city_2);
            else if (time_2 < to_station) printf("%d\n", time_1 + min_to_city_1);
            else printf("%d\n", min(time_1 + min_to_city_1, time_2 + min_to_city_2));
        }
    }
}