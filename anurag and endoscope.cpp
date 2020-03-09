#include <iostream>
using namespace std;

#define MAXN 1002
#define MAXM 1002
#define INFINITY 9999

struct Point
{
    int v;
    int h;
    int dis=0;
};

int totalPushed = 0;
Point queue[1000010];

int head = 0, tail = -1;
Point get()
{
    return queue[head];
}
Point pop()
{
    Point p = queue[head];
    head++;
    return p;
}
void push(Point p)
{
    tail++;
    queue[tail] = p;
}
bool isEmpty()
{
    if (head > tail)
        return true;
    return false;
}
bool notEmpty()
{
    if (head <= tail)
        return true;
    return false;
}

int N, M, SV, SH, L;
bool visited[MAXN][MAXM];
int graph[MAXN][MAXM];
// int dis[MAXN][MAXM];

void visit(int v, int h, int dis){
    Point p;
    p.v=v;
    p.h=h;
    p.dis=dis+1;

    push(p);
    totalPushed++;
    // cout << v << " " << h << " " << totalPushed << "\n";

    visited[v][h]=true;
}
void goUp(Point p){
    if(p.v - 1 < 0) return;
    int v = p.v - 1;
    int h = p.h;
    if(visited[v][h])   return;

    if(graph[v][h] == 1 || graph[v][h] == 2 || graph[v][h] == 5 || graph[v][h] == 6)
        visit(v, h, p.dis);
}
void goDown(Point p){
    if(p.v + 1 >= N) return;
    int v = p.v + 1;
    int h = p.h;
    if(visited[v][h])   return;

    if(graph[v][h] == 1 || graph[v][h] == 2 || graph[v][h] == 4 || graph[v][h] == 7)
        visit(v, h, p.dis);
}
void goLeft(Point p){
    if(p.h - 1 < 0) return;
    int v = p.v;
    int h = p.h - 1;
    if(visited[v][h])   return;

    if(graph[v][h] == 1 || graph[v][h] == 3 || graph[v][h] == 4 || graph[v][h] == 5)
        visit(v, h, p.dis);
}
void goRight(Point p){
    if(p.h + 1 >= M) return;
    int v = p.v;
    int h = p.h + 1;
    if(visited[v][h])   return;

    if(graph[v][h] == 1 || graph[v][h] == 3 || graph[v][h] == 6 || graph[v][h] == 7)
        visit(v, h, p.dis);
}

int result() {
    if(graph[SV][SH]!=0)
        visit(SV, SH, 0);

    while(notEmpty()){
        Point current = pop();
        if(current.dis == L)
            continue;

        int type = graph[current.v][current.h];

        if(type == 1){
            goUp(current);
            goDown(current);
            goLeft(current);
            goRight(current);
        }
        else if(type == 2){
            goUp(current);
            goDown(current);
        }
        else if(type == 3){
            goLeft(current);
            goRight(current);
        }
        else if(type == 4){
            goUp(current);
            goRight(current);
        }
        else if(type == 5){
            goRight(current);
            goDown(current);
        }
        else if(type == 6){
            goLeft(current);
            goDown(current);
        }
        else if(type == 7){
            goUp(current);
            goLeft(current);
        }
    }

    return totalPushed;
}

void clear()
{
    head = 0;
    tail = -1;
    totalPushed=0;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            visited[i][j] = false;
            // dis[i][j]=INFINITY;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> N >> M >> SV >> SH >> L;
        clear();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> graph[i][j];
            }
        }

        cout << result() << "\n";
    }

    return 0;
}
