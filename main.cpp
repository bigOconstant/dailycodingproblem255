#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

bool dfs(vector<int> graph[],int size,int end,int current,bool visited[]){
    if(current == end){
        return true;
    }

    visited[current] = true;

    for(auto it = graph[current].begin(); it< graph[current].end(); ++it ){
        if(!visited[(*it)]){
            int c = (*it);
            bool found = dfs(graph,size,end,c,visited);
            if(found){
                return true;
            } 
        }
    }

    return false;
}
void EraseArray(int V,bool vt[]){
    for(int i = 0; i < V; ++i){
        vt[i] = false;
    }
}

int main(){

    int V = 4;
    vector<int> adj[V];
    adj[0].push_back(0);
    adj[0].push_back(1);
    adj[0].push_back(3);
    
    adj[1].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(2);
    adj[3].push_back(3);

    bool visited[V];

    for(int i = 0; i < V; ++i){

        for(int j = 0; j < V; ++j){
            cout<<"["<<dfs(adj,V,j,i,visited)<<"]";
            EraseArray(V,visited);
            
        }
        cout<<"\n";
    }
    
    
}