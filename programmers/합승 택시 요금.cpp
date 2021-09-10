#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 987654321;
    int dp[201][201];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = answer;
            if(i==j) dp[i][j] = 0;
        }
    }

    for(int i=0; i<fares.size(); i++){
        dp[fares[i][0]][fares[i][1]] = fares[i][2];
        dp[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dp[i][k]+dp[k][j] < dp[i][j]){
                    dp[i][j] = dp[i][k]+dp[k][j];
                }
            }
        }
    }

    // s->a, s->b
    for(int i=1; i<=n; i++){
        if(dp[s][i]==987654321 || dp[a][i]==987654321 || dp[b][i]==987654321) continue;
        answer = min(answer, dp[s][i]+dp[a][i]+dp[b][i]);
    }

    return answer;
}

int main(){

    vector<vector<int>> fares = {{4,1,10},{3,5,24},{5,6,2},
                                 {3,1,41},{5,1,24},{4,6,50},
                                 {2,4,66},{2,3,22},{1,6,25}};

    vector<vector<int>> fares2 = {{5,7,9},{4,6,4},{3,6,1},{3,2,3},{2,1,6}};

    cout<< solution(7,3,4,1,fares2)<<endl;

    return 0;
}