//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int a,b,c;
//int dp[21][21][21];
//
//int w(int a, int b, int c){
//    if(a<=0 || b<=0 || c<=0) return 1;
//    if(a>20 || b>20 || c>20) return w(20,20,20);
//    if(dp[a][b][c]!=-1) return dp[a][b][c];
//
//    if(a<b && b<c){
//        dp[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
//        return dp[a][b][c];
//    }
//    dp[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
//
//    return dp[a][b][c];
//}
//int main(){
//    memset(dp,-1,sizeof(dp));
//    for(int i=0; i<21; i++){
//        for(int j=0; j<21; j++){
//            dp[0][i][j] = 1;
//            dp[i][0][j] = 1;
//            dp[i][j][0] = 1;
//        }
//    }
//
//    while(1){
//        cin>>a>>b>>c;
//        if(a==-1 && b==-1 && c==-1) break;
//
//        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
//    }
//
//    return 0;
//}