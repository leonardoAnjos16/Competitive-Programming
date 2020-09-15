#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int long_int;
 
vector<int> get_sum(vector<long_int> numbers, int size) {
    stack<int> left, right;
    left.push(size - 1);
    right.push(0);
    
    vector<int> former_greater(size), next_greater(size);
    for (int i = 1; i < size; i++) {
        while (!left.empty() && numbers[size - i - 1] > numbers[left.top()]) {
            former_greater[left.top()] = size - i;
            left.pop();
        }
        
        while (!right.empty() && numbers[i] > numbers[right.top()]) {
            next_greater[right.top()] = i + 1;
            right.pop();
        }
        
        left.push(size - i - 1);
        right.push(i);
    }
    
    while (!left.empty()) {
        former_greater[left.top()] = -1;
        left.pop();
    }
    
    while (!right.empty()) {
        next_greater[right.top()] = -1;
        right.pop();
    }
    
    vector<int> sum(size);
    for (int i = 0; i < size; i++)
        sum[i] = former_greater[i] + next_greater[i];
    
    return sum;
}
 
int main() {
    int size;
    scanf("%d", &size);
    
    vector<long_int> numbers(size);
    for (int i = 0; i < size; i++)
        scanf("%lld", &numbers[i]);
        
    vector<int> sum = get_sum(numbers, size);
    for (auto s: sum) {
        printf("%d ", s);
    }
}