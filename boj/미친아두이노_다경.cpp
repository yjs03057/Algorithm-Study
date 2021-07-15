#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
int R,C;
char map[101][101];
int cnt[101][101];
int X=0; //종수가 게임이 끝나기 전까지 이동한 횟수
int route[10][2] = {{0,0},
                    {1,-1},{1,0},{1,1},{0,-1},
                    {0,0},
                    {0,1},{-1,-1},{-1,0},{-1,1}};
string input;
pair<int,int> Jongsu;
vector<pair<int,int>> Arduinos;
set<pair<int,int>> s;
int main(){

    cin>>R>>C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin>>map[i][j]; // . : 빈 칸, R : 미친 아두이노, I : 종수의 위치
            if(map[i][j]=='I') Jongsu = {i,j};
            else if(map[i][j]=='R') Arduinos.push_back({i,j});
        }
    }
    cin>>input;

    //1. 종수의 아두이노 이동 -> 미친 아두이노 칸으로 이동 시 LOSE
    //2. 미친 아두이노 이동(종수 아두이노랑 가까워지는 방향으로)
    //      -> 종수 칸이면 종수 LOSE
    //      -> 해당 칸에 미친 아두이노 >=2 모두 파괴

    int dx,dy,mindiff,idx;
    vector<pair<int,int>>::iterator it;
    for(int i=0; i<input.size(); i++){
        //종수 이동
        X++;
        dx = Jongsu.first+route[input[i]-'0'][0];
        dy = Jongsu.second+route[input[i]-'0'][1];
        if(map[dx][dy]=='.' || map[dx][dy]=='I'){
            map[Jongsu.first][Jongsu.second]='.';
            map[dx][dy] = 'I';
            Jongsu = {dx,dy};
        }
        else{ //R
            //게임 종료 - 종수 LOSE
            cout<< "kraj "<<X;
            return 0;
        }

        //미친 아두이노 이동
        memset(cnt, 0, sizeof(cnt));
        s.clear();
        for(int j=0; j<Arduinos.size(); j++){

            //이동 방향 정하기
            mindiff = 987654321;
            for(int r=1; r<=9; r++){
                dx=abs(Jongsu.first-(Arduinos[j].first+route[r][0]));
                dy=abs(Jongsu.second-(Arduinos[j].second+route[r][1]));
                if(dx+dy < mindiff){
                    mindiff = dx+dy;
                    idx=r;
                }
            }
            dx = Arduinos[j].first+route[idx][0];
            dy = Arduinos[j].second+route[idx][1];
            if(map[dx][dy] == 'I'){
                //미친 아두이노가 종수 아두이노한테 감
                //게임 종료 - 종수 LOSE
                cout<< "kraj "<<X;
                return 0;
            }
            else {
                map[Arduinos[j].first][Arduinos[j].second] = '.';
                Arduinos[j].first = dx;
                Arduinos[j].second = dy;
                cnt[dx][dy]++;
                s.insert({dx,dy});
            }
        }

        //폭발한 아두이노 삭제
        for(auto chk: s){
            map[chk.first][chk.second] = 'R';
            if(cnt[chk.first][chk.second]>=2){
                //폭발
                it = find(Arduinos.begin(), Arduinos.end(), chk);
                while(it!=Arduinos.end()){
                    Arduinos.erase(it);
                    it = find(Arduinos.begin(), Arduinos.end(), chk);
                }
                map[chk.first][chk.second]='.';
            }
        }
    }

    //출력
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout<<map[i][j];
        }
        cout<<endl;
    }

    return 0;
}