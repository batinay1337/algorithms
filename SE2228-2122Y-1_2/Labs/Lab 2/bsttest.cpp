#include<iostream>
#include "bst_.h"

using namespace std;

int main()
{
	BST st;
	int arr[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof(arr) / sizeof(arr[0]); 
	for(int i=0; i<size; i++){
		st.insert(arr[i]);
	}
	st.printInorder(st.root);
	system("PAUSE");
	return 0;
}
