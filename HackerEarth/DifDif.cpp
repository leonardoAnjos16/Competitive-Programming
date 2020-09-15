#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    string str; cin >> str;
    set<string> substrings;
    
    int size = 0;
    while (++size <= str.size())
        for (int i = 0; i <= str.size() - size; i++)
            substrings.insert(str.substr(i, size));
            
    printf("%d\n", (int) substrings.size());
}