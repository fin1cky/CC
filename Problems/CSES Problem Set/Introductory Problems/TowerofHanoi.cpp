/*
Approach: The most important observation to solving this problem is realizing that
in order to move the biggest disk, the destination stack must be EMPTY. TO describe that
situation, imagine that currently the biggest disk can now be removed from the src stack meaning
that all the disks on top of the biggest disk have been removed and the destination
stack is EMPTY since by the rules of the game, we cannot place a bigger disk on top of
a smaller disk. This means that in the auxiliary stack (middle stack), all the remaining disks are placed.
not simply placed, but rather they are placed in the perfect order i.e. increasing order
of sizes of disks from top to bottom. The next observation that we need to make is that
once the biggest disk has reached the destination stack, it will NEVER be moved again
since there is no need to move that disk as it has already reached the destination and 
it does not have to be placed on top of any other disk. You might as well think that
once the biggest disk reaches the destination stack, it becomes fused to the floor of the
stack (or it is as good as saying we do not even need to think of its existence any more). So, 
the problem can be solved as number of moves it takes to move n-1 disks from the src
stack to the auxiliary stack using the destination stack + number of moves it takes 
to move nth disk from src stack to the destination stack (which would be 1) + 
number of moves it takes to move n-1 disks from the auxiliary stack to the destination stack
through the src stack (these disks need to be placed in the destination stack too!).
Now, we can see that this has simply reduced to the original problem again except that
now there are n-1 disks instead of n and they are all stacked on top of each other
in the auxiliary stack instead of the src stack (it is the same problem since our objective
is to move the disks from src stack to the destination stack and what names we give to the
first stack and second stack are purely arbitrary).

Recurrence relation: Let T(n) be the number of moves it takes to move n disks. From the
explanation above, we can see that T(n) = T(n-1) + 1 + T(n-1).
T(n) = 2*T(n-1) + 1
If you plug in numbers and observe the pattern, you will notice that
T(n) = 2^n - 1

Time Complexity: O(2^n)

Space Complexity: O(n) - at an moment the deepest the recursion goes is n 
(you only hold a single path from the root to a leaf in memory at any instant (depth n)
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int num_disks, int src, int dest, int aux){
	// solve(move n disks from src stack to dest stack using the aux stack)
	if(num_disks==0){
		return;
	}
	solve(num_disks-1, src, aux, dest);
	cout << src << " " << dest << "\n";
	solve(num_disks-1, aux, dest, src);
}

int main(){
	int n;
	cin >> n;
	cout << (1<<n)-1 << "\n";
	solve(n, 1, 3, 2);
	return 0;
}