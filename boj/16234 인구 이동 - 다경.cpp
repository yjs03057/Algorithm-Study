#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int n,l,r, ans=0;
int map[52][52];
bool visited[52][52];
int route[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
queue<pair<int,int>> q;
vector<pair<vector<pair<int,int>>,int>> uni; //연합국: (연합국가들(x,y), 인구수)
int open_border(int x, int y){
    int flag=0;
    vector<pair<int,int>> tmp;
    tmp.push_back(make_pair(x,y));
    q.push(make_pair(x,y));
    visited[x][y] = 1;

    int dx,dy, sum=map[x][y], cnt=1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            dx = x+route[i][0];
            dy = y+route[i][1];

            // 1. l명 <= 인구 차이 <= r명 -> 국경선 열기 (연합 생성)
            if(dx>0 && dx<=n && dy>0 && dy<=n && !visited[dx][dy]
            && abs(map[x][y] - map[dx][dy]) >= l && abs(map[x][y] - map[dx][dy]) <= r){
                //연합에 추가됨
                sum += map[dx][dy];
                cnt++;
                visited[dx][dy] = 1;
                tmp.push_back(make_pair(dx,dy));
                q.push(make_pair(dx,dy));
                flag=1;
            }
        }
    }

    if(flag){
        // 2. 인구이동 -> 연합의 인구 수 / 연합 국가 개수 (소수 버리기)
        int people = sum / cnt;
        uni.push_back(make_pair(tmp,people)); //(연합 국가들, 인구 수)
        return 1;
    }

    return 0;
}
int main(){
    int move_flag=0, ret=0, x,y, people=0;

    cin>>n>>l>>r;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
        }
    }

    while(1){ //인구이동이 없을 때 까지
        memset(visited, false, sizeof(visited));
        move_flag=0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!visited[i][j]){
                    ret = open_border(i,j);
                    move_flag = max(move_flag,ret); //움직였으면 1이 들어가겠지
                }
            }
        }

        //인구이동 없었으면 끝내기
        if(move_flag==0) break;

        // 2. 인구이동 갱신
        // 각 연합은 uni에 저장되어 있음
        for(int i=0; i<uni.size(); i++){
            people = uni[i].second;
            for(int j=0; j<uni[i].first.size(); j++){
                x = uni[i].first[j].first;
                y = uni[i].first[j].second;
                map[x][y] = people;
            }
        }

        // 3. 국경선 닫기 (연합 해체)
        uni.clear();
        ans++;
    }

    cout<<ans;

    return 0;
}