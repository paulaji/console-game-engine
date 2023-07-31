#include <iostream>
// Using the below line of code, we can avoid using
// 'std::' prefix with 'cout' and other standard library elements
using namespace std;

// Windows API to interact with Windows
#include <Windows.h>

// Creating a fixed window size for the engine
int nScreenWidth = 120;
int nScreenHeight = 40;

int main()
{
	// Creating a screen buffer

	// 'wchar_t' is used to store wide characters.
	// Characters are typically 1 byte in length, but in many contexts,
	// 'wchar_t' is usually 2 bytes.
	// 'new' operator requests a block of memory and returns a pointer to the first element of the allocated memory.
	// 'new wchar_t[nScreenWidth * nScreenHeight]' allocates memory to store 'wchar_t' type elements with size 'nScreenWidth * nScreenHeight'.
	// 'wchar_t*' is a pointer type variable that points to the memory location allocated using the 'new' keyword.
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];

	// 'HANDLE' is a special datatype defined when using the Windows API.
	// It represents a handle to the console screen.
	// 'CreateConsoleScreenBuffer' is a Windows API function to create a new console screen buffer.
	// The parameters 'GENERIC_READ | GENERIC_WRITE' indicate that we have read/write access to the console.
	// The second parameter '0' is reserved and must be set to 0.
	// This 0 indicates that the console window we create is for project purposes and must not be used as the primary console screen.
	// The third parameter 'NULL' indicates that we don't want to use any existing console window as our buffer but prefer to create a new one.
	// The fourth parameter 'CONSOLE_TEXTMODE_BUFFER' indicates that we are creating a text mode screen buffer because we are using characters or texts to create the whole map.
	// The last parameter as 'NULL' indicates that we are not setting any security descriptors: e.g., access rights - those who can access the application.
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// By this line, we are saying that when we run the application, we must use 'hConsole'.
	SetConsoleActiveScreenBuffer(hConsole);

	// 'DWORD' is a datatype coming with the Windows API.
	// It is 4 bytes in size, as opposed to 2 bytes of 'wchar_t'.
	// 'DWORD' is commonly used for storing sizes, counts, or other values that don't need to be negative.
	// The 'dw' in 'dwBytesWritten' is a common prefix for 'DWORD' datatype variables.
	// We initialize the variable with the value of 0.
	DWORD dwBytesWritten = 0;

	// Game Loop
	// The game loop runs indefinitely (infinite loop) to keep the game/application running and responsive.
	// It continuously updates the game state and redraws the screen to create dynamic and interactive content.
	// The loop will keep executing until explicitly stopped by an external condition or user input.
	while (1) {
		// Set the last character of the screen buffer to '\0' (null terminator).
		// This is essential when dealing with text to properly handle string termination.
		screen[nScreenWidth * nScreenHeight - 1] = '\0';

		// Write the contents of the 'screen' buffer to the console screen.
		// 'WriteConsoleOutputCharacter' is a Windows API function used to write characters to the console screen buffer.
		// The parameters are the console handle, the 'screen' buffer, the number of characters to write,
		// the position where writing starts, and the 'dwBytesWritten' variable to store the number of characters actually written.
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
	}
	
	// We are done, so we return 0 to indicate successful execution of the program.
	return 0;
}
