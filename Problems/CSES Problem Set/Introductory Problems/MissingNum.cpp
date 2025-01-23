 #include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n-1]={};
    for(int i=0;i<n-1;i++){
        cin >> arr[i];
    }
    sort(arr,arr+(n-1));
    /*for(int i=0;i<n-1;i++){
        cout << arr[i] << " ";
    }*/
    bool flag = false;
    for(int i=0;i<n-1;i++){
        if(arr[i]==i+1){

        }
        else{
            cout << i+1;
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << n ;
    }

    
	return 0;
}