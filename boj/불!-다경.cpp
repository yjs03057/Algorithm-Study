#include <iostream>
#include <cstring>
using namespace std;

int R,C,ans=987654321;
char map[1001][1001];
char cp[1001][1001];
bool f_visited[1001][1001];
bool j_visited[1001][1001];
int moved[1001][1001];
int route[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int main(){
    bool flag=false;
    int dx,dy;

    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++) cin>>map[i][j];
    }

    memset(moved, 0, sizeof(moved));
    memset(j_visited,false, sizeof(j_visited));
    memset(f_visited,false, sizeof(f_visited));
    while(1){
        flag=false;
        memcpy(cp, map, sizeof(cp));
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                //불
                if(map[i][j]=='F'){
                    if(f_visited[i][j]) continue;
                    f_visited[i][j]=1;
                    for(int r=0; r<4; r++){
                        dx=i+route[r][0], dy=j+route[r][1];
                        if(dx<0||dy<0||dx>=R||dy>=C) continue;
                        if(cp[dx][dy]!='#'){
                            cp[dx][dy]='F';
                        }
                    }
                }
                    //지훈
                else if(map[i][j]=='J'){
                    if(j_visited[i][j]) continue;
                    j_visited[i][j]=1;
                    for(int r=0; r<4; r++){
                        dx=i+route[r][0], dy=j+route[r][1];
                        if(dx<0||dy<0||dx>=R||dy>=C){ //탈출
                            ans = min(ans,moved[i][j]+1);
                            flag=true;
                            continue;
                        }
                        if(moved[dx][dy]<moved[i][j]+1
                           &&cp[dx][dy]=='.'){
                            moved[dx][dy] = moved[i][j]+1;
                            cp[dx][dy]='J';
                            flag=true;
                        }
                    }
                }
            }
        }
        memcpy(map, cp, sizeof(map));
        //print
//        for(int i=0; i<R; i++){
//            for(int j=0; j<C; j++){
//                cout<<map[i][j];
//            }
//            cout<<endl;
//        }
//        cout<<endl;
        if(!flag) break;
    }

    if(ans==987654321){
        cout<<"IMPOSSIBLE";
    }
    else cout<<ans;

    return 0;
}