#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

long long int totalAsciiValues(string str)
{
	vector<long long int> sumArr;
    int l = str.length();
    int sum = 0;
    long long int bigSum = 0L;
    for (int i = 0; i < l; i++) {
 
        if (str[i] == ' ') {
 
            bigSum += sum;
            sumArr.push_back(sum);
            sum = 0;
        }
        else
 
            
            sum +=  str[i];       
    }
 
    sumArr.push_back(sum);
    bigSum += sum;
    return bigSum;
}

void heapify(string arr[], int n, int i) {
    int largestIdx = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && totalAsciiValues(arr[left]) >
            totalAsciiValues(arr[largestIdx]))
        largestIdx = left;

    if (right < n && totalAsciiValues(arr[right]) >
    totalAsciiValues(arr[largestIdx]))
        largestIdx = right;

    if (largestIdx != i) {
        string temp = arr[i];
        arr[i] = arr[largestIdx];
        arr[largestIdx] = temp;
        heapify(arr, n, largestIdx);
    }
}


void heapSort(string arr[], int n) {


    for (int i = n / 2 - 1; i >= 0 ; --i) {
        heapify(arr, n, i);
    }
    
    for (int i = n - 1; i > 0; --i) {
        string temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}



int main() {
    string arr[1000];
    
    int totalWords = 0;
    
    fstream outputFileStream;

    outputFileStream.open("input.txt"); //write your txt file name
    string currentWord;

    if (outputFileStream) {
        while (!outputFileStream.eof()) {
            outputFileStream >> currentWord;
            arr[totalWords] = currentWord;
            totalWords += 1;
        }

        heapSort(arr, totalWords);

        for (int i = 0; i < totalWords; ++i) {
            cout << arr[i] << " " << totalAsciiValues(arr[i]) << endl;
        }
    } 
	
	else {
        cout << "File doesn't exist or is not accessible.\n";
    }
    
    return 0;
}










