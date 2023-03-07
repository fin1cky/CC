/*
Approach : Make a map which stores the index corresponding to the latest occurrence of a number in the vector.
Maintain two variables curlen and maxlen which store the length of the current unique sequence and length
of the longest unique sequence respectively. Traverse the vector and if a number is not encountered before
or has been encountered at an index that occurs before the index from which the current unique sequence starts,
then update the index position of this number to the current index in the map, increment the curlen variable
by 1 and update maxlen to max(maxlen, curlen). Otherwise, update maxlen to max(maxlen, curlen), new curlen
value will be (i - mp[v[i]]) (mp[v[i]] has the index of its previous occurrence so, the length of the new 
unique sequence will be the number of numbers between mp[v[i]] & i, number at index i inclusive).
Set mp[v[i]] to i; 
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long int> v(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int maxlen = 0;
    int curlen = 0;
    map<long long int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.count(v[i]) == 0 || mp[v[i]] < i-curlen){
            mp[v[i]] = i;
            curlen += 1;
            maxlen = max(maxlen, curlen);
        }
        else{
            maxlen = max(maxlen,curlen);
            curlen = i-mp[v[i]];
            mp[v[i]] = i;
        }
    }
    cout << maxlen;
	return 0;
}