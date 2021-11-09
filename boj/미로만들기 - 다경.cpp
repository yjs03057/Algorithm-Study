#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct person{
    int x;
    int y;
};
queue<person> q;
int n;
char map[52][52];
bool visited[52][52];
int black[52][52]; //바꾼 검은 방 수
int route[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int main(){
    memset(map, ' ', sizeof(map));
    memset(visited, false, sizeof(visited));

    cin>>n;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cin>>map[i][j];
            black[i][j] = 987654321;
        }
    }

    //최소거리로 도달하는 것이 아닌, black을 최소로 변경하고 도달하는 것이 목표!!
    person p;
    p.x=1, p.y=1;
    visited[1][1]=1;
    black[1][1]=0;
    q.push(p);
    int x,y,dx,dy,dark;
    while(!q.empty()){
        p = q.front();
        q.pop();
        x=p.x, y=p.y;
        if(x==n&&y==n) continue;

        for(int i=0; i<4;  i++){
            dx=x+route[i][0], dy=y+route[i][1];
            dark=black[x][y];
            if(dx<1||dy<1||dx>n||dy>n) continue;

            if(map[dx][dy]=='0'){ //검은 방
                dark=dark+1;
            }

            if(visited[dx][dy]){
                //이미 방문 -> black 값 비교
                if(black[dx][dy]>dark){
                    black[dx][dy] = dark;
                }
                else continue;
            }
            else{
                black[dx][dy] = min(dark, black[dx][dy]);
                visited[dx][dy]=1;
            }
            p.x=dx, p.y=dy;
            q.push(p);
        }
    }

    //print
//    for(int i=1; i<n+1; i++){
//        for(int j=1; j<n+1; j++){
//            cout<<black[i][j]<<'\t';
//        }
//        cout<<endl;
//    }

    cout<<black[n][n];

    return 0;
}