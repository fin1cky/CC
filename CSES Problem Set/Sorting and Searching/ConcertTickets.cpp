/*
set<pair<int,int>>sortedticketprices is used to hold values and index and makes sense because we might
encounter duplicate values which a set does not handle.
By performing lower_bound({max_price[i]+1,0}) and lower-- later (in case of a match) we can account 
for all values that are lesser than or equal to a given number.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>ticket_prices;
    vector<int>max_price;
    set<pair<int,int>>sortedticketprices;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
    	ticket_prices.push_back(x);
        sortedticketprices.insert({ticket_prices[i],i});
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        max_price.push_back(x);
    }
    for(int i=0;i<m;i++){
    	 auto lower = sortedticketprices.lower_bound({max_price[i]+1,0});
         //cout << (*lower).first << "\n";
    	 if(lower==sortedticketprices.begin()){
    	 	cout << "-1" << "\n";
    	 }
    	 else{
            lower--;
    	 	cout << (*lower).first << "\n";
    	 	sortedticketprices.erase(lower); 
    	 }
    }
	return 0;
}