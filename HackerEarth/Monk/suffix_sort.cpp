#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100
 
int main() {
    string letters;
    int k;
    
    cin >> letters >> k;
    int size = letters.size();
    
    string suffices[MAX];
    for (int i = 0; i < size; i++)
        suffices[i] = letters.substr(i);
        
    sort(suffices, suffices + size);
    cout << suffices[k - 1] << endl;
}