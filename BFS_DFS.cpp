#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// BFS Function
void bfs(int start, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    cout << "BFS Traversal: ";
    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]){
            if (!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}
// DFS Function (Recursive)
void dfs_recursive(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]){
        if (!visited[neighbor]){
            dfs_recursive(neighbor, adj, visited);
        }
    }
}
// DFS Function (Iterative)
void dfs_iterative(int start, vector<vector<int>> &adj, vector<bool> &visited){
    stack<int> s;
    s.push(start);
    cout << "DFS Traversal (Iterative): ";
    while (!s.empty()){
        int node = s.top();
        s.pop();
        if (!visited[node]){
            visited[node] = true;
            cout << node << " ";
            for (int i = adj[node].size() - 1; i >= 0; --i){
                if (!visited[adj[node][i]]){
                    s.push(adj[node][i]);
                }
            }
        }
    }
    cout << endl;
}
int main(){
    int n = 6; // Number of nodes
    vector<vector<int>> adj(n);
    // Add edges (Undirected Graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};
    vector<bool> visited(n, false);
    // Perform BFS
    bfs(0, adj, visited);
    // Reset visited array for DFS
    fill(visited.begin(), visited.end(), false);
    cout << "DFS Traversal (Recursive): ";
    // Perform Recursive DFS
    dfs_recursive(0, adj, visited);
    cout << endl;
    // Reset visited array for Iterative DFS
    fill(visited.begin(), visited.end(), false);
    // Perform Iterative DFS
    dfs_iterative(0, adj, visited);
    return 0;
}
