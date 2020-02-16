#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<ii> order;

bool comp(int a, int b) {
    return order[a - 1] <= order[b - 1];
}

int main() {
    int num_queries;
    scanf("%d", &num_queries);
    
    int x1, y1, x2, y2;
    for (int i = 0; i < num_queries; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        order.push_back({x1 + y1 + x2 + y2, i + 1});
    }
        
    sort(order.begin(), order.end());
    for (int i = 0; i < num_queries; i++)
        printf("%d ", order[i].second);
        
    printf("\n");
}