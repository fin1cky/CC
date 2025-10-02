/*
Approach: Since pos represents the index in the final concatenated string, its value
lies between [1, s*(s+1)/2] where s is the length of the initial string. Every
time, we delete only one letter from the current version of the string and append
it to the big string(which eventually becomes the final string). So, each time, 
the length of the big string increases like this 
s -> s + (s-1) -> s + (s-1) + (s-2) -> ... -> s + (s-1) + (s-2) + ... + 1 (length of S). 
Among all these sums, we need to find the smallest sum that is bigger than or 
equal to pos meaning we need to find the smallest value k such that
(s + (s-1) + (s-2) + ... + (s-k+1) + (s-k) + ... + 1) - ((s-k) + ... + 1) >= pos
i.e. (s*(s+1))/2 - ((s-k)*(s-k+1))/2 >= pos > (s*(s+1))/2 - ((s-(k-1))*((s-(k-1))+1))/2
Once we find such k, we would need to make k-1 deletions meaning we need to remove 
(s*(s+1))/2 - ((s-(k-1))*(s-(k-1)+1))/2 from pos. 

Why k-1?
Because the sum corresponding to k is atleast as big as pos meaning pos is in the
kth string. So if we remove the sums of the lengths of all strings 
s, s-1, s-k-1 that come before this string from pos, we will be left with an index
that lies within the length of the current string.

Also since we use 0-based indexing, subtract -1 from pos. 

Doing these two operations give the adjusted position of the pos 
corresponding to the length of latest string that would be appended.

Delete k-1 characters from the original string to generate the
lexicographically minimal string. For this, whenever we encounter a character
and the characters immediately before this character are greater than it,
then keep popping them till the string is empty or k-1 characters are deleted or
you encounter a character smaller than the current character. Insert this character.
After traversing all the characters of the original string, if there are still
deletions left, do them from the end of the string since it is now guaranteed that
the characters are sorted lexicographically otherwise they would have been popped
earlier itself.

In this new string, simply output the character at the adjusted position of pos.

Time Complexity: O(S) where S is the sum of all lengths of all t strings.

Space Complexity: O(max length of a string among all strings)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	string ans = "";
	while(t--){
		string str;
		cin >> str;
		long long int pos;
		cin >> pos;
		long long int s = str.length();
		long long int l = 1, h = s, idx = s;
		long long int val = (s*(s+1))/2;
		while(l<=h){
			long long int mid = l + (h-l)/2;
			long long int val_mid = ((s-mid)*(s-mid+1))/2; 
			if(val-val_mid >= pos){
				h = mid-1;
				idx = mid;
			}
			else{
				l = mid+1;
			}
		}
		int deletions = idx-1;
		int adjusted_pos = pos - 1;
		if(deletions > 0){
			adjusted_pos = pos - (val-((s-(idx-1))*(s-(idx-1)+1))/2) - 1;
		} 
		string sub = "";
		long long int count = deletions;
		for(char ch: str){
			while(sub.length()>0 && count>0 && sub.back()>ch){
				count--;
				sub.pop_back();
			}
			sub.push_back(ch);
		}

		while(count>0 && sub.length()>0){
			sub.pop_back();
			count--;
		}
		// cout << sub << " " << adj_pos << "\n";
		
		ans += sub[adjusted_pos];
	}
	cout << ans;
	return 0;
}