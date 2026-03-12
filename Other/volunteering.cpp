#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int BEGIN = 0;
const int END = 1;
const int QUERY = 2;

struct Event {
  int type, t;

  Event(int type, int t): type(type), t(t) {}

  bool operator <(Event const &other) const {
    if (t == other.t) return type < other.type;
    return t < other.t;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  int S, F;
  cin >> S >> F;

  vector<Event> events;
  events.emplace_back(QUERY, S);
  events.emplace_back(QUERY, F);

  for (int i = 0; i < n; i++) {
    int b, e;
    cin >> b >> e;

    events.emplace_back(BEGIN, b);
    events.emplace_back(END, e);
  }

  sort(events.begin(), events.end());

  int available = 0, last_time = 0;
  vector<llong> total_time(n + 1);

  for (auto [type, t]: events) {
    total_time[available] += max(min(t, F) - max(last_time, S), 0);
    available += type == BEGIN ? 1 : (type == END ? -1 : 0);
    last_time = t;
  }

  for (int i = 1; i <= n; i++)
    total_time[i] += total_time[i - 1];

  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << total_time[i];
  }

  cout << "\n";
}