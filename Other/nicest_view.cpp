#include <bits/stdc++.h>

using namespace std;

#define llong long long int

template<typename T>
struct Fraction {
    T num, den;

    Fraction(T num = 0, T den = 1) {
        T g = gcd(num, den);
        this->num = num / g;
        this->den = den / g;
    }

    Fraction<T> operator +(Fraction<T> other) {
        return Fraction<T>(num * other.den + other.num * den, den * other.den);
    }

    bool operator <(Fraction<T> const &other) const {
        return num * other.den < other.num * den;
    }
};

template<typename T>
Fraction<T> max_beauty(vector<int> &heights) {
    stack<int> aux;
    Fraction<T> ans;

    for (int i = 0; i < (int) heights.size(); i++) {
        while (!aux.empty() && heights[aux.top()] < heights[i]) {
            Fraction<T> last = Fraction<T>(heights[aux.top()] - heights[i - 1], heights[i] - heights[i - 1]);
            Fraction<T> dist = Fraction<T>(i - aux.top() - 1) + last;
            ans = max(ans, dist);
            aux.pop();
        }

        aux.push(i);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> H(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];

    Fraction<llong> ans = max_beauty<llong>(H);

    reverse(H.begin(), H.end());
    ans = max(ans, max_beauty<llong>(H));

    if (ans.den == 1) cout << ans.num << "\n";
    else cout << ans.num << "/" << ans.den << "\n";
}