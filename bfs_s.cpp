#include<iostream>
#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited ;

void parallel_bfs(int v ){
    queue<int> s;
    s.push(v);
    visited[v]=true;

    while(s.empty()==false){

        int curr = s.front();
        cout<<curr<<" ";
        s.pop();

        #pragma omp parallel for
        for(int i =0; i <graph[curr].size(); i++){
            int child = graph[curr][i];
            if(visited[child]==false){
                visited[child]=true;
                s.push(child);
            }
        }
    }
}


int main (){

    int v, e;
     cout<<"Vertices : ";
     cin>>v;
     cout<<"Edges : ";
     cin>>e;
     
     graph.resize(v);
     visited.resize(v);

     int x,y;
     for(int i =0 ; i <e ; i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
     }

     for(int i =0 ; i <v; i++){
        visited[i]=false;
     }

     parallel_bfs(0);


    return 0;

}