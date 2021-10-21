#include <iostream>
using namespace std;

int N,M,x,y,K;
int map[20][20];
int order[1000];

struct dice{
    int top=0;
    int north=0;
    int east=0;
    int west=0;
    int south=0;
    int bottom=0;
};
dice dc;

void moveEast(){
    y++;
    if(y>=M){
        y--;
        return;
    }
    int tmp=dc.top;
    dc.top=dc.west;
    dc.west=dc.bottom;
    dc.bottom=dc.east;
    dc.east=tmp;

    if(map[x][y]==0) map[x][y] = dc.bottom;
    else{
        dc.bottom = map[x][y];
        map[x][y]=0;
    }
    cout<<dc.top<<'\n';
    return;
}
void moveWest(){
    y--;
    if(y<0){
        y++;
        return;
    }
    int tmp=dc.top;
    dc.top=dc.east;
    dc.east=dc.bottom;
    dc.bottom=dc.west;
    dc.west=tmp;

    if(map[x][y]==0) map[x][y] = dc.bottom;
    else{
        dc.bottom = map[x][y];
        map[x][y]=0;
    }
    cout<<dc.top<<'\n';
    return;
}
void moveNorth(){
    x--;
    if(x<0){
        x++;
        return;
    }
    int tmp=dc.top;
    dc.top=dc.south;
    dc.south=dc.bottom;
    dc.bottom=dc.north;
    dc.north=tmp;

    if(map[x][y]==0) map[x][y] = dc.bottom;
    else{
        dc.bottom = map[x][y];
        map[x][y]=0;
    }
    cout<<dc.top<<'\n';
    return;
}
void moveSouth(){
    x++;
    if(x>=N){
        x--;
        return;
    }
    int tmp=dc.top;
    dc.top=dc.north;
    dc.north=dc.bottom;
    dc.bottom=dc.south;
    dc.south=tmp;

    if(map[x][y]==0) map[x][y] = dc.bottom;
    else{
        dc.bottom = map[x][y];
        map[x][y]=0;
    }
    cout<<dc.top<<'\n';
    return;
}
void solve(){

    for(int i=0; i<K; i++){
        //order[i]
        // 1: 동, 2: 서, 3: 북, 4: 남
        switch (order[i]) {
            case 1:
                moveEast();
                break;
            case 2:
                moveWest();
                break;
            case 3:
                moveNorth();
                break;
            case 4:
                moveSouth();
                break;
        }
    }

    return;
}
int main(){

    cin>>N>>M>>x>>y>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<K; i++){
        cin>>order[i];
    }

    solve();

    return 0;
}