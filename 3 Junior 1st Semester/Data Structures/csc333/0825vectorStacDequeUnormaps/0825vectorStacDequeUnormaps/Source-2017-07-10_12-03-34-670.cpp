#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<deque>
#include<unordered_map>
using namespace std;
void main(){
	vector<int> A(100);
	vector<string> B;
	vector<vector<int>> C2;
	A[0] = 1;
	A[99] = 99;

	B.push_back("My string");

	int size_of_A = A.size();
	// Method 1
	for (int i = 0; i < A.size(); i++){
		// A[i]  processing each element
	}
	// Method 2
	for (vector<int>::iterator i = A.begin(); i != A.end(); i++){
		// *i processing each element
	}
	// Method 3 C++ 11
	for (auto i : A){
	}

	stack<int> C;
	C.push(1); // Add to the stack
	int D = C.top(); // Read the number at the top of the stack
	C.pop(); // pop the element from the stack
	
	deque<string> E;
	E.push_back("MyString1");
	string S = E.front();
	E.pop_front();
	
	unordered_map<int, string> F;
	F.insert(make_pair(1, "MyString1"));
	
	pair<int, string> MyData;
	string S2 = F[1];
	cout << S2;
	cout <<endl<< A[0] << "  " << A[1] << "  "<<A[99];
}
