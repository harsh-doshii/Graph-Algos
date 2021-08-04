#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string name;
    list<string> neighbours;

    Node(string name){
        this->name = name;
    }
};


class Graph{
    unordered_map<string, Node*> m;  //pointer to list l

public:
    Graph(vector<string> data){
        for(auto i : data){
            m[i] = new Node(i);
        }
    }

    void addEdge(string i, string j, bool undir=true){
        m[i]->neighbours.push_back(j);
        if(undir){
            m[j]->neighbours.push_back(i);
        }
    }

    void printAdjList(){
        for(auto node : m){
            cout << node.first << "---> ";
            for(auto i : node.second->neighbours){
                cout << i << " ";
            }
                    cout << endl;

        }
    }
};

int main(){
    vector<string> cities = {"Delhi", "A", "B", "C"};
    Graph g(cities);
    g.addEdge("Delhi","A");
    g.addEdge("B","A");
    g.addEdge("B","C");
    g.addEdge("C","A");
    g.printAdjList();
    return 0;
}
