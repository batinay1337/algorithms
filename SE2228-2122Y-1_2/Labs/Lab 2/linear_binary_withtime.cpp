#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <chrono>

using namespace std;

int linearsearch(int A[], int key, int size) {
	int result = -1;
	for (int i = 0; i<size; i++) {
		if (key == A[i])
			result = i;
	}
	return result;
}

int binarysearch(int A[], int key, int size) {
	int low, mid, high, result;
	result = -1;
	low = 0;
	high = size - 1;
	while (low <= high && result == -1) {
		mid = (high + low) / 2;
		if (A[mid] == key)
			result = mid;
		else if (key <A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return result;
}

int main() {
	int A[100000];
	cout << "The array is : ";
	for (int i = 0; i<100000; i++) {
		A[i] = i;
	}
	int size = sizeof(A) / sizeof(int);
	//clock_t start = clock();
	auto start = std::chrono::high_resolution_clock::now();
	int result = linearsearch(A, 99999, size);
	//clock_t finish = clock();
	auto finish = std::chrono::high_resolution_clock::now();
	//double elapsed_time = (double)(finish - start) / double(CLOCKS_PER_SEC) * 1000;
	cout << "Linear search took " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << endl;
	cout << "The searched key is found in the index " << result << endl;


	//start = clock();
	start = std::chrono::high_resolution_clock::now();
	result = binarysearch(A, 99999, size);
	//finish = clock();
	finish = std::chrono::high_resolution_clock::now();
	//elapsed_time = (double)(finish - start) / double(CLOCKS_PER_SEC) * 1000;
	cout << "Binary search took " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << endl;
	cout << "The searched key is found in the index " << result << endl;

	system("pause");
	return 0;

}

