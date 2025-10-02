// a b c d
// e f g h

// minimize [(a+b)2 + (a+c)2 + (a+d)2 + (b+c)2 + (b+d)2 + (c+d)2
// + (e+f)2 + (e+g)2 + (e+h)2 + (f+g)2 + (f+h)2 + (g+h)2]

// a b c
// d e f

//  +  + 2ab + +  + 2ac +  +  + 2bc
// +  + 2de + +  + 2df +  +  + 2ef

// a e c
// d b f

//  +  + 2ae + +  + 2ac +  +  + 2ec
// +  + 2bd +  +  + 2df +  +  + 2bf 

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		for(int i=0; i<n; i++){
			cin >> b[i];
		}
		if(n==1){
			cout << 0 << "\n";
		}
		else{
			pair<int, int> prev_sums = {a[0], b[0]};
			vector<vector<int>> elems(2);
			elems[0].push_back(a[0]);
			elems[1].push_back(b[0]);
			int cost = 0;
			for(int i=1; i<n; i++){
				int sum1_term1 = prev_sums.first*a[i];
				int sum1_term2 = prev_sums.second*b[i];
				int sum2_term1 = prev_sums.first*b[i];
				int sum2_term2 = prev_sums.second*a[i];

				// cout << a[i] << " " << b[i] << " " << sum1_term1 << " " << sum1_term2 << " " << sum2_term1 << " " << sum2_term2 << "\n";

				if(sum1_term1 + sum1_term2 <= sum2_term1 + sum2_term2){
					prev_sums.first += a[i];
					prev_sums.second += b[i];
					// cost += sum1_term1 + sum1_term2;
					elems[0].push_back(a[i]);
					elems[1].push_back(b[i]);
				}
				else{
					prev_sums.first += b[i];
					prev_sums.second += a[i];
					// cost += sum2_term1 + sum2_term2;
					elems[1].push_back(a[i]);
					elems[0].push_back(b[i]);
				}
			}
			// cost *= 2;
			for(auto ele: elems[0]){
				cout << ele << " ";
			}
			cout << "\n";
			for(auto ele: elems[1]){
				cout << ele << " ";
			}
			cout << "\n";
			for(int i=0; i<n-1; i++){
				for(int j=i+1; j<n; j++){
					cost += ((elems[0][i]+elems[0][j])*(elems[0][i]+elems[0][j])) 
					+ ((elems[1][i]+elems[1][j])*(elems[1][i]+elems[1][j]));
				}
			}
			cout << cost << "\n";
		}
	}
	return 0;
}