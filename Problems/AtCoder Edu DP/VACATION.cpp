 #include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int>dp(3);
    for(int i=0;i<n;i++){
       vector<int>c(3,0);
       vector<int>ndp(3,0);
       for(int i=0;i<3;i++){
    	  scanf("%d",&c[i]);
       }
       for(int i=0;i<3;i++){
       	for(int j=0;j<3;j++){
       		if(i!=j){
       			ndp[j]=max(ndp[j],dp[i]+c[j]);
       		}
       	}
       }
       dp = ndp;
    }
    printf("%d\n",max({dp[0],dp[1],dp[2]}));
	return 0;
}