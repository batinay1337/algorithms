#include <iostream>
#include <cstdlib>

#define N 8

using namespace std;

void printBoard(int board[N][N]) {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

bool isValid(int board[N][N], int row, int col) {
	for (int i = 0; i < col; i++)
		if (board[row][i])
			return false;

	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;
	for (int i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;
}

bool solveQueen(int board[N][N], int col) {
	if (col >= N)
		return true;
	for (int i = 0; i < N; i++) {
		if (isValid(board, i, col)) {
			board[i][col] = 1;
			if (solveQueen(board, col + 1))
				return true;
		}
		board[i][col] = 0;
	}
	return false;
}

bool checkSolution() {
	int board[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = 0;
	if (solveQueen(board, 0) == false) {
		cout << "Solution does not exist" << endl;
		return false;
	}
	printBoard(board);
	return true;
}

/*
int main() {
	checkSolution();
	return 0;
}
*/