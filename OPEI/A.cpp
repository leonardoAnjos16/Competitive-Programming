#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string W; cin >> W;
    int N = W.size();
    
    bool palindrome = true;
    for (int i = 0, j = (int) W.size() - 1; i < j && palindrome; i++, j--)
        if (W[i] != W[j]) palindrome = false;

    bool valid = (N & 1) && palindrome;
    valid &= W[0] == W[N / 2] && W[N / 2] == W[N - 1];

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += W[i] - '0';

    valid &= 3 * (W[0] - '0') > sum - 3 * (W[0] - '0');
    cout << (valid ? "printing" : "bubblegum dog error") << "\n";
}