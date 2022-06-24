template<typename T = long>
bool inside(vector<Point<T>> &vertices, Point<T> P) {
    int n = vertices.size();
    for (int i = 0; i < n; i++)
        if (left_turn(vertices[(i + 1) % n] - vertices[i], P - vertices[i]))
            return false;

    return true;
}