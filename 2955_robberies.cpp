#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define MAX_N 101
#define MAX_M 101*101
double dp[MAX_M];
int money[MAX_N];
double prob[MAX_N];
int casetotal = 0;
using namespace std;
int main(){
	cin >> casetotal;
	while (casetotal-- > 0){
		//memset(dp, 0, sizeof(dp));
		memset(prob, 0, sizeof(prob));
		memset(money, 0, sizeof(money));
		int N;
		double thres;
		cin >> thres>>N;
		int M=0;
		for (int i = 1; i <= N; i++){
			cin >> money[i] >> prob[i];
			M += money[i];
		}
		//dp
		for (int i = 0; i <= M; i++){
			dp[i] = 100;
		}
		dp[0] = 0;
		for (int i = 0; i <= M; i++){
			dp[i] = 0;
		}
		dp[0] = 1;
		for (int i = 1; i <= N; i++){
			for (int j = M; j >= money[i]; j--){
				dp[j] = max(dp[j], dp[j - money[i]] * (1-prob[i]));
			}
		}
		for (int i = M; i >= 0; i--){
			if (1-dp[i] - thres < 0.000000001){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
