#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

int fib_iter(int num) {
	int x = 0, y = 1, z = 0;
	for (int i = 0; i < num; i++) {
		z = x + y;
		x = y;
		y = z;
	}
	return x;
}

int fib_rec(int num) {
	if ((num == 1) || (num == 0)) {
		return(num);
	}
	else {
		return(fib_rec(num - 1) + fib_rec(num - 2));
	}
}

int main() {
	auto start = std::chrono::high_resolution_clock::now();
	int result = fib_iter(7);
	auto finish = std::chrono::high_resolution_clock::now();
	cout << "The result of iterative function is : " << result << endl;
	cout << "The function took " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << endl;

	start = std::chrono::high_resolution_clock::now();
	result = fib_rec(7);
	finish = std::chrono::high_resolution_clock::now();
	cout << "The result of recursive function is : " << result << endl;
	cout << "The function took " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << endl;

	system("pause");
	return 0;
}