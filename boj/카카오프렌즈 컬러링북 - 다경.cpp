#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);
    queue<pair<int,int>> q;
    bool visited[m][n];
    int route[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int x,y,dx, dy, area_size=0;
    memset(visited, false, sizeof(visited));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!picture[i][j]) continue;
            if(visited[i][j]) continue;
            //BFS
            number_of_area++;
            q.push({i,j});
            visited[i][j]=1;
            area_size=1;
            while(!q.empty()){
                x = q.front().first, y=q.front().second;
                q.pop();

                for(int k=0; k<4; k++){
                    dx = x+route[k][0], dy = y+route[k][1];
                    if(dx>=0 && dy>=0 && dx<m && dy<n
                    && picture[dx][dy]==picture[x][y] && !visited[dx][dy]){
                        q.push({dx,dy});
                        visited[dx][dy]=1;
                        area_size++;
                    }
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, area_size);
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){

    int m=6,n=4;
    vector<vector<int>> picture;
    picture.push_back({1, 1, 1, 0});
    picture.push_back({1, 2, 2, 0});
    picture.push_back({1, 0, 0, 1});
    picture.push_back({0, 0, 0, 1});
    picture.push_back({0, 0, 0, 3});
    picture.push_back({0, 0, 0, 3});

    //몇 개의 영역, 가장 큰 영역의 넓이

    vector<int> ans = solution(m,n,picture);

    cout<< ans[0]<<' ' <<ans[1];

    return 0;
}