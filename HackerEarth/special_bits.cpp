#include <bits/stdc++.h>

using namespace std;

#define long unsigned long long int

int set_count(long n) {
	int ans = 0;
	while (n) {
		if (n & 1LL) ans++;
		n >>= 1LL;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		long L, R; int k;
		cin >> L >> R >> k;

		long ans = L;
		int cnt = set_count(L);

		if (cnt <= k) {
			int idx = 0;
			while (cnt < k) {
				if (!(ans & (1LL << idx)))
					cnt++, ans |= (1LL << idx);

				idx++;
			}
		} else {
			int needed = cnt - k + 1, taken = 0, idx = 0;
			while (taken < needed) {
				if (ans & (1LL << idx))
					taken++, ans ^= (1LL << idx);

				idx++;
			}

			while (ans & (1LL << idx))
				taken++, ans ^= (1LL << idx++);

			ans |= (1LL << idx);

			int extra = taken - needed;
			ans |= (1LL << extra) - 1;
		}

		if (ans > R) cout << "-1\n";
		else cout << ans << "\n";
	}
}
