#include<iostream>
using namespace std;
#define ll long long int

int Grid[100][100];
int Node,Edge;
bool visited[100];
bool color[100];

bool Bipartite(int u){

    for(int  v=0;v<Node;v++){
        if( Grid[u][v]){
            if(!visited[v]){
                visited[v]=true;
                color[v]=  !(color[u]);
                if(!Bipartite(v)) return false;
            }
            else if(color[v]==color[u]) return false;
         }
   }

   return true;
}

int main() {

    cin>>Node>>Edge;
    for(int i=0;i<Edge;i++){
        int x,y;
        cin>>x>>y;
        Grid[x][y]=1;
        Grid[y][x]=1;
    }

    // for(int i=1;i<=Node;i++){
    //     for(int j=1;j<=Node;j++){
    //         cout<<Grid[i][j]<<" ";

    //     }
    //     cout<<endl;
    // }

    visited[1]=true;
    color[1]=1;
    if(Bipartite(1)) cout<<"Bipartite"<<endl;
    else cout<<"Not ....."<<endl;


}
