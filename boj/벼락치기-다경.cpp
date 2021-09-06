//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//int N,T,K,S;
//vector<pair<int,int>> classes;
//int dp[101][10001]; //dp[i][j]: j시간 동안, i번째 과목까지 공부햇을 때, 최대 점수
//int main(){
//    memset(dp, 0, sizeof(dp));
//
//    cin>>N>>T;
//    classes.push_back({0,0});
//    for(int i=0; i<N; i++){
//        cin>>K>>S; //공부시간, 배점
//        classes.push_back({K,S});
//    }
//
//    for(int i=1; i<=N; i++){
//        for(int j=0; j<=T; j++){
//            if(classes[i].first>j){
//                dp[i][j] = dp[i-1][j];
//                continue;
//            }
//            dp[i][j] = max(dp[i-1][j], dp[i-1][j-classes[i].first]+classes[i].second);
//        }
//    }
//
//    cout<<dp[N][T];
//
//    return 0;
//}