#include <bits/stdc++.h>
using namespace std;

bool dfs_helper(vector<int>graph[], int node, int visited[], int parent, int color){
    visited[node] = color; //1 or 2
    for(auto nbr : graph[node]){
        if(visited[nbr]==0){
            int subprob = dfs_helper(graph, nbr, visited, node, 3-color);
            if(subprob==false) return false;
        }
        //nbr is not a parent and nbr is visited
        else if(nbr!=parent && color==visited[nbr]){
            return false;
        }
    }
    return true;
}


bool dfs(vector<int> graph[], int N){
    int visited[N] = {0}; //visited array filled with zeros
    int color = 1;
     bool ans = true;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                color = 1;
                ans = ans && dfs_helper(graph, i, visited, -1, color);
            }
        }
    return ans;
}



int main(){
    int N, M;
    cin >> N >> M;
    vector<int> graph[N];
    while(M--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if(dfs(graph, N)) {cout << "Yes its bipartite" << endl;}
    else{
        cout << "Its not bipartite" << endl;
    }

    return 0;
}
