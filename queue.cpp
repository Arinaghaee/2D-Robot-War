// CPP code to illustrate Queue in 
// Standard Template Library (STL)
#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void showq(queue<int> g)
{
	while (!g.empty()) {
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';
}

// Driver Code
int main()
{
	queue<int> gquiz;
	gquiz.push(10);
	gquiz.push(20);
	gquiz.push(30);

	cout << "The queue gquiz is : ";
    cout << "\t " << gquiz.back();
    gquiz.pop();

    cout << "\t " << gquiz.back();
    gquiz.pop();

    cout << "\t " << gquiz.back();
    gquiz.pop();


	cout << '\n';
	// showq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
    
	cout << "\ngquiz.front() : " << gquiz.front();
	cout << "\ngquiz.back() : " << gquiz.back();

	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showq(gquiz);

	return 0;
}
