#include <iostream>
#include <cstring>
using namespace std;
#define NSIZE 500001
int M;// const cost 
int N;//number of post offices;
long int wcost[NSIZE];//cost of words
long int wsum[NSIZE];//sum of cost
long int queue[NSIZE];
long int dp[NSIZE];
void init(){
	for(int i = 1; i<=N; i++){
		wsum[i]=wsum[i-1]+wcost[i];
	}
}
int slope1(int i, int j){
	return (dp[j]-dp[i]+wsum[j]*wsum[j]-wsum[i]*wsum[i]);
}
int slope2(int i, int j){
	return 2*(wsum[j]-wsum[i]);
}
int main(){
	
	while(cin>>N>>M){
	memset(wcost,0,sizeof(wcost));
	memset(wsum,0,sizeof(wsum));
	memset(dp,0,sizeof(dp));
	memset(queue,0,sizeof(queue));
	int flag=1;
	for(int i = 1; i<=N; i++){
		cin>>wcost[i];
		if(wcost[i]==0) {flag=0;}
	}
	init();
	int head=0;
	int tail=0;
	for(int n=1; n<=N; n++){
		while(head<tail && slope1(queue[head],queue[head+1])<=slope2(queue[head],queue[head+1])*wsum[n]) {
			cout<<"inner slope1 "<<slope1(queue[head],queue[head+1])<<" slope2 "<<slope2(queue[head],queue[head+1])<<" sum "<<wsum[n]<<endl;
			head++;
		}
		cout<<"outter slope1 "<<slope1(queue[head],queue[head+1])<<" slope2 "<<slope2(queue[head],queue[head+1])<<" sum "<<wsum[n]<<endl;
		dp[n]=dp[queue[head]]+(wsum[n]-wsum[queue[head]])*(wsum[n]-wsum[queue[head]])+M;
		while(head<tail && slope1(queue[tail-1],queue[tail])*slope2(queue[tail],n)>=slope2(queue[tail-1],queue[tail])*slope1(queue[tail],n)) {
			cout<<"inner slope1 "<<slope1(queue[tail-1],queue[tail])<<" slope2 "<<slope2(queue[tail],n)<< " slope2 "<<slope2(queue[tail-1],queue[tail])<<" slope1 "<<slope1(queue[tail],n)<<endl;
			tail--;
		}		
		cout<<"outter slope1 "<<slope1(queue[tail-1],queue[tail])<<" slope2 "<<slope2(queue[tail],n)<< " slope2 "<<slope2(queue[tail-1],queue[tail])<<" slope1 "<<slope1(queue[tail],n)<<endl;
		//while(head<tail && slope1(queue[tail-1],queue[tail])*slope2(queue[tail],n)>slope2(queue[tail-1],queue[tail])*slope1(queue[tail],n)) tail--;
		queue[++tail]=n;
		cout<<" n "<<n <<" dp "<<dp[n]<<" head "<<head <<" tail "<<tail<<" queue head " << queue[head]<<" queue head+1 "<<queue[head+1]<<endl;
	}
	cout<<dp[N]<<endl;
	}
	return 0;
}
