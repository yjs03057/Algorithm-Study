#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, fish=0, ans=0;
int map[20][20];
int route[4][2]={{-1,0},{0,-1},{0,1},{1,0}}; //위 왼 오 아
bool visited[20][20];
struct babyShark{
    int x;
    int y;
    int size=2;
    int grow=2; //0마리 되면 size++
    int moved=0;
};
struct compare{
    bool operator()(const babyShark& bs1, const babyShark& bs2){
        if(bs1.moved==bs2.moved){
            if(bs1.x==bs2.x) return bs1.y>bs2.y;
            return bs1.x>bs2.x;
        }
        return bs1.moved>bs2.moved;
    }
};
priority_queue<babyShark,vector<babyShark>,compare> pq;
int main(){
    memset(map, 0, sizeof(map));

    cin>>N;
    babyShark bs;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            // 0: 빈칸
            // 1,2,3,4,5,6: 칸에 있는 물고기의 크기
            // 9: 아기 상어의 위치
            cin>>map[i][j];
            if(map[i][j]==9){
                bs.x=i, bs.y=j;
                map[i][j]=0;
            }
            else if(map[i][j]>0) fish++;
        }
    }

    memset(visited, false, sizeof(visited));
    pq.push(bs);
    visited[bs.x][bs.y]=1;
    int x,y,dx,dy,s,g,moved,qsize=pq.size(),tmps;
    bool flag=false;

    while(qsize){
        x=pq.top().x, y=pq.top().y;
        s=pq.top().size, g=pq.top().grow;
        moved = pq.top().moved;
        pq.pop();
        for(int i=0; i<4; i++){
            dx=x+route[i][0], dy=y+route[i][1];
            if(dx<0||dy<0||dx>=N||dy>=N) continue;
            if(visited[dx][dy]) continue;
            if(map[dx][dy]==0 || map[dx][dy]==s){
                //빈 공간 or 같은 크기의 물고기
                visited[dx][dy]=1;
                bs.x=dx, bs.y=dy, bs.size=s, bs.grow=g;
                bs.moved= moved+1;
                pq.push(bs);
            }
            else if(map[dx][dy]<bs.size){
                //먹을 수 있는 물고기
                visited[dx][dy]=1;
                bs.x=dx, bs.y=dy;
                bs.size=s, bs.grow=g;
                bs.moved= moved+1;
                pq.push(bs);
                flag=1;
            }
        }
        qsize--;

        if(qsize==0 && flag){
            //먹을 수 있는 물고기 먹기
            fish--;
            while(1){
                dx=pq.top().x, dy=pq.top().y;
                tmps=pq.top().size, g=pq.top().grow;
                moved=pq.top().moved;
                pq.pop();
                if(map[dx][dy]==0) continue;
                else if(map[dx][dy]<s){
                    map[dx][dy]=0;
                    break;
                }
            }
            //pq clear
            while(!pq.empty()) pq.pop();

            bs.x=dx, bs.y=dy;
            if(g-1==0) bs.grow = bs.size = tmps+1;
            else bs.grow= g-1;
            ans = max(ans, moved);
            pq.push(bs);

            qsize = pq.size();
            memset(visited, false, sizeof(visited));
            visited[dx][dy]=1;
            flag=0;

            //물고기 다 먹음
            if(fish==0){
                cout<<ans;
                return 0;
            }
        }
        else if(qsize==0) qsize=pq.size();
    }

    cout<<ans;

    return 0;
}