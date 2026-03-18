// Last updated: 3/18/2026, 2:23:21 PM
using namespace std;

class DetectSquares {
public:
    // store all points and their frequencies
    map<pair<int, int>, int> pointCount;
    // store all points grouped by x
    map<int, vector<int>> yByX;

    DetectSquares() {}

    // Add a point (x, y)
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        pointCount[{x, y}]++; // count how many times this point is added
        yByX[x].push_back(y); // store y for this x
    }

    // Count how many squares can be made with (x, y)
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int totalSquares = 0;

        // 1️⃣ Find all other points that have the same x
        for (int otherY : yByX[x]) {
            // skip same point
            if (otherY == y) continue;

            // 2️⃣ side length of square
            int side = abs(otherY - y);

            // 3️⃣ check both right and left sides
            // right square
            totalSquares += pointCount[{x + side, y}] * pointCount[{x + side, otherY}];
            // left square
            totalSquares += pointCount[{x - side, y}] * pointCount[{x - side, otherY}];
        }

        return totalSquares;
    }
};
