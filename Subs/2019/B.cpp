#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int max_ = 0;
    cin >> max_;

    for(int i = 1; i < N; i++){
        int a;
        cin >> a;
        if(a > max_){
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";

    return 0;
}