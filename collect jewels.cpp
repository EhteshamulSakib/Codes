#include<bits/stdc++.h>
using namespace std;

#define MXN 11
int Array[MXN][MXN];
int Path[MXN][MXN];
int Visited[MXN][MXN];
int MaxJewels;
int N;
int Ans[MXN][MXN];

//
//void PrintGrid(int Grid[MXN][MXN]){
//    cout<<"My Grid is ............"<<endl;
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            cout<<Grid[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//}


void SavePath(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Ans[i][j]=Path[i][j];
        }
    }
}
void Travel(int i,int j,int total){

    Path[i][j]=5;
    Visited[i][j]=1;
    if(i==0 and j==0 and Array[i][j]==2) total++;
    if(i==N-1 and j==N-1 ){
        if(total>MaxJewels){
            MaxJewels=total;
            SavePath();
        }
        Visited[i][j]=0;
        return ;
    }
    //cout<<Visited[i][j+1]<<endl;
    if((j+1)< N){

        if(!Visited[i][j+1] and Array[i][j+1]!=1){

            if(Array[i][j+1]==2){
                Travel(i,j+1,total+1);
            }
            else {
                Travel(i,j+1,total);
            }
            Path[i][j+1]=Array[i][j+1];
            //cout<<"Pore:"<<i<<" "<<j+1<<endl;

        }
    }
    if(j-1>=0){
        if(!Visited[i][j-1] and Array[i][j-1]!=1){
            if(Array[i][j-1]==2){
                Travel(i,j-1,total+1);
            }
            else {
                Travel(i,j-1,total);
            }
           Path[i][j-1]=Array[i][j-1];
            // cout<<"J-1: "<<j<<endl;
            // PrintGrid(Path);

        }
    }
    if(i+1<N){
        if(!Visited[i+1][j] and Array[i+1][j]!=1){
            if(Array[i+1][j]==2){
                Travel(i+1,j,total+1);
            }
            else {
                Travel(i+1,j,total);
            }
            Path[i+1][j]=Array[i+1][j];
            // cout<<"i+1: "<<i<<endl;
            // PrintGrid(Path);
        }
    }
    if(i-1>=0){
       // cout<<"The I-1 started..."<<endl;
        if(!Visited[i-1][j] and Array[i-1][j]!=1){
            if(Array[i-1][j]==2){
                Travel(i-1,j,total+1);
            }
            else {
                Travel(i-1,j,total);
            }
            Path[i-1][j]=Array[i-1][j];
            // cout<<"i-1: "<<i<<endl;
            // PrintGrid(Path);
         //   cout<<i-1<<" "<<j<<endl;
        }
    }
    Visited[i][j]=0;
   // PrintGrid(Path);
  // return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    cin>>N;
    MaxJewels=-1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Array[i][j];
            Path[i][j]=Array[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Visited[i][j]=0;
        }
    }

    Travel(0,0,0);
   cout<<"Case :"<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<Ans[i][j]<<" ";
        }
        cout<<endl;
    }
   cout<<MaxJewels<<endl;

    }
}

/*
1
6
0 1 2 1 0 0
0 1 0 0 0 1
0 1 2 1 2 1
0 2 0 1 0 2
0 1 0 1 0 1
2 0 2 1 0 0
*/
