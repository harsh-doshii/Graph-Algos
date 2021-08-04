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

    void addEdge(int i, int j){
        l[i].push_back(j);
    }

    void dfs(int node, vector<int>& visited, vector<int>& ordering){
        visited[node] = 1;
        for(int nbr : l[node]){
            if(visited[nbr]==0){
                dfs(nbr, visited, ordering);
            }
        }
        ordering.push_back(node);
        return;
    }

    void topo_sort(){
        vector<int> visited(V, 0);
        vector<int> ordering;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(i, visited, ordering);
            }
        }
        reverse(ordering.begin(), ordering.end());
        for(int i=0;i<ordering.size();i++){
            cout << ordering[i] << " ";
        }
    }
};

int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.topo_sort();
    return 0;
}
