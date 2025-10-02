#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int current_pos = 0;
		int score = 0;
		int current_time = 0;
		while(n--){
			int next_time, next_pos;
			cin >> next_time >> next_pos;
			int difference = next_time - current_time;
			if(difference%2==0 && next_pos==current_pos){
				score += difference;
			}
			else if(difference%2==0 && next_pos!=current_pos){
				score += difference-1;
			}
			else if(difference%2!=0 && next_pos==current_pos){
				score += difference-1;
			}
			else if(difference%2!=0 && next_pos!=current_pos){
				score += difference;
			}
			current_pos = next_pos;
			current_time = next_time;
		}
		cout << score+(m-current_time) << "\n";
	}
	return 0;
}