#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* l;  //pointer to list l

public:
    Graph(int v){
        V = v;
        l = new list<int>[V]; //array containing V lists, pointer to that array is l
    }

    void addEdge(int i, int j, bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjList(){
        for(int i =0;i<V;i++){
            cout << i << "---> ";
            for(auto node : l[i]){
                cout << node << " ";
            }
            cout << endl;
        }
    }
    vector<int> bfs(int source, int& ans){
        queue<int> q;
        ans = 0;
        vector<int> visited(V, 0);
        vector<int> parent(V);
        vector<int> distance(V, 0);
        vector<int> path;
        visited[source] = 1;
        q.push(source);
        parent[source] = source;
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(auto i : l[k]){
                if(visited[i]==0){
                    q.push(i);
                    visited[i]=1;
                    parent[i] = k;
                    distance[i] = distance[k]+1;
                }
            }
        }
        if(visited[V-1]==0){ans=-1;  return path;}
        ans = distance[V-1];
        int temp = V-1;
        while(temp!=source){
            path.push_back(temp+1);
            temp = parent[temp];
        }
        path.push_back(source+1);
        return path;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        int l;
        cin >> l;
        g.addEdge(k-1,l-1);
    }
    int ans = -1;
    vector<int> pans = g.bfs(0, ans);
    if(ans==-1) cout << "IMPOSSIBLE";
    else{
        cout << ans+1 << endl;
        reverse(pans.begin(), pans.end());
        for(int i=0;i<pans.size();i++){
            cout << pans[i] << " ";
        }
    }

    return 0;
}
