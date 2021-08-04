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

    bool dfs(int node, std::vector<int>& visited, vector<int>& stack){
        visited[node] = 1;
        stack[node] = 1;
        for(auto i : l[node]){
            if(stack[i]==1) return true;
            else if(visited[i]==0) return dfs(i, visited, stack);
        }
        stack[node] = false;
        return false;
    }


    bool contains_cycle(){
        std::vector<int> visited(V, 0);
        std::vector<int> stack(V, 0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(dfs(i, visited, stack)) return true;
            }
        }
        return false;
    }
};

int main(){
    Graph g(3);
    g.addEdge(0,1, false);
    g.addEdge(1,2, false);
    g.addEdge(0,2, false);
    g.printAdjList();
   cout<< g.contains_cycle() << endl;
    return 0;
}
