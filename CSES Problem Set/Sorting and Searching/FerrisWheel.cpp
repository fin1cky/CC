#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,x;
    cin >> n >> x;
    vector <long long int> gondela_weights;
    for(int i=0;i<n;i++){
    	long long int y;
    	cin >> y;
    	gondela_weights.push_back(y);
    }
    sort(gondela_weights.begin(),gondela_weights.end());
    int i=0;
    int j=n-1;
    int min_gondelas = 0;
    while(i<=j){
    	if(gondela_weights[i]+gondela_weights[j]<=x){
    		i++;
    		j--;
    		min_gondelas++;
    	}
    	else{
    		j--;
    		min_gondelas++;
    	}
    }
    cout << min_gondelas << "\n";
	return 0;
}