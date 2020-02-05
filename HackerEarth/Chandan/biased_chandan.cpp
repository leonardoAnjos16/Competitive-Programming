#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int size; scanf("%d", &size);
    stack<int> ratings;
    int sum = 0;
    
    while (size--) {
        int rating; scanf("%d", &rating);
        if (rating) 
            sum += rating, ratings.push(rating);
        else if (!ratings.empty())
            sum -= ratings.top(), ratings.pop();
    }
    
    printf("%d\n", sum);
}