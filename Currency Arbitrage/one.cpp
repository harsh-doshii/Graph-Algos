#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, int src, vector<vector<int>> edges){
    vector<int> dist(V+1,INT_MAX);
    dist[src] = 0;

    //relax all edges V-1 times
    for(int i=0;i<V-1;i++){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt){
                dist[v] = dist[u] + wt;
            }
        }
    }
    //negative edge cycle
    vector<int> copy = dist;
    for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt){
                dist[v] = dist[u] + wt;
        }
    }
    if(copy==dist) return dist;
    cout << "There is a negative weight cycle" << endl; exit(0);
    return {};
}



int main(){
    //edge list representation

    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j] = -log(matrix[i][j]);
        }
    }

    double dis[n];
    for(int i=0;i<n;i++){
        dis[n] = INT_MAX;
    }

    int source = 0;
    dis[source] = 0;

for (int k = 0; k < n; ++k)
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (dis[i] + matrix[i][j] < dis[j])
        dis[j] = dis[i] + matrix[i][j];

for (int i = 0; i < n; ++i)
  for (int j = 0; j < n; ++j)
    if (dis[i] + matrix[i][j] < dis[j]) {
        return "TRUE";
    }

return "FALSE";

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    int source;
    cin >> source;
    vector<int> ans = bellman_ford(n, source, edges);
    for(int i =1; i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
