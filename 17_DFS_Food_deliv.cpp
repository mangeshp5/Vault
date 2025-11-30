#include <iostream>
#include <vector>
using namespace std;

class DeliveryGraph {
private:
    int n;                        // number of locations
    vector<vector<int>> adj;      // adjacency list

public:
    DeliveryGraph(int nodes) {
        n = nodes;
        adj.resize(n);
    }

    // Add delivery connection (edge)
    void addRoute(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);      // undirected route
    }

    // DFS function
    void dfs(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";

        for(int next : adj[start])
            if(!visited[next])
                dfs(next, visited);
    }

    // Show full delivery route from starting restaurant
    void showRoutes(int start) {
        vector<bool> visited(n, false);
        cout << "\nDelivery Route from " << start << ":\n";
        dfs(start, visited);
    }
};

int main() {
    int nodes, edges, u, v, start;

    cout << "Enter number of locations (nodes): ";
    cin >> nodes;

    DeliveryGraph g(nodes);

    cout << "Enter number of delivery connections (edges): ";
    cin >> edges;

    cout << "\nEnter connected locations (u v):\n";
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        g.addRoute(u, v);
    }

    cout << "\nEnter starting restaurant for delivery: ";
    cin >> start;

    g.showRoutes(start);

    return 0;
}
