#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of locations: ";
    cin >> n;

    vector<vector<int>> graph(n);   // adjacency list
    cout << "Enter number of routes: ";
    cin >> e;

    cout << "Enter connected paths (u v):\n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);      // undirected
    }

    int start, dest;
    cout << "Enter starting point: ";
    cin >> start;
    cout << "Enter destination: ";
    cin >> dest;

    // -------- BFS to find shortest path --------
    vector<bool> visited(n,false);
    vector<int> parent(n,-1);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == dest) break;   // stop when reached

        for(int next : graph[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
    }

    // -------- Print path --------
    if(!visited[dest]) {
        cout << "No route found!";
        return 0;
    }

    cout << "\nShortest Path: ";
    int x = dest;
    vector<int> path;
    while(x != -1) {
        path.push_back(x);
        x = parent[x];
    }

    for(int i = path.size()-1; i >= 0; i--)
        cout << path[i] << (i?" -> ":"");

    cout << "\nTotal steps: " << path.size()-1;
}
