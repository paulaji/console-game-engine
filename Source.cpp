#include <iostream>
// using the below line of code, we can always avoid using
// cout instead of std::cout etc., avoiding the std:: always
using namespace std;

int main()
{
	for (int i = 0; i < 100; i++) {
		// endl which stands for endline means for next iteration,
		// it will start a new line
		cout << "Namaskaaram " << i << endl;
	}
	// return 0 is typed so that we can indicate the successful completion of a block of code
	// if we don't type it explicitly, it will be included anyways
	return 0;
}