#include<iostream>
using namespace std;

int grid[100][100];
bool visit[100][100];
int dist[100][100];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int N,M;


struct Point{
    int x,y;
};


Point arr[101];
int front=0,rear=0;


void Push(int x,int y){
            arr[front].x=x;
            arr[front].y=y;
            front++;
}
Point Pop(){
          Point P=arr[rear];
          rear++;
          return P;
}
bool valid(int x, int y)
{
    return (x >= 1 and x <= N and y >= 1 and y <= M and !visit[x][y] and grid[x][y]);
}



void BFS(int sx,int sy){
       visit[sx][sy]=true;
       Push(sx,sy);
       dist[sx][sy]=0;

       while(front>=rear){
          Point P;
          P=Pop();
          int ux=P.x,uy=P.y;
          for(int i=0;i<4;i++){
            int vx=ux+dx[i];
            int vy=uy+dy[i];
            if(valid(vx,vy)){
            if(ux==vx){
                dist[vx][vy]=dist[ux][uy];
            }
            if(uy==vy){
                dist[vx][vy]=dist[ux][uy]+1;
            }
            visit[vx][vy]=true;
            Push(vx,vy);
          }
       }
}
}

int main(){
     cin>>N>>M;
     for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>grid[i][j];
        }
     }
//      for(int i=1;i<=N;i++){
//        for(int j=1;j<=M;j++){
//            dist[i][j]=0;
//        }
//     }

        int srx,sry,dsx,dsy;
        cin>>srx>>sry>>dsx>>dsy;
        BFS(srx,sry);
        cout<<dist[dsx][dsy]<<endl;;


      }

