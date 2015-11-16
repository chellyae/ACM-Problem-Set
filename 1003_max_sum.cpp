#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#define MAX_N 100000
#define MAX_M X
using namespace std;
int casetotal, casenum;
int arr[MAX_N];
int main(){
	cin >> casetotal;
	casenum = 0;
	
	while (casenum++ < casetotal){
		memset(arr, 0, sizeof(arr));
		if (casenum != 1) cout << endl;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}
		int cur_head = 0;
		int best_head = 0;
		int best_tail = 0;
		int cur_sum = 0;
		int best_sum = arr[0];
		for (int i = 0; i < n; i++){
			cur_sum += arr[i];
			if (cur_sum > best_sum){
				best_sum = cur_sum;
				best_head = cur_head;
				best_tail = i;
			}
			if (cur_sum < 0){
				cur_sum = 0;
				cur_head = i + 1;
			}
		}
		cout << "Case " << casenum << ":" << endl;
		cout << best_sum << " " << best_head+1 << " " << best_tail+1 << endl;
	}
	return 0;
}
