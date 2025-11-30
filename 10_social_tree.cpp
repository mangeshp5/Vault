#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>>& graph, int n) {
    vector<int> level(n+1, -1);      // distance from starting node
    queue<int> q;

    q.push(start);
    level[start] = 0;                // starting user distance = 0

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int v : graph[u]) {      // check all connected friends
            if(level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    cout << "\nFriend suggestions for user " << start << ":\n";
    bool found = false;
    for(int i = 1; i <= n; i++) {
        if(level[i] == 2) {          // level 2 = friend of friend
            cout << i << " ";
            found = true;
        }
    }

    if(!found) cout << "No suggestions available.";
    cout << endl;
}

int main() {
    int n, u, v;
    cout << "Enter number of users: ";
    cin >> n;

    vector<vector<int>> graph(n+1);   // adjacency list (graph)

    cout << "Enter friend connections (edges):\n";
    for(int i = 0; i < n-1; i++) {    // taking sample edges
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int user;
    cout << "\nSuggest friends for user: ";
    cin >> user;

    BFS(user, graph, n);
    return 0;
}
