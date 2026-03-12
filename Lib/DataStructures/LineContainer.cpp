#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

struct Line {
  int m, b, max_x;

  Line(int m, int b, int max_x = INF): m(m), b(b), max_x(max_x) {}

  int x_intersect(Line other) {
    int num = (b - other.b);
    int den = (other.m - m);
    return num / den - (num ^ den < 0 && num % den > 0);
  }

  bool operator <(const Line &other) const {
    if (m == other.m) return b < other.b;
    return m < other.m;
  }
};

struct LineContainer {
private:
  set<Line> lines;

public:
  void insert(int m, int b) {
    Line line(m, b);

    auto it = lines.lower_bound(line);
    if (it != lines.end()) {
      if (it->m == m) return;

      if (it != lines.begin()) {
        auto prv_it = prev(it);
        if (prv_it->m == m)
          lines.erase(prv_it);

        if (it != lines.begin()) {
          Line prv = *prev(it);
          lines.erase(prv);

          prv.max_x = prv.x_intersect(line);
          lines.insert(prv);
        }
      }

      bool should_erase = true;
      while (it != lines.end() && next(it) != lines.end() && should_erase) {
        Line curr = *it;
        auto nxt = next(it);

        int x1 = line.x_intersect(curr);
        int x2 = curr.x_intersect(*nxt);

        if (x1 < x2) should_erase = false;
        else {
          lines.erase(it);
          it = nxt;
        }
      }

      if (it != lines.end())
        line.max_x = line.x_intersect(*it);

      lines.insert(line);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}