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

    bool dfs(int node, vector<int>& visited,int parent ){
        visited[node] = 1;
        for(auto i : l[node]){
            if(visited[i]==0){
                bool cycle_present = dfs(i, visited, node);
                if(cycle_present) return true;
            }
            else if(i!=parent){
                return true;
            }
        }
        return false;
    }

    bool cycle_detect(){
        std::vector<int> visited(V, 0);
        return dfs(0, visited, -1);
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    //g.addEdge(0,2);
    cout << g.cycle_detect() << endl;
    //g.printAdjList();
    return 0;
}
