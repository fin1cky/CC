#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,W;
    cin >> N >> W;
    long long int wt[N+1]={}; 
    long long int val[N+1]={};
    long long int V[N+1][W+1];
    
    for(int i=0;i<N+1;i++){
    	for(int j=0;j<W+1;j++){
            V[i][j]=0;
        }
    }
    
    for(int i=1;i<=N;i++){
    	cin >> wt[i] >> val[i];
    } 

    for(int item = 1;item<=N;item++){
    	for(int weight = 1;weight<=W;weight++){
    		if(wt[item]<=weight){
    			V[item][weight] = max(V[item-1][weight],val[item]+V[item-1][weight-wt[item]]);
    		}
    		else{
    			V[item][weight] = V[item-1][weight];
    		}
    	}
    }
    cout << V[N][W];
	return 0;
}