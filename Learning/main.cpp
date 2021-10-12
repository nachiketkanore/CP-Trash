/*
Author: Nachiket Kanore
Created: Thursday 22 July 2021 11:29:16 PM IST
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

template <typename T> void println(T x) { cout << x << '\n'; }

void hello_main() {
	int x; cin >> x;
	println(x);
}

struct hello {
	struct world {
		struct HELLO {
			int secret;
			HELLO() {
				secret = 21;
			}
		};
		map<HELLO, int> f;
	} here;
	int x, y, z;
	hello(int x, int y, int z): x(x), y(y), z(z) {}
} A(1, 1, 1);

void test(int a, int b, int c, int d) {
	for (int i = 0; i < 10; i++) {
		cout << a * b + c * d << endl;
	}
	A.here.f.clear();
}

int teej(int x, int y, int z) {
	return x + y + z;
}

pair<string,string> get_name(const string& S) {
	{
		A.here.f.clear();
		A.here.f.clear();
		int SZ = A.here.f.size();
	}
	pair<int,int> it = make_pair(21, 22);
	const int one = it.first;
	const int two = it.second;
	string curr;
	string name, surname;
	for (char ch : S) {
		if (ch == ' ') {
			name = curr;
			curr.clear();
		} else {
			curr += ch;
		}
	}
	surname = curr;
	return make_pair(name, surname);
}

void test() {
	struct my_struct {
		int x, y, z;
		my_struct(int a, int b, int c) {
			x = a;
			y = b;
			z = c;
		}
		my_struct() {
			x = y = z = -1;
		}
	} my_obj;
	my_obj.z = 21;
}

void hello_world() {
	cout << "HELLO WORLD\n";
	pair<string,string> full_name = get_name("nachiket kanore");
	const string name = full_name.first;
	const string surname = full_name.second;

	cout << name << ' ' << surname << endl;
	return;

	int n = 21;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				cout << "HELLO WORLD\n";
				break;
			}
		}
	}
	cout << endl << flush;
}

struct Map {
	int x, y;
	struct new_map {
		vector<set<int>> f;
	};
	new_map my_map;
};

void print(const set<pair<int,int>>& A) {
	for (const pair<int,int> a: A) {
		cout << a.first << ' ' << a.second;
		Map map;
		map.my_map.f.push_back({1, 2, 3});
	}
	Map nachiket;
	set<int> val = nachiket.my_map.f.back();
	cout << *val.begin() << '\n';
}

void map_stuff() {
	set<pair<int,int>> f;
	f.clear();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		f.insert(make_pair(u, i));
	}
	print(f);
}

int Main() {
	int _; cin >> _;
	return 0;
}

void hell0_main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int X, Y;
		cin >> X >> Y;
		printf("%d", abs(X) + abs(Y));
	}
}

void test3() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
	}
}

void Rest() {
	int N; cin >> N; int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	for (int i = 1; i < N; i++) {
		A[i] += A[i-1];
	}
	cout << A[N-1] - A[0] << endl;
}

void Test() {
	vector<int> A;
	pair<int,int> old = {0, 0};
	for (int i = 0; i < 100000; i++) {
		A.push_back(i);
		pair<int,int> neww = make_pair(A.size(), A.capacity());
		if (old.second != neww.second) {
			cout << neww.first << ' ' << neww.second << '\n';
		}
		old = neww;
	}

	int chk = 0;
	for (int i = 0; i < 100000; i++) {
		A.pop_back();
		if (chk != A.capacity()) {
			cout << chk << '\n';
		}

		chk = (int)A.capacity();
	}
}

void teest() {
	int N;
	cin >> N;
	int mat[N][N];
	int positive_sum(0), negative_sum(0);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			cin >> mat[i][j];
			if (mat[i][j] >= 0) { positive_sum += mat[i][j]; }
			else { negative_sum += mat[i][j]; }
		}
	}
}

void read(int &x, int &y) { cin >> x >> y; }
void read(int &x) { cin >> x; }

struct state {
	int A, B, C;
	static const int default_value = -1;
	state(int A, int B, int C): A(A), B(B), C(C) {}
	state() { A = B = C = default_value; }
	state(int x) { A = B = C = x; }
};

state solve(int x, int y, int z) {
	return {x, y, z};
}

int solve() {
	int N, ans = 0;
	cin >> N;
	vector<int> A(N);
	for (int &x: A) {
		cin >> x;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i] == A[j]) {
				++ans;
			}
		}
	}
	return ans;
}

void hello() {
	int main;
	read(main);
	int32_t x, y;
	read(x, y);
}

void* return_ptr(int x) {
	map<int, vector<int>>* ret = new map<int, vector<int>>();
	return ret;
}

void one_two() {
	string name;
	cin >> name;
	cout << "HELLO " << name << endl;
}

bool stress_test(int N) {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int u;
		cin >> u;
		ans += u % 2 == 0 ? 1 : 0;
		if (ans == N) {
			cout << "-1\n";
			return false;
		}
	}
	cout << ans << '\n';
	return true;
}

bool Hello() {
	int N;
	cin >> N;
	vector<int_fast64_t> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < 0) {
			return false;
		}
	}
	return true;
}

void testing_main() {
	{
		int64_t x;
		{ cin >> x; }
	}
	char ch = getchar();
	auto test = [&](int x) {
		if (x == 1) return 0;
		if (x == 2) return 1;
		if (x == 3) return 2;
		return x + 1;
	};
}
int f(int n) {
	if (n % 2 == 0) return f(n - 1);
	return 1;
}
int main() {
	array<int,3> x = {1, 2, 3};
	auto [a, b, c] = x;
	cout << f(5) << '\n';
	return 0;
	hello_world();
	return 0;
	Test();
	return 0;
	vector<int> chk = {2, 3, 3, 3, 1};
	reverse(chk.begin() + 3, chk.end());
	for (int x: chk) cout << x << ' '; cout << endl;
	return 0;
	int n;
	cin >> n;
	vector<int> cnt(32);
	int ans = 0;
	for (int i = 0; i < n; i++){ 
		int u;
		cin >> u;
		for (int j = 0; j < 32; j++) {
			if (u >> j & 1)
				cnt[j]++;
			ans = max(ans, cnt[j]);
		}
	}
	cout << ans << '\n';
}
