 #include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==3||n==2){
    	cout << "NO SOLUTION" << endl;
    }
    else{
    	if(n%2==0){
    		for(int i=n-1;i>=1;i-=2){
    			cout << i << " ";
    		}
    		for(int i=n;i>=2;i-=2){
    			cout << i << " "; 
    		}
    	}
    	else{
    		for(int i=n;i>=1;i-=2){
    			cout << i << " "; 
    		}
    		for(int i=n-1;i>=2;i-=2){
    			cout << i << " ";
    		}
    	}
    }
	return 0;
}