 #include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    int lcs[n+1][m+1] = {};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        	lcs[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(s[i-1]==t[j-1]){
    			lcs[i][j] = 1 + lcs[i-1][j-1];
    		}
    		else{
    			lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
    		}
    	}
    }
    cout << lcs[n][m] << endl;
    /*string ans="";
    for(int i=n,j=m;i!=0&&j!=0;){
    	if(lcs[i][j]==lcs[i-1][j]){
           i = i-1;
    	}
    	else if(lcs[i][j]==lcs[i][j-1]){
           j=j-1;
    	}
    	else{
    		ans = t[j-1] + ans;
            i--;
            j--;
    	}
    }
    //cout << ans << endl;
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << lcs[i][j] << " ";
        }
        cout << endl;
    }*/
	return 0;
}	