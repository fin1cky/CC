#include <bits/stdc++.h>
using namespace std;

long long answer(long long x,long long y){
    long long maxd = max(x,y);//the number would lie in the outermost L shape of the square grid which would be of the max dimension of x and y. we try to solve this problem by first reaching the max element possible
    if(maxd%2==0){//if its even, the max element is on the first element of the even rows
        if(y==1){//if its the first element its the max element itself
            return maxd*maxd;
        }
        else if(x<maxd){//if its not on the same row as the max element we first reach the junction point of the L using the answer(maxd,maxd) function and then try to go up from there to the required point
            return answer(maxd,maxd) - (maxd-x);
        }
        else if(x==maxd){//if its on the same row as the max element
            return maxd*maxd - (y-1);
        }
    }
    else{//if its odd, the max element is on the first element of the odd columns
        if(x==1){//if its the first element its the max element itself
            return maxd*maxd;
        }
        else if(y<maxd){//if its not on the same column as the max element we first reach the junction point of the L using the answer(maxd,maxd) function and then try to go left from there to the required point
            return answer(maxd,maxd) - (maxd-y);
        }
        else if(y==maxd){//if its on the same column as the max element
            return maxd*maxd - (x-1);
        }
    }
}

void solve(){
    long long x,y;
    cin >> x >> y;
    cout << answer(x,y) << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}