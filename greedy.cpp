#include <iostream>
#include <vector>
using namespace std;

struct coins{
	int coin;
	int number;
};
int notes[] = { 1, 2, 5, 10, 20, 50, 100,  200, 2000 };
coins coins[] = {(1,2), (2,1),(3,1),(4,2),(5,2),(6,1),(7,1),(8,1),(9,1)};
int n = sizeof(notes) / sizeof(notes[0]);



void minchange(int sum){
   vector<int> coins;
   int limit7 = 2;
   for (int i = n - 1; i >= 0; i--) {
      while (sum >= notes[i]) {
      	
      	
      	limit7--;
      	sum -= notes[i];
        coins.push_back(notes[i]);
		
		  
	
		sum -= notes[i];
        coins.push_back(notes[i]);
		
         
      }
   }
   for (int i = 0; i < coins.size(); i++)
      cout << coins[i] << "\t";
}
int main(){
   int n = 1100;
   cout << "The minimum number of coin that sum up " << n << " is \t ";
   minchange(n);
   return 0;
}
