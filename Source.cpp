#include <iostream>
// Using the below line of code, we can avoid using
// 'std::' prefix with 'cout' and other standard library elements
using namespace std;

// Windows API to interact with Windows
#include <Windows.h>

// Creating a fixed window size for the engine
int nScreenWidth = 120;
int nScreenHeight = 40;

// Creating player position(X, Y) and angle(A) at which player is looking at
// Adding f at the end of floating point numbers makes it 0 single-precision floating point numbers
float fPlayerX = 0.0f;
float fPlayerY = 0.0f;
float fPlayerA = 0.0f;

// Creating the map variables
int nMapHeight = 16;
int nMapWidth = 16;

// setting FOV (field of view)
float fFov = 3.14159 / 4.0;

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

	// Map
	// storing the map as wstring
	wstring map;

	// drawing the map
	// since we declared 16 units as height and width of the map, we use 16x16 # symbols to create the map
	// we cleared many of the # symbols to make the map look like it has a boundary and filling it with . means we can properly show the player position
	map += L'################'; // using the +=, we are appending the string to the map variable
	map += L'#..............#'; // using L before the string tells the program that we are using wide characters
	map += L'#..............#';	// wide characters are used to store unicodes, symbols etc. eg: hindi letters, chinese etc
	map += L'#..............#';
	map += L'#..............#';
	map += L'#..............#';
	map += L'#..............#';
	map += L'#..............#';
	map += L'#..............#';
	map += L'#..............#';
	map += L'#..............#';
	map += L'#..............#';
	map += L'#..............#';
	map += L'#..............#';
	map += L'#..............#';
	map += L'################';




	// Game Loop
	// The game loop runs indefinitely (infinite loop) to keep the game/application running and responsive.
	// It continuously updates the game state and redraws the screen to create dynamic and interactive content.
	// The loop will keep executing until explicitly stopped by an external condition or user input.
	while (1) {

		// Ray-Casting formula
		// looping through each column or the screenwidth so as to calculate the ray angle to each column
		for (int x = 0; x < nScreenWidth; x++) {

			// for each column, calculate the projected ray angle into the world space
			float fRayAngle = (fPlayerA - fFov / 2.0f) + ((float)x / (float)nScreenWidth) * fFov;
		
		}


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
