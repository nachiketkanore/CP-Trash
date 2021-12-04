/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 04 December 2021 11:10:03 AM IST
**/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

vector<int> order = { 31, 50, 68, 16, 25, 15, 28, 80, 41, 8, 75, 45, 96, 9, 3, 98, 83, 27, 62, 42, 59, 99, 95, 13, 55, 10, 23, 84, 18, 76, 87, 56, 88, 66, 1, 58, 92, 89, 19, 54, 85, 74, 39, 93, 77, 26, 30, 52, 69, 48, 91, 73, 72, 38, 64, 53, 32, 51, 6, 29, 17, 90, 34, 61, 70, 4, 7, 57, 44, 97, 82, 37, 43, 14, 81, 65, 11, 22, 5, 36, 71, 35, 78, 12, 0, 94, 47, 49, 33, 79, 63, 86, 40, 21, 24, 46, 20, 2, 67, 60 };

const int SIZE = 5;
struct Matrix {
	int mat[SIZE][SIZE];
	bool marked[SIZE][SIZE];
	bool won;
	Matrix()
	{
		won = false;
		F0R(i, SIZE)
		{
			F0R(j, SIZE)
			{
				cin >> mat[i][j];
				marked[i][j] = false;
			}
		}
	}
	void print()
	{
		F0R(i, SIZE)
		{
			F0R(j, SIZE)
			{
				cout << mat[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	bool check()
	{
		vector<int> row_marked(SIZE), col_marked(SIZE);
		F0R(i, SIZE)
		{
			F0R(j, SIZE)
			{
				row_marked[i] += marked[i][j] == true;
				col_marked[j] += marked[i][j] == true;
			}
		}
		F0R(i, SIZE)
		{
			if (row_marked[i] == SIZE)
				return true;
			if (col_marked[i] == SIZE)
				return true;
		}
		return false;
	}
	void mark_it(int value)
	{
		F0R(i, SIZE)
		{
			F0R(j, SIZE)
			{
				if (mat[i][j] == value) {
					marked[i][j] = true;
				}
			}
		}
	}
	int get_unmarked_sum()
	{
		int ret = 0;
		F0R(i, SIZE)
		{
			F0R(j, SIZE)
			{
				if (marked[i][j] == false) {
					ret += mat[i][j];
				}
			}
		}
		return ret;
	}
};

int32_t main()
{
	vector<Matrix> A;
	char start;
	while (cin >> start) {
		A.push_back(Matrix());
	}
	vector<int> answers;
	for (int remove : order) {
		bool done = false;
		for (Matrix& mat : A) {
			if (mat.won)
				continue;
			mat.mark_it(remove);
			if (mat.check()) {
				mat.won = true;
				int add_answer = mat.get_unmarked_sum() * remove;
				answers.push_back(add_answer);
				done = true;
			}
		}
	}
	cout << sz(A) << ' ' << sz(answers) << '\n';
	cout << answers.back() << '\n';
	// Answer = 24628
}
