#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <chrono>

using namespace std;

int fib_iterative(int num) {
	int x = 0, y = 1, z = 0;
	for (int i = 0; i < num; i++) {
		z = x + y;
		x = y;
		y = z;
	}
	return x;
}

int fib_recursive(int x) {
	if ((x == 1) || (x == 0)) {
		return(x);
	}
	else {
		return(fib_recursive(x - 1) + fib_recursive(x - 2));
	}
}

int main() {
	//clock_t start = clock();
	auto start = std::chrono::high_resolution_clock::now();
	int result = fib_iterative(40);
	//clock_t finish = clock();
	auto finish = std::chrono::high_resolution_clock::now();
	//double elapsed_time = (double)(finish - start) / double(CLOCKS_PER_SEC) * 1000000;
	cout << "Iterative fibonacci took " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " milliseconds" << endl;
	//cout << "Iteration took: " << elapsed_time << "miliseconds" << endl;
	cout << "The result of the series is: " << result << endl;


	//start = clock();
	start = std::chrono::high_resolution_clock::now();
	result = fib_recursive(40);
	//finish = clock();
	finish = std::chrono::high_resolution_clock::now();
	//elapsed_time = (double)(finish - start) / double(CLOCKS_PER_SEC) * 1000000;
	cout << "Recursive fibonacci took " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " milliseconds" << endl;
	//cout << "Recursion took: " << elapsed_time << "miliseconds" << endl;
	cout << "The result of the series is: " << result << endl;

	system("pause");
	return 0;

}
