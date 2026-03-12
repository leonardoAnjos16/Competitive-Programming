#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

struct Size {
  int w, h;
  ldouble s;

  Size() {}
  Size(int w, int h, ldouble s): w(w), h(h), s(s) {}
};

struct Photo {
  int t;
  vector<Size> sizes;

  Photo() {}
  Photo(int t): t(t) {}

  void add_size(Size size) {
    sizes.push_back(size);
  }
};

struct Group {
  int n;
  vector<Photo> photos;

  Group() {}
  Group(int n): n(n) {}

  void add_photo(Photo photo) {
    photos.push_back(photo);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int g, gw;
  cin >> g >> gw;

  int total_photos = 0;
  vector<Group> groups(g);

  for (int i = 0; i < g; i++) {
    int n; cin >> n;

    groups[i] = Group(n);
    for (int j = 0; j < n; j++) {
      int t; cin >> t;

      Photo photo = Photo(t);
      for (int k = 0; k < t; k++) {
        int w, h; ldouble s;
        cin >> w >> h >> s;

        Size size = Size(w, h, s);
        photo.add_size(size);
      }

      groups[i].add_photo(photo);
      total_photos++;
    }
  }

  int x = 0, y = 0;
  for (int i = 0; i < total_photos; i++) {
    cout << (x + 1) << " " << (y + 1) << " 6 6\n";

    if (x + 6 >= gw) {
      x = 0;
      y += 6;
    } else {
      x += 6;
    }
  }
}