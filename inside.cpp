#include <iostream>
#include <string> 
using namespace std;


struct Point
{
    int x;
    int y;
};

int ccw(Point p0, Point p1, Point p2){
    int dx1 = p1.x -p0.x;
    int dy1 = p1.y - p0.y;
    int dx2 = p2.x - p0.x;
    int dy2 = p2.y - p0.y;
    return dx1*dy2 - dy1*dx2;
}

int sign(int x){
    if(x>0) return 1;
    if(x<0) return -1;
    return 0;
}

bool isInside(Point poly[], int n, Point p){
    int e = sign(ccw(p, poly[0], poly[1]));
    if(e==0) return false;
    for (int i = 1; i<n-1; i++){
        int t = sign(ccw(p, poly[i], poly[i+1]));
        if(t != e) return false;
    }
    int l = sign(ccw(p, poly[n-1], poly[0]));
    if(l!=e) return false;
    return true;
}


int main(){
    int n, m;
    cin>>n>>m;
    Point test[m] = {};
    Point poly[n] = { };
    int i = 0;
    while(i<n){
        Point p = {};
        cin>>p.x>>p.y;
        poly[i] = p;
        i++;
    }
    string result = "";
    int k = 0;
    while(k<m){
        Point t = {};
        cin>>t.x>>t.y;
        test[k] = t;
        k++;
    }
    for (int j = 0; j<m; j++){
        if(isInside(poly, n, test[j])){
            result += to_string(1);
        }
        else{
            result += to_string(0);
        }
    }
    cout<<result<<endl;
}