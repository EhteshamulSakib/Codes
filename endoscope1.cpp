#include<iostream>
using namespace std;

int n,m,x,y,l,ans;
int grid[1001][1001];
int vis[1001][1001];
int dis[1001][1001];

int validposition[4][4]={
                         {1,3,4,5},   //left
                         {1,3,6,7},   //right
                         {1,2,5,6},   //up
                         {1,2,4,7},   //down
};

int direction[7][4]={
                     {1,1,1,1},
                     {0,0,1,1},
                     {1,1,0,0},
                     {0,1,1,0},
                     {0,1,0,1},
                     {1,0,0,1},
                     {1,0,1,0},
};

int check(int d,int x,int y){
                             int p=grid[x][y];
//                             if(vis[x][y]==1) return 0;
                             for(int i=0;i<4;i++){
                                if(validposition[d][i]==p){
                                    return 1;
                                }
                             }
                             return 0;
}

void dfs(int x,int y,int len){
                    int pipe=grid[x][y];
                    if(pipe >0 && len+1<=l){
                     if((y-1)>=0 && grid[x][y-1]>0 && check(0,x,y-1)==1 && check(1,x,y)==1 && vis[x][y-1]!=1){
//                        dis[x][y-1]=1;
//                        vis[x][y-1]=1;
                        dfs(x,y-1,len+1);
                    }
                     if((y+1)<m && grid[x][y+1]>0 && check(1,x,y+1)==1 && check(0,x,y)==1 && vis[x][y+1]!=1){
//                        dis[x][y+1]=1;
//                        vis[x][y+1]=1;
                        dfs(x,y+1,len+1);
                    }
                    if((x-1)>=0 && grid[x-1][y]>0 && check(2,x-1,y)==1 && check(3,x,y)==1 && vis[x-1][y]!=1){
//                        dis[x-1][y]=1;
//                        vis[x-1][y]=1;
                        dfs(x-1,y,len+1);
                    }
                    if((x+1)<n && grid[x+1][y]>0 && check(3,x+1,y)==1 && check(2,x,y)==1 && vis[x+1][y]!=1){
//                        dis[x+1][y]=1;
//                        vis[x+1][y]=1;
                        dfs(x+1,y,len+1);
                    }
                }



}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>x>>y>>l;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
                vis[i][j]=0;
                dis[i][j]=0;
            }
        }
        ans=0;
//        vis[x][y]=1;
//        dis[x][y]=1;
        dfs(x,y,1);
//
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//               if(dis[i][j]>1) ans++;
//            }
//        }
        cout<<ans<<endl;
    }
}

/*
2
5 6 2 1 3
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0

5 6 2 2 6
3 0 0 0 0 3
2 0 0 0 0 6
1 3 1 1 3 1
2 0 2 0 0 2
0 0 4 3 1 1
*/





