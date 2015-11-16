/*
 pitfall:
	1. learn to use unordered_map
	2. memset can't be used to string, since string contains a pointer to an allocated space.
*/
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define MAX_N 1000
#define MAX_M X
using namespace std;
string str[MAX_N];
int main(){
	int n;
	while (cin >> n){
		if (n == 0) break;
		//memset(str, 0, sizeof(str));
		unordered_map<string, int> mp;
		for (int i = 0; i < n; i++){
			cin >> str[i];
			auto iter = mp.find(str[i]);
			if (iter == mp.end()){
				mp.insert({ str[i], 1 });
			}
			else{
				iter->second++;
			}
		}
		int cur_max = 0;
		string cur_str;
		for (auto iter = mp.begin(); iter != mp.end(); iter++){
			if (iter->second > cur_max){
				cur_str = iter->first;
				cur_max = iter->second;
			}
		}
		cout << cur_str << endl;
	}
	return 0;
}
