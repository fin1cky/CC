/*
Approach: The objective is to go from room 1 to room n by getting the maximum score.
Since the edge weights can be negative, we cannot use Dijkstra's algorithm. This leaves
us with Bellman-Ford algorithm. Since there can be cycles in the graph, after relaxing
every edge n-1 times, during the nth time, maintain a vector that stores the rooms
whose score improved. From these nodes, check if it is possible to reach room n, if yes,
then return -1 since it implies the existence of a path where the score can be infinitely 
large. If it is not possible to reach room n from any of these nodes, return the output
from the Bellman-Ford algorithm. (Obviously in this implementation of Bellman-Ford, we
update the room if the new score is GREATER than the previous score.)

Time Complexity: O(nm)

Space Complexity: O(n+m)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> roads;
    vector<vector<int>> graph(n+1);
    for(int i=0; i<m; i++){
        int a,b,x;
        cin >> a >> b >> x;
        roads.push_back({a, b, x});
        graph[a].push_back(b);
    }
    long long int INF = -1000000000000000;
    vector<long long int> scores(n+1, INF);
    scores[1] = 0;
    
    int room = n;
    vector<int> score_improved;
    for(int i=0; i<n; i++){
        vector<long long int> current = scores;
        for(int j=0; j<m; j++){
            int a = roads[j][0];
            int b = roads[j][1];
            int x = roads[j][2];
            if(scores[a] != INF && scores[a] + x > current[b]){
                if(i != n-1){
                    current[b] = scores[a] + x;
                }
                else{
                    score_improved.push_back(b);
                }
            }
        }
        scores = current;
    }

    vector<int> visited(n+1, 0);
    for(int i=0; i<score_improved.size(); i++){
        int node = score_improved[i];
        if(visited[node]==0){
            queue<int> q;
            q.push(node);
            while(q.size() > 0){
                node = q.front();
                q.pop();
                if(node==n){
                    cout << -1;
                    return 0;
                }
                visited[node] = 1;
                for(int x: graph[node]){
                    if(visited[x] == 0){
                        q.push(x);
                    }
                }
            }
        }
    }
    
    cout << scores[n];
    return 0;
}