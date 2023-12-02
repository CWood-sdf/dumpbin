#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct Point {
  double x;
  double y;
};
// Find a single point on a bezier curve with parameter t (t goes from 0 -> 1)
Point bezierInterpolate(vector<Point> ptArr, double t) {
  // The array of the interpolated points
  vector<Point> newPts = {};
  for (int i = 0; i < ptArr.size() - 1; i++) {
    // Interpolate between current point and next
    double newX = ptArr[i + 1].x - ptArr[i].x;
    newX *= t;
    newX += ptArr[i].x;
    double newY = ptArr[i + 1].y - ptArr[i].y;
    newY *= t;
    newY += ptArr[i].y;

    Point newPt = {newX, newY};
    newPts.push_back(newPt);
  }
  // If interpolated point array still has multiple elements
  if (newPts.size() >= 2) {
    // YAYYY RECURSION!!!!
    return bezierInterpolate(newPts, t);
  } else {
    // Otherwise return the only element
    return newPts.front();
  }
}
// Create a bezier curve
vector<Point> bezierCurve(vector<Point> ptArr, double inc) {
  // double spacing = 1.0;
  // Return value
  vector<Point> ret;
  // Go through multiple rounds of interpolation
  for (double i = 0; i <= 1; i += inc) {
    Point pt = bezierInterpolate(ptArr, i);
    ret.push_back(pt);
  }
  ret.push_back(ptArr.back());
  return ret;
}

int main() {
  vector<Point> pts = {{0, 0}, {1, 1}, {2, 0}};
  vector<Point> curve = bezierCurve(pts, 0.1);
  for (Point pt : curve) {
    cout << pt.x << ", " << pt.y << endl;
  }
  return 0;
}
