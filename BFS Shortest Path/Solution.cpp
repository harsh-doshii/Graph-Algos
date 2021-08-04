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
    void bfs(int source, int dest = -1){
        queue<int> q;
        vector<bool> visited(V, 0);
        vector<int> dist(V, 0);
        vector<int> parent(V, -1);
        q.push(source);
        visited[source] = 1;
        parent[source] = source;
        while(!q.empty()){
            cout << q.front() << " ";
            int temp = q.front();
            q.pop();
            for(auto i : l[temp]){
                if(!visited[i]){
                    q.push(i);
                    parent[i] = temp;
                    dist[i] = dist[temp] + 1;
                    visited[i] = 1;
                }
            }
        }
        if(dest!=-1){
                cout << "Shortest distance to " << dest << " is " << dist[dest] << endl;
        }
        cout << endl;
        //print the path from source to dest
        if(dest!=-1){
            int temp = dest;
            while(temp!=source){
                cout << temp << "--> ";
                temp = parent[temp];
            }
            cout << source << endl;
        }
        //print the shortest dist
        for(int i=0;i<V;i++){
            cout << "Shortest distance to " << i << " is " << dist[i] << endl;
        }
        cout << endl;
    }

};

int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,4);
    g.addEdge(3,4);
    g.addEdge(2,3);
    g.addEdge(4,5);
    //g.bfs(1);
    g.bfs(1, 4);
    return 0;
}
