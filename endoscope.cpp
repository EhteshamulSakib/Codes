#include<iostream>
using namespace std;
#define ll long long int

  int up[]={0,1,1,0,0,1,1,0};
  int down[]={0,1,1,0,1,0,0,1};
  int Left[]={0,1,0,1,1,1,0,0};
  int Right[]={0,1,0,1,0,0,1,1};

  int Maze[1010][1010];
  bool visit[1010][1010];
  int dist[1010][1010];
  int N,M,R,C,L;

  struct Point{
      int x,y;

  };

  struct Node {
      Point data;
      Node * next;
  };

  Node * front=NULL;
  Node * rear=NULL;

  void Push( Point p){
      Node * temp=new Node();
      temp->data.x=p.x;
      temp->data.y=p.y;
      temp->next=NULL;

      if(front==NULL and rear==NULL ){
          front=rear=temp;
      }
      else {
          rear->next=temp;
          rear=temp;
      }
  }

  void Pop(){
      if(front==rear) {
          front=rear=NULL;
      }
      else {
          front=front->next;
      }
  }

  Point Front(){
      return front->data;
  }

  void BFS(){


        if(Maze[R][C]!=0){
            Push({R,C});
            visit[R][C]=1;
            dist[R][C]=1;
        }

        while(front!=NULL){

            Point P;
            P=Front();
            Pop();
            int x=P.x;
            int y=P.y;

            if(x-1>=0 and Maze[x-1][y] and  up[Maze[x-1][y]]==1 and down[Maze[x][y]]==1 and !visit[x-1][y]){
                int d=dist[x][y]+1;
                if(d<=L){
                    Push({x-1,y});
                    visit[x-1][y]=1;
                    dist[x-1][y]=d;
                }
            }

            if(x+1<N and Maze[x+1][y] and  !visit[x+1][y] and down[Maze[x+1][y]] and up[Maze[x][y]]){
                int d=dist[x][y]+1;
                if(d<=L){
                    dist[x+1][y]=d;
                    visit[x+1][y]=1;
                    Push({x+1,y});
                }
            }

            if(y-1>=0 and  Maze[x][y] and !visit[x][y-1] and Right[Maze[x][y]] and Left[Maze[x][y-1]]){
                int d=dist[x][y]+1;
                if(d<=L) {
                    visit[x][y-1]=1;
                    dist[x][y-1]=d;
                    Push({x,y-1});
                }
            }

            if(y+1<M and Maze[x][y+1] and !visit[x][y+1] and Left[Maze[x][y]] and Right[Maze[x][y+1]]){
                int d=dist[x][y]+1;
                if(d<=L){
                    dist[x][y+1]=d;
                    visit[x][y+1]=1;
                    Push({x,y+1});
                }
            }
        }
            int cnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(dist[i][j]>0) cnt++;
            }

        }
        cout<<cnt<<endl;

    }


int main() {

    int t;
    cin>>t;
    while(t--){
        cin>>N>>M>>R>>C>>L;

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>Maze[i][j];
                visit[i][j]=0;
                dist[i][j]=0;
            }

    }

    BFS();
    }
}
