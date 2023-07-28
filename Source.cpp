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
	wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
	// HANDLE is a special datatype which is defined when we use the windows API
	// it represents a handle to the console screen
	// CreateConsoleScreenBuffer is a windows API function to create a new console screen
	// generic read/write, we are accessing rights to do these to the console
	// 0 parameter is reserved and must be 0
	// this 0 indicates that the console window we create is for project purpose and must not be used as the primary console screen
	// third parameter NULL indicates that we dont want to use any existing console window as our buffer but prefer to create a new one
	// 4th parameter indicates we are making a text mode screen buffer because we are using characters or texts to create the whole map
	// last parameter as NULL says that we are not setting any security descriptors: eg: access rights - those who can access the application
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
}