#include <bits/stdc++.h> 
using namespace std; 
  
struct Point 
{ 
    int x, y; 
}; 
  
int orientation(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// Prints convex hull of a set of n points. 
void convexHull(Point points[], int n) 
{ 
    Point result[] = {};
    // There must be at least 3 points 
    if (n < 3) return; 
  
    // Initialize Result 
    vector<Point> hull; 
  
    // Find the leftmost point 
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].x < points[l].x) 
            l = i; 
   
    int p = l, q; 
    do
    { 
        // Add current point to result 
        hull.push_back(points[p]); 
  
        q = (p+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           // If i is more counterclockwise than current q, then 
           // update q 
           if (orientation(points[p], points[i], points[q]) == 2) 
               q = i; 
        } 
  
        p = q; 
  
    } while (p != l);  // While we don't come to first point 
  
    // Print Result 
    for (int i = 0; i < hull.size(); i++) 
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n"; 
} 

int main(){
        int n;
    cin>>n;
    Point poly[n] = { };
    int i = 0;
    while(i<n){
        Point p = {};
        cin>>p.x>>p.y;
        poly[i] = p;
        i++;
    }

}