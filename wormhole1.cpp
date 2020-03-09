#include<iostream>
using namespace std;
#define ll long long int

struct Node{
  int data;
  Node * next;
};
Node * front=NULL;
Node * rear=NULL;


void push(int x)
{
    Node * temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if(front==NULL and rear==NULL){
      front=rear=temp;
    }
    else {
      rear->next=temp;
      rear=temp;
    }
}


int pop() {
    if(front==rear){
      front=rear=NULL;
    }
    else{
      front=front->next;
    }
}

int Front(){
  return front->data;
}

int Mat[100][100];

int abs(int x,int y){
      if(x>y){
        return (x-y);
      }
      else{
        return (y-x);
      }
}
int Dis(int x1,int y1,int x2,int y2){
    return (abs(x1,x2)+abs(y1,y2));
}
struct Point{
    int x,y;
}P[100];

int dist[100];
bool sptSet[100];

void BFS(int src,int node) {

    for(int i=1;i<node;i++) dist[i]=100000007;
    dist[src] = 0;
    push(src);

    while(front!=NULL) {
       int u = Front();
        pop();

        for(int i=1;i<node;i++){
//            if(u!=2)
                int v = i;
            if(dist[v] > dist[u] + Mat[u][v] && u!=v){
                dist[v] = dist[u] + Mat[u][v];
//                if(u==1)
                push(v);
            }

        }

    }

}

void Initilization(){
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      Mat[i][j]=-1;
    }
  }
}

int main() {
   Initilization();
   int sx,sy,dx,dy;
   cin>>sx>>sy>>dx>>dy;
   int n;cin>>n;
   int node=3;
   int k=0;
   int Start_Wx,Start_Wy,End_Wx,End_Wy;
   for(int i=0;i<n;i++) {

   cin>>Start_Wx>>Start_Wy>>End_Wx>>End_Wy;
   P[node].x=Start_Wx;
   P[node].y=Start_Wy;

   int w1=node;
   Mat[1][node]=Dis(sx,sy,Start_Wx,Start_Wy);
   Mat[node][2]=Dis(dx,dy,Start_Wx,Start_Wy);

//    Mat[node][1]=Dis(sx,sy,Start_Wx,Start_Wy);
//    Mat[node][2]=Dis(dx,dy,Start_Wx,Start_Wy);

   node=node+1;
   Mat[1][node]=Dis(sx,sy,End_Wx,End_Wy);
   Mat[node][2]=Dis(dx,dy,End_Wx,End_Wy);

   P[node].x=End_Wx;
   P[node].y=End_Wy;

//    Mat[node][1]=Dis(sx,sy,End_Wx,End_Wy);
//    Mat[node][2]=Dis(dx,dy,End_Wx,End_Wy);

   int w2=node;
   node=node+1;

   Mat[w1][w2]=0;
   Mat[w2][w1]=0;

   }
   Mat[1][2]=Dis(sx,sy,dx,dy);
//    Mat[2][1]=Dis(sx,sy,dx,dy);



  for(int i=3;i<=node-1;i++){
    for(int j=i+1;j<=node-1;j++){
      {
        if(Mat[i][j]!=0){
        Mat[i][j]=Dis(P[i].x,P[i].y,P[j].x,P[j].y);
        Mat[j][i]=Dis(P[i].x,P[i].y,P[j].x,P[j].y);
        }
      }
    }
  }

  cout<<"My conventional Matrix .is."<<endl;

   for(int i=1;i<=node-1;i++){
     for(int j=1;j<=node-1;j++){
       cout<<Mat[i][j]<<" ";
     }
     cout<<endl;
   }

  BFS(1,node);

cout<<endl;
//  for(int i=1;i<node;i++)
    cout<<dist[2]<<' ';

}

/*
9 9 100 100
3
10 10 120 120
10 1 120 100
6 8 150 180
*/
