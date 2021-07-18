//백준 8972: 미친 아두이노
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct r_info{
    int x, y;
    bool boom;
};

int dx[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int R, C, my_x, my_y;
char map[101][101];
int check_crazys[101][101];
vector<r_info> crazys;
bool finish = false;

pair<int, int> cal_distance(int x, int y){
    int dist = 987654321;
    int result_x = 0; int result_y = 0;
    for(int i=1; i<10;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= C || nx < 0 || ny >= R || ny < 0) continue;
        int temp = abs(my_x - nx) + abs(my_y - ny);
        if (temp < dist) {
            dist = temp;
            result_x = nx;
            result_y = ny;
        }
    }
    return {result_x, result_y};
}

void move_crazys(){
    memset(check_crazys, -1, sizeof(check_crazys));
    for(int i=0; i<crazys.size();i++){
        if(!crazys[i].boom){
            pair<int, int> next = cal_distance(crazys[i].x, crazys[i].y);
            map[crazys[i].y][crazys[i].x] = '.';
            if(map[next.second][next.first] == 'I'){
                finish = true;
                break;
            }
            else if(check_crazys[next.second][next.first] == -1) {
                check_crazys[next.second][next.first] = i;
            }
            else if(check_crazys[next.second][next.first] != -1) {
                crazys[i].boom = true;
                crazys[check_crazys[next.second][next.first]].boom = true;
            }

            crazys[i].x = next.first;
            crazys[i].y = next.second;
        }
    }

    //map 갱신
    for (int i=0;i<crazys.size();i++){
        if(crazys[i].boom) map[crazys[i].y][crazys[i].x] = '.';
    }
    for (int i=0;i<crazys.size();i++){
        if(!crazys[i].boom) map[crazys[i].y][crazys[i].x] = 'R';
    }
}

int main(){
    cin>>R>>C;
    for(int i=0; i<R;i++){
        for(int j=0;j<C;j++){
            cin>> map[i][j];
            if(map[i][j] == 'I'){
                my_x = j;
                my_y = i;
            }
            else if (map[i][j]=='R'){
                crazys.push_back({j, i, false});
            }
        }
    }

    string str;
    cin >> str;
    int move = 0;
    for(int i=0; i<str.size();i++){
        int dir = str[i] - '0';
        // 내 아두이노 움직이기
        map[my_y][my_x] = '.';
        my_x += dx[dir];
        my_y += dy[dir];
        move++;
        // 도착한 곳에 미친 아두이노가 있는지 확인
        if (map[my_y][my_x] == 'R'){
            finish = true;
            break;
        }
        map[my_y][my_x] = 'I';
        // 미친 아두이노 움직이기
        move_crazys();
        if (finish) break;
    }

    if (finish) cout<<"kraj "<<move;
    else{
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<map[i][j];
            }
            cout<<endl;
        }
    }
}
