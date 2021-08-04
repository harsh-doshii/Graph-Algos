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

    void printAdjList(){
        for(int i =0;i<V;i++){
            cout << i << "---> ";
            for(auto node : l[i]){
                cout << node << " ";
            }
            cout << endl;
        }
    }

    void topo_sort(){
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto node : l[i]){
                indegree[node]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                int k = q.front();
                cout << k << " ";
                q.pop();
                for(auto t : l[k]){
                    indegree[t]--;
                    if(indegree[t]==0) q.push(t);
                }
            }
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
