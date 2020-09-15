#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100000
 
int binary_search(int numbers[], int size, int number) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        
        if (numbers[middle] == number) return middle;
        else if (numbers[middle] > number) right = middle - 1;
        else left = middle + 1;
    }
    
    return left;
}
 
int main() {
    int size;
    scanf("%d", &size);
    
    int numbers[MAX];
    for (int i = 0; i < size; i++)
        scanf("%d", &numbers[i]);
        
    sort(numbers, numbers + size);
    
    int num_queries;
    scanf("%d", &num_queries);
    
    for (int i = 0; i < num_queries; i++) {
        int type, number;
        scanf("%d %d", &type, &number);
        
        int pos = binary_search(numbers, size, number);
        if (type == 0)
            while (pos > 0 && numbers[pos - 1] == number) pos--;
        else
            while (pos < size && numbers[pos] == number) pos++;
        
        printf("%d\n", (size - pos));
    }
}