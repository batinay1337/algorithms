#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

struct coins {
	int price;
	int number;
};

coins coins[] = {{1,1}, {2,1}, {5,2}, {10,2}, {20,2}, {50,2}, {100,1}, {500,1}};
int deno[] = {1, 2, 5, 10, 20, 50, 100, 500};

int n2 = sizeof(coins) / sizeof(coins[0]);
int n = sizeof(deno) / sizeof(deno[0]);

void findMin(int V){
	sort(deno, deno + n);
	
	vector<int> ans;
	
	for(int i=n-1; i>=0; i--){
		while(V >= deno[i]){
			V-= deno[i];
			ans.push_back(deno[i]);
		}
	}
	
	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	cout << endl;
}

void findMin2(int V){
	
	vector<int> ans;
	
	for(int i=n-1; i>=0; i--){
		while(V >= coins[i].price && coins[i].number>0){
			V-= coins[i].price;
			ans.push_back(coins[i].price);
			coins[i].number--;
		}
	}
	
	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	cout << endl;
}

int main() {
	int n= 200;
	cout <<"Following is minimal: " << endl;
	findMin(n);
	cout <<"Following is minimal: " << endl;
	findMin2(n);
	system("pause");
	return 0;
}
