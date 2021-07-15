#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;
int n,m;
int map[51][51];
bool visited[51][51];
int route[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; //남,동,북,서
int room_cnt=0,widest=0,merged_room=0; //방의 개수, 가장 넓은 방, 벽 제거 넓은 방
int main(){

    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));
    cin>>n>>m;

    // +1:서, +2:북, +4:동, +8:남 => 0~15
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++) cin>>map[i][j];
    }

    // 비트마스트
    // (남동북서)1111 - map[i][j] => 이동할 수 있는 방향
    // 0 1 2 3 동서남북,동남북,동서남,동남
    // 4 5 6 7 서남북,남북,서남,남
    // 8 9 10 11 동서북,동북,동서,동
    // 12 13 14 15 서북,북,서,X
    // bitset<4>(15-num).to_string()

    int x,y,dx,dy,cnt;
    string s;
    queue<pair<int,int>> q; //<x,y>
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j]) continue;

            q.push({i,j});
            visited[i][j]=1;
            cnt=0;
            while(!q.empty()){ //q 하나가 끝나면 방 하나가 끝난 것
                x=q.front().first, y=q.front().second;
                q.pop();
                cnt++;
                s=bitset<4>(15-map[x][y]).to_string();

                for(int k=0; k<4; k++){
                    if(s[k]=='0') continue;
                    dx = x+route[k][0], dy = y+route[k][1];
                    if(dx<=0||dy<=0||dx>m||dy>n||visited[dx][dy]) continue;
                    q.push({dx,dy});
                    visited[dx][dy]=1;
                }
            }
            room_cnt++;
            widest = max(widest,cnt);
        }
    }

    //3번
    //벽을 하나씩 없애보기
    for(int i=1; i<=m; i++) {
        for (int j = 1; j <= n; j++) {
            s=bitset<4>(15-map[i][j]).to_string();
            for(int k=0; k<s.size(); k++){
                if(s[k]=='0'){
                    memset(visited,0,sizeof(visited));
                    q.push({i,j});
                    visited[i][j]=1;
                    cnt=0;
                    map[i][j] -= pow(2,s.size()-1-k);
                    //벽 하나 없애기
                    //BFS
                    while(!q.empty()){
                        x=q.front().first, y=q.front().second;
                        q.pop();
                        cnt++;
                        s=bitset<4>(15-map[x][y]).to_string();

                        for(int p=0; p<4; p++){
                            if(s[p]=='0') continue;
                            dx=x+route[p][0], dy=y+route[p][1];
                            if(dx<=0||dy<=0||dx>m||dy>n||visited[dx][dy]) continue;
                            q.push({dx,dy});
                            visited[dx][dy]=1;
                        }
                    }
                    merged_room = max(merged_room,cnt);
                    //벽 다시 세우기
                    map[i][j] += pow(2,s.size()-1-k);
                }
            }
        }
    }


    cout<<room_cnt<<endl<<widest<<endl<<merged_room<<endl;


    return 0;
}