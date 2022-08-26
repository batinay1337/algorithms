#include <iostream> // standard input output stream
#include <cstdlib> // standard library to call system("pause") instruction

using namespace std;

int main() {
	int input;
	int sum = 0;
	int average = 0;
	int count = 0;
	int min;
	int max;
	/* the algorithm takes an integer input from the user and adds the value on the sum
	if the user enters 0, the algorithm terminates and calculates the average value which is given as the output */
	do{
		cout << "Please enter an integer value:" << endl;
		cin >> input;
		sum = sum + input;
		if(count == 0){
			min = input;
			max = input;
		}
		else if(input == 0)
		{
			continue;
		}
		else if(min > input){
			min = input;
		}
		else if(max < input){
			max = input;
		}
		count = count + 1;
	}
	while(input != 0);
	
	cout << "Sum is equal to = " << sum << endl;
	average = sum / (count);
	cout << "Average is equal to = " << average << endl;
	cout << "Maximum value is = " << max << endl;
	cout << "Minimum value is = " << min << endl;
	system("pause"); // a system instruction used to pause the output screen until user presses a button
	return 0;
}
