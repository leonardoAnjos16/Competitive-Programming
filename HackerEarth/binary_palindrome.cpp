#include <bits/stdc++.h>

using namespace std;

#define long long long int

int reverse(int n) {
    int ans = 0;
    while (n) {
        ans <<= 1;
        ans |= (n & 1);
        n >>= 1;
    }

    return ans;
}

vector<int> get_palindromes() {
    vector<int> palindromes;
    palindromes.push_back(0);
    palindromes.push_back(1);

    for (int i = 1; i < 16; i++) {
        for (int j = 1 << (i - 1); j < (1 << i); j++) {
            int rev = reverse(j);
            palindromes.push_back((j << i) | rev);
            palindromes.push_back((j << (i + 1)) | rev);
            palindromes.push_back((((j << 1) | 1) << i) | rev);
        }
    }

    return palindromes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> palindromes = get_palindromes();
    sort(palindromes.begin(), palindromes.end());
    int num_palindromes = palindromes.size();

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        int idx = lower_bound(palindromes.begin(), palindromes.end(), N) - palindromes.begin();
        if (idx >= num_palindromes || (idx && N - palindromes[idx - 1] < palindromes[idx] - N)) idx--;

        int ans = abs(N - palindromes[idx]);
        cout << ans << "\n";
    }
}