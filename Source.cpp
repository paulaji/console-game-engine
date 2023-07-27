#include <iostream>
// using the below line of code, we can always avoid using
// cout instead of std::cout etc., avoiding the std:: always
using namespace std;

// windows API to interact with windows
#include <Windows.h>

// creating a fixed window size for the engine
int nScreenWidth = 120;
int nScreenHeight = 40;

int main()
{
	// creating screen buffer

	// wchar_t is used to store wide characters
	// characters are basically 1 byte in length
	// in many contexts, wchar_t is usually 2 bytes
	// new operator requests a block of memory and returns a pointer to the first element of the allocated memory
	// new wchar_t[nScreenWidth * nScreenHeight]; this part of the code requests from memory space to store wchar_t type elements and requests nScreenWidth * nScreenHeight size from the memory
	// wchar_t* screen this part creates a pointer type variable called screen which points to the memory location allocated using the new keyword
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
}