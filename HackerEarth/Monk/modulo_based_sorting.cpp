#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10000
 
int modulo;
 
bool less_than(int a, int b) {
    return (a % modulo) <= (b % modulo);
}
 
void merge(int numbers[], int first_half[], int second_half[], int size) {
    int indices[3] = { 0, 0, 0 }, sizes[2];
    sizes[0] = size / 2;
    sizes[1] = size - sizes[0];
    
    while (indices[1] < sizes[0] && indices[2] < sizes[1]) {
        if (less_than(first_half[indices[1]], second_half[indices[2]]))
            numbers[indices[0]++] = first_half[indices[1]++];
        else
            numbers[indices[0]++] = second_half[indices[2]++];
    }
    
    if (indices[1] < sizes[0]) {
        for (int i = indices[1]; i < sizes[0]; i++)
            numbers[indices[0]++] = first_half[i];
    } else {
        for (int i = indices[2]; i < sizes[1]; i++)
            numbers[indices[0]++] = second_half[i];
    }
}
 
void merge_sort(int numbers[], int size) {
    if (size > 1) {
        int half = size / 2;
        
        int first_half[MAX], second_half[MAX];
        for (int i = 0; i < half; i++)
            first_half[i] = numbers[i];
            
        for (int i = half; i < size; i++)
            second_half[i - half] = numbers[i];
            
        merge_sort(first_half, half);
        merge_sort(second_half, size - half);
        merge(numbers, first_half, second_half, size);
    }
}
 
int main() {
    int size;
    scanf("%d %d", &size, &modulo);
    
    int numbers[MAX];
    for (int i = 0; i < size; i++)
        scanf("%d", &numbers[i]);
        
    merge_sort(numbers, size);
    for (int i = 0; i < size; i++)
        printf("%d ", numbers[i]);
}