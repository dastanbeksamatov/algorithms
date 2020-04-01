#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Point{
    int x;
    int y;
};

double shoelace(Point points[], int n) {
	double leftSum = 0.0;
	double rightSum = 0.0;
 
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		leftSum  += points[i].x * points[j].y;
		rightSum += points[j].x * points[i].y;
	}
 
	return 0.5 * abs(leftSum - rightSum);
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
    double area = 0.0;
    int j = n - 1;
/*     for(int k = 0; k<n; k++){
        area +=  (poly[j].x + poly[k].x) * (poly[j].y - poly[k].y);
        j = k;
    } */
    
    cout<<shoelace(poly, n)<<endl;
 }