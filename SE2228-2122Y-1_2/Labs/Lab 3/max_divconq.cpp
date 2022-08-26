#include <iostream>
#include <cstdlib>

using namespace std;

int maxsimum(int a[], int l, int r) {
	if (l == r)
		return a[l];
	int m = (l + r) / 2;
	int u = maxsimum(a, l, m);
	int v = maxsimum(a, m+1, r);

	if (u > v)
		return u;
	else
		return v;
}

/*
int main() {
	int a[] = {34,23,45,72,30,31,57,33,65,85};
	int n = sizeof(a) / sizeof(int);
	cout << maxsimum(a, 0, n) << endl;
	system("pause");
	return 0;
}
*/