#include <iostream>
using namespace std;
#define ll long long int

struct Point{
    int x,y;
};

struct Node
{
    Point data;
    Node *next;
};
Node *front = NULL;
Node *rear = NULL;

void Push(int x,int y)
{
    Node *temp = new Node();
    temp->data.x = x;
    temp->data.y=y;
    temp->next = NULL;
    if (front == NULL and rear == NULL)
    {
        front = rear = temp;
    }
    else
    {

        rear->next = temp;
        rear = temp;
    }
}
void Pop()
{
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;

}
Point Front(){
    return front->data;
}

void Print()
{
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data.x<<" "<<temp->data.y;
        temp = temp->next;
    }
}

int N, M;
int Grid[100][100];
bool visited[100][100];
int Level[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y)
{
    return (x >= 1 and x <= N and y >= 1 and y <= M and !visited[x][y] and Grid[x][y]);
}

void BFS(int srx, int sry)
{
    visited[srx][sry] = true;
    Push(srx,sry);

    Level[srx][sry] = 0;

    while (front!=NULL)
    {
        Point P;
        P = Front();
        Pop();

        int ux = P.x, uy = P.y;

        for (int i = 0; i < 4; i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            // cout<<vx<<" "<<vy<<endl;
            if (valid(vx, vy))
            {
                //cout<<vx<<" "<<vy<<" "<<ux<<" "<<uy<<endl;
                if (ux == vx)
                    Level[vx][vy] = Level[ux][uy] + 0;
                if (uy == vy)
                    Level[vx][vy] = Level[ux][uy] + 1;
                visited[vx][vy] = true;
                Push(vx,vy);
            }
        }
    }
}

int main()
{

        cin>>N>>M;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin>>Grid[i][j];
            }
        }
        int srx,sry,desx,desy;
        cin>>srx>>sry>>desx>>desy;
        BFS(srx,sry);
        //cout<<srx<<" "<<sry<<endl;
       cout<<Level[desx][desy]<<endl;

      for(int i=1;i<=N;i++){
          for(int j=1;j<=M;j++){
              cout<<Level[i][j]<<" ";
          }
          cout<<endl;
      }



}

/*
4 5
1 1 1 1 1
1 1 0 1 0
1 1 1 1 0
1 1 1 1 1
1 1
2 4

10 10
1 1 0 1 1 0 1 0 1 1
0 1 1 1 1 1 0 1 0 1
1 0 1 1 1 0 1 1 0 0
0 1 0 1 1 1 0 1 0 1
1 1 1 1 1 0 0 0 1 0
0 0 1 1 0 1 1 1 1 1
1 1 1 0 0 0 1 1 0 1
1 1 1 1 0 1 1 0 1 1
0 0 0 1 1 1 0 1 1 1
1 1 1 1 0 0 0 1 1 1
1 1
10 10
*/
