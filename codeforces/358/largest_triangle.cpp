/*
Building a convex hull for given set of points then using it to find the largest area of triangle
Source: http://isolvedaproblem.blogspot.in/2011/08/maximum-triangle-area-part-2.html
@Author: Rohith Uppala
*/

#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;

struct point {
	int x;
	int y;
};

point p0;

point nextToTop(stack<point> &s) {
	point p = s.top();
	s.pop();
	point res = s.top();
	s.push(p);
	return res;
}

int swap(point &p1, point &p2) {
	point temp = p1;
	p1 = p2;
	p2 = temp;
}

int square_dist(point p1, point p2) {
	return (p1.x -p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(point p1, point p2, point p3) {
	int val = ((p2.y - p1.y) * (p3.x - p2.x)) - ((p2.x - p1.x) * (p3.y - p2.y));
	if(val == 0) return 0;
	return (val > 0) ? 1:2;
}

int compare(const void *vp1, const void *vp2) {
	// you can do this using acute angle difference also
	point *p1 = (point *)vp1;
	point *p2 = (point *)vp2;
	int o = orientation(p0, *p1, *p2);
	if(o == 0) return (square_dist(p0, *p2) >= square_dist(p0, *p1)) ? -1: 1;
	return (o == 2) ? -1:1;
}

vector<point> convex_hull(point points[], int n) {
	vector<point> convex_hull_points;
	int ymin = points[0].y, min = 0;
	for(int i=1; i<n; i++) {
		int y = points[i].y;
		if((y < ymin) || (ymin == y && (points[0].x < points[i].x))) ymin = points[i].y, min = i;
	}
	swap(points[0], points[min]);
	p0 = points[0];
	qsort(&points[1], n-1, sizeof(point), compare);
	int m=1;
	for(int i=1; i<n; i++) {
		while(i < n-1 && orientation(p0, points[i], points[i+1]) == 0) i++;
		points[m] = points[i];
		m = m+1;
	}
	if(m < 3) return convex_hull_points;
	stack<point> s;
	s.push(points[0]); s.push(points[1]); s.push(points[2]);
	for(int i=3; i<n; i++) {
		while(orientation(nextToTop(s), s.top(), points[i]) != 2) s.pop();
		s.push(points[i]);
	}
	while(!s.empty()) {
		point p = s.top();
		convex_hull_points.push_back(p);
		s.pop();
	}
	return convex_hull_points;
}

double get_triangle_area(point p1, point p2, point p3) {
	    return abs((double) p1.x * p2.y +
               (double) p2.x * p3.y +
               (double) p3.x * p1.y -
               (double) p1.y * p2.x -
               (double) p2.y * p3.x -
               (double) p3.y * p1.x) / 2.0;
}

double get_large_triangle_area(vector<point> convex_hull_points) {
	int n = convex_hull_points.size();
	int i=0, j=i+1, k=j+1;
	double res = 0.0;
	while(true) {
		double area = get_triangle_area(convex_hull_points[i], convex_hull_points[j], convex_hull_points[k]);	
		while(true) {
			while(true) {
				int nk = (k+1) % n;
				double narea = get_triangle_area(convex_hull_points[i], convex_hull_points[j], convex_hull_points[nk]);
				if(narea >= area) {
					area = narea;
					k = nk;
				}
				else break;
			}
			int nj = (j+1) % n;
			double narea = get_triangle_area(convex_hull_points[i], convex_hull_points[nj], convex_hull_points[k]);
			if(narea >= area) {
				area = narea;
				j = nj;
			}
			else break;
		}
		if (area >= res) res = area;
		i = i+1;
		if(i == j) j = (j+1) % n;
		if(j == k) k = (k+1) % n;
		if(i == n) break;
	}
	return res;
}

int main() {
	point points[] = {{0,0}, {1,0}, {1,1}, {0,1}};
	int n = sizeof(points) / sizeof(points[0]);
	vector<point> convex_hull_points = convex_hull(points, n);
	for(int i=0; i<convex_hull_points.size(); i++) cout << convex_hull_points[i].x << " " << convex_hull_points[i].y << endl;
 	double largest_area = get_large_triangle_area(convex_hull_points);
	cout << largest_area << endl;
	return 0;
}
