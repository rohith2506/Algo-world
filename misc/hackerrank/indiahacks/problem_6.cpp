// A C++ program to find convex hull of a set of points
// Refer http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
// for explanation of orientation()
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;
 
struct Point
{
    int x;
    int y;
};
 
// A globle point needed for  sorting points with reference to the first point
// Used in compare function of qsort()
Point p0;
 
// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
// A utility function to swap two points
int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
// A utility function to return square of distance between p1 and p2
int dist(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 
// Prints convex hull of a set of n points.
vector<Point> convexHull(vector<Point> points, int n)
{
   // Find the bottommost point
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     // Pick the bottom-most or chose the left most point in case of tie
     if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   // Place the bottom-most point at first position
   swap(points[0], points[min]);
 
   // Sort n-1 points with respect to the first point.  A point p1 comes
   // before p2 in sorted ouput if p2 has larger polar angle (in 
   // counterclockwise direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   // Create an empty stack and push first three points to it.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   // Process remaining n-3 points
   for (int i = 3; i < n; i++)
   {
      // Keep removing top while the angle formed by points next-to-top, 
      // top, and points[i] makes a non-left turn
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
    
   vector<Point> res;
   // Now stack has the output points, print contents of stack
   while (!S.empty())
   {
       Point p = S.top();
       res.push_back(p);
       S.pop();
   }
   return res;
}

double solve(vector<Point> pts){
    int x1,y1,x2,Y2,x3,y3;
    x1 = pts[0].x;
    y1 = pts[0].y;

    x2 = pts[1].x;
    Y2 = pts[1].y;

    x3 = pts[2].x;
    y3 = pts[2].y;

 double px,py,qx,qy,rx,ry,p1,y11,pd1,yd1,p2,y2,pd2,yd2,ox,oy,dx,yd,radius; // Variables Used and to Declared
px =x1 ; py = y1; //first Point X and Y
qx =x2;  qy = Y2; // Second Point X and Y
rx =x3 ; ry = y3; // Third Point X and Y

////****************Following are Basic Procedure**********************///
p1 = (qx + px) / 2;
y11 = (qy + py) / 2;
yd1 = qx - px;
pd1 = -(qy - py);

p2 = (rx + qx) / 2;
y2 = (ry + qy) / 2;
yd2 = rx - qx;
pd2 = -(ry - qy);

ox = (y11 * pd1 * pd2 + p2 * pd1 * yd2 - p1 * yd1 * pd2 - y2 * pd1 * pd2)/ (pd1 * yd2 - yd1 * pd2);
oy = (ox - p1) * yd1 / pd1 + y11;

dx = ox - px;
yd = oy - py;
radius =(int)sqrt(dx * dx + yd * yd);

cout<<dx<<" "<<yd<<" "<<radius<<endl;
return radius; 
}
 
// Driver program to test above functions
int main()
{
    int n;
    cin >> n;
    vector<Point> points;
    for(int i=0;i<n;i++){
      int x,y;
      cin >> x >> y;
      Point p;
      p.x = x;
      p.y = y;
      points.push_back(p);
    }
    vector<Point> res = convexHull(points, n);
    double radius = 0.0;

    cout<<res.size()<<endl;
    for(int i=0;i<=res.size()-3;i++){
        vector<Point> pts;
        for(int j=i;j<i+3;j++)
          pts.push_back(res[j]);
        radius = radius + solve(pts);
    }
    cout << radius << endl;
    return 0;
}