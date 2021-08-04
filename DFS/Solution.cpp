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

    void dfs_recur(int node, vector<int>& visited, vector<int>& traverse){
        visited[node] = 1;
        traverse.push_back(node);
        for(auto i : l[node]){
            if(visited[i]==0){
                dfs_recur(i, visited, traverse);
            }
        }
    }

    void dfs(int source){
        vector<int> traverse;
        vector<int> visited(V, 0);
        dfs_recur(source, visited, traverse);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs_recur(i, visited, traverse);
            }
        }
        for(int i=0;i<V;i++){
            cout << traverse[i] << " ";
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
    g.printAdjList();
    g.dfs(1);
    return 0;
}
