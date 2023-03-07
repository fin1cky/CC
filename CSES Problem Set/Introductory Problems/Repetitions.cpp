 #include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int len = 1;
    int best = 1;
    for(int i=1;i<str.length();i++){ 
        char ch = str[i];
        char ch1 = str[i-1];
    	if(ch==ch1){
            //cout << ch << " " << ch1 << endl ;
    		len++;
            //cout << len << endl;
    	}
    	else{
    		len=1;
    	}
        best = max(len,best);
    }
    cout << best << endl;
    
	return 0;
}