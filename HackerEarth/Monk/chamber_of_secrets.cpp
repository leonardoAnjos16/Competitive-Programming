#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100000
 
int main() {
    int num_spiders, num_selected;
    scanf("%d %d", &num_spiders, &num_selected);
    
    queue< pair<int, int> > spiders;
    for (int i = 0; i < num_spiders; i++) {
        int power;
        scanf("%d", &power);
        
        spiders.push({power, i + 1});
    }
    
    for (int i = 0; i < num_selected; i++) {
        int num_removed = num_selected;
        if (spiders.size() < num_selected) num_removed = spiders.size();
        
        queue< pair<int, int> > removed;
        pair<int, int> greatest = {INT_MIN, -1};
        
        for (int j = 0; j < num_removed; j++) {
            pair<int, int> front = spiders.front();
            spiders.pop();
            
            removed.push(front);
            if (front.first > greatest.first) greatest = front;
        }
        
        printf("%d ", greatest.second);
        for (int j = 0; j < num_removed; j++) {
            pair<int, int> front = removed.front();
            removed.pop();
            
            if (front.second != greatest.second)
                spiders.push({max(front.first - 1, 0), front.second});
        }
    }
}