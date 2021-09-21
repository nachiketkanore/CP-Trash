#include <iostream>
#include <cassert>

// currently only taking 'int',
// later change to 'T' type

class vector {
	private:
		int N = 0;
		int* A = nullptr;
	public:
		vector(int _N, int default_value = 0) {
			assert(_N >= 0);
			N = _N;
			A = new int[N];
			for (int i = 0; i < N; i++) {
				A[i] = default_value;
			}
		}

		int size() {
			return N;
		}

		int operator [](int id) {
			assert(id >= 0 && id < N);
			return A[id];
		}

		void sort(bool ascending = true) {
			for (int i = 0; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					if (A[i] > A[j]) {
						std::swap(A[i], A[j]);
					}
				}
			}
			if (!ascending) {
				for (int i = 0, j = N - 1; i < j; i++, j--)
					std::swap(A[i], A[j]);
			}
		}

		bool is_sorted(bool ascending = true) {
			bool yes = true;
			if (ascending) {
				for (int i = 1; i < N; i++)
					yes &= A[i - 1] <= A[i];
			} else {
				for (int i = 1; i < N; i++)
					yes &= A[i - 1] >= A[i];
			}
			return yes;
		}
};

int main() {
	std::cout << "OK COMPILATION\n";
	return 0;
}
