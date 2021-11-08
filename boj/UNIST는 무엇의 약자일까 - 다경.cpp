#include <iostream>
#include <cstring>
using namespace std;
int N, ans=0;
string unist="UNIST";
int arr[100001][5][5]; //arr[k][i][j]: k번째 단어로 (UNIST 인덱스 i~j까지) 만들 수 있는 개수
int dp[100001][5]; // dp[i][j]: i번째 단어까지 사용하여 unist[j]까지 만드는 경우의 수
int main(){
    //UNIST 만들기
    string s;
    int idx=0;
    memset(arr, 0, sizeof(arr));
    memset(dp, 0, sizeof(dp));

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>s;
        for(int j=0; j<5; j++){ //UNIST
            idx=0;
            for(int k=0; k<s.size(); k++){
                if(s[k]==unist[j+idx]){
                    arr[i][j][j+idx]=1;
                    idx++;
                }
                else break;
            }
        }
    }

    //UNIST 조합 만들기
    // dp[i][j]: i번째 단어까지 사용하여 unist[j]까지 만드는 경우의 수
    // dp[0][0] = arr[0][0][0] dp[0][1] = arr[0][0][1]

    // dp[1][0] = dp[0][0]+ arr[1][0][0]
    // dp[1][1] = (dp[0][0]&&arr[1][1][1]) + arr[1][0][1]
    // dp[1][2] = (dp[0][0]&&arr[1][1][2]) + (dp[0][1]&&arr[1][2][2]) + arr[1][0][2]
    // dp[1][3] = (dp[0][0]&&arr[1][1][3]) + (dp[0][1]&&arr[1][2][3]) + (dp[0][2]&&arr[1][3][3]) + arr[1][0][3]

    // dp[2][0] = dp[1][0] + arr[2][0][0]
    // dp[2][1] = (dp[1][0]&&arr[2][1][1]) + arr[2][0][1]
    // && 아니고 *

    for(int i=0; i<N; i++) dp[0][i] = arr[0][0][i];
    for(int i=1; i<N; i++){
        dp[i][0] = dp[i-1][0];
        dp[i][0] = (dp[i][0] + arr[i][0][0])%1000000007;
        for(int j=1; j<5; j++){
            dp[i][j] = dp[i-1][j];
            dp[i][j] = (dp[i][j] + arr[i][0][j])%1000000007;
            //split
            for(int k=0; k<j; k++){
                dp[i][j] = (dp[i][j]+(dp[i-1][k]*arr[i][k+1][j]))%1000000007;
                //cout<<"dp["<<i<<"]["<<j<<"] += (dp["<<i-1<<"]["<<k<<"]*arr["<<i<<"]["<<k+1<<"]["<<j<<"]);"<<endl;
            }
        }
    }

    cout<<dp[N-1][4]%1000000007;

    return 0;
}