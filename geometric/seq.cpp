#include <iostream>

using namespace std;

long long nchoosek(int n, int m){
    long long res = 1;
    for (int i=0; i<(n-m); i++){
        res = res*(n-i);
    }
    long long div = 1;
    for (int k=0; k<(n-m); k++){
        div *= (k+1);
    }
    return res/div;
}

int main(){
    int n, m;

    cin>>n>>m;
    cout<<nchoosek(n,m)<<endl;
    
}