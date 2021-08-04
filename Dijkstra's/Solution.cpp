#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<pair<int, int>>* l;  //pointer to list l

public:
    Graph(int v){
        V = v;
        l = new list<pair<int, int>>[V]; //array containing V lists, pointer to that array is l
    }

    void addEdge(int i, int j, int w, bool undir=true){
        l[i].push_back({w, j});
        if(undir){
            l[j].push_back({w, i});
        }
    }


    void dijkstra(int source){
        vector<int> distance(V, INT_MAX);
        distance[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, source});
        while(!q.empty()){
            pair<int, int> p = q.top();
            q.pop();
            int node = p.second;
            int d_node = p.first;
            if (distance[node] != d_node) continue;
            for(auto i : l[node]){
                if(d_node+i.first < distance[i.second]){
                    distance[i.second] = d_node + i.first;
                    q.push({distance[i.second], i.second});
                }
            }
        }
        sort(distance.begin(), distance.end());
        for (int i = 0; i < V; i++) {
            cout << distance[i] << " ";
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(0,2,4);
    g.addEdge(0,2,2);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);
    g.dijkstra(0);
    return 0;
}
