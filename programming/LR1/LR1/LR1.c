#include <stdio.h>
#include <Windows.h>

int main() {
	HANDLE output;
	HANDLE input;

	output = GetStdHandle(STD_OUTPUT_HANDLE);
	input = GetStdHandle(STD_INPUT_HANDLE);

	printf("Input HANDLE = %d!\nOutput HANDLE = %d!", input, output);

	return 0;
}