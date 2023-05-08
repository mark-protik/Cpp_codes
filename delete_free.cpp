// CPP program to demonstrate the correct and incorrect
// usage of delete operator
#include <cstdlib>
#include <iostream>
using namespace std;

// Driver Code
int main()
{
	int x;
	int *ptr1 = &x;
	int *ptr2 = (int *)malloc(sizeof(int));
	int *ptr3 = new int;
	int *ptr4 = NULL;

	// delete Should NOT be used like below because x is
	// allocated on stack frame
	delete ptr1;

	// delete Should NOT be used like below because x is
	// allocated using malloc()
	delete ptr2;

	// Correct uses of delete
	delete ptr3;
	delete ptr4;

	int *ptrr;
	int y = 10;
	ptrr = &y;
	cout << ptrr << " " << *(ptrr) << " " << endl;
	ptrr = NULL;
	cout << ptrr << " " << *(ptrr) << " " << endl;

	getchar();
	return 0;
}
