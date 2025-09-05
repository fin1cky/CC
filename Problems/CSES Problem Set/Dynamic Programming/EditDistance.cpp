/*
Approach: Let distance[i][j] represent the minimum number of moves needed to change
str1[0:i] to str2[0:j]. If the characters that are currently being compared are the
same in both the strings, then it is the same as the number of moves needed to
change str1[0:i-1] to str2[0:j-1]. However, if the characters are not same, there
are three moves to choose from as described in the problem statement:
1. add the character at str2[j] to end of str1[i] --> 1 + distance[i][j-1] (1 is for the addition)
2. remove the character at str1[i] --> 1 + distance[i-1][j] (1 is for the removal)
3. replace the character at str1[i] to str2[j] --> 1 + distance[i-1][j-1] (1 is for the replacement)

Choose the move with the minimum value.

The 2D vector is padded with zeros -- think of it as adding a $ character at the start
of both strings ($LOVE and $MOVIE). This is just done so that we can have 
baseline values to do the three moves described above for the first 
characters of both strings. (print out the distance vec, it will help you understand better)

Time Complexity: O(n*m) where n,m are the lengths of both the strings
Space Complexity: O(n*m)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	string str1, str2;
	cin >> str1 >> str2;
	int n,m;
	n = str1.length();
	m = str2.length();
	vector<vector<int>> distance(n+1, vector<int>(m+1, 0));
	for(int j=1; j<m+1; j++){
		distance[0][j] = distance[0][j-1] + 1;
	}
	for(int i=1; i<n+1; i++){
		distance[i][0] = distance[i-1][0] + 1;
	}
	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			if(str1[i-1] == str2[j-1]){
				distance[i][j] = distance[i-1][j-1];
			}
			else{
				distance[i][j] = min(distance[i-1][j-1]+1, min(distance[i-1][j]+1, distance[i][j-1]+1));
			}
		}
	}

	cout << distance[n][m];
	return 0;
}