 #include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    long long int k;
    cin >> n >> m >> k;
    long long int a[n];
    long long int b[m];
    for(int i=0;i<n;i++){
    	cin >> a[i];
    }
    for(int i=0;i<m;i++){
    	cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    int ai = 0, bi = 0;
    int count = 0;
    while(ai<n && bi<m){
       if(a[ai]>=b[bi]-k && a[ai]<=b[bi]+k){
       	count++;
       	ai++;
       	bi++;
       }
       else if(a[ai]<b[bi]-k){
       	ai++;
       }
       else if(a[ai]>b[bi]+k){
       	bi++;
       }
    }
    cout << count << endl;

	return 0;
}