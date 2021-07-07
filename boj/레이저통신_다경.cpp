#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int W,H, ans=987654321;
char arr[102][102];
int visited[102][102]; //거울 수 저장
int route[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //우,하,좌,상
vector<pair<int,int>> Cs;
struct laser{
    int x;
    int y;
    int dir; //0:우, 1:하, 2:좌, 3:상
    int cnt;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<102; i++){
        for(int j=0; j<102; j++) visited[i][j] = 10001;
    }
    queue<laser> q;

    cin>>W>>H;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'C') Cs.push_back({i,j});
        }
    }

    int start_x=Cs[0].first, start_y=Cs[0].second;
    int end_x=Cs[1].first, end_y=Cs[1].second;
    int x,y,cnt,dx,dy,dir;
    laser l;

    //첫 이동
    for(int i=0; i<4; i++){
        dx = start_x+route[i][0], dy = start_y+route[i][1];
        if(dx<=0 || dy<=0 || dx>H || dy>W) continue;
        if(arr[dx][dy]=='.'){
            l.x = dx, l.y = dy, l.dir = i, l.cnt = 0;
            visited[dx][dy]=0;
            q.push(l);
        }
    }

    while(!q.empty()){
        x = q.front().x, y = q.front().y;
        dir = q.front().dir, cnt = q.front().cnt;
        q.pop();
        if(cnt > visited[x][y]) continue;

        for(int i=0; i<4; i++){
            dx = x+route[i][0], dy = y+route[i][1];
            if(dx<=0 || dy<=0 || dx>H || dy>W) continue;
            if(abs(dir-i)==2) continue; //왔던 방향으로 돌아가지 않기

            if(dx==end_x&&dy==end_y){
                //도착 지점
                if(dir==i) l.cnt = cnt;
                else l.cnt = cnt+1; //거울 셋팅
                ans = min(ans, l.cnt);
                break;
            }

            if(arr[dx][dy]=='.'){
                //이동할 수 있는 칸
                l.x = dx, l.y = dy, l.dir = i;
                if(dir==i) l.cnt = cnt;
                else l.cnt = cnt+1; //거울 셋팅

                if(visited[dx][dy]>=l.cnt){
                    //더 적거나 같은 거울 사용해서 해당 칸으로 가는 경우
                    q.push(l);
                    visited[dx][dy] = l.cnt;
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

