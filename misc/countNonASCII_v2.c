#include <stdio.h>

//assuming all are max length (6-byte) UTF characters in a line
static const int MAX_STRING_SIZE = 1201;	

unsigned int skipBytes(const unsigned char c) {
	//count the number of most significant set bits until first unset bit
	unsigned char num = 7;
	unsigned char testBit = 1;
	unsigned int numSkip = 0;	
	while(1) {
		if( c & (testBit << num)) {
			numSkip++;
			num--;
		} 
		else {
			break;
		}
	}	

	return numSkip - 1;
}

int main() {
	char buffer[MAX_STRING_SIZE];

	unsigned int count = 0;

	//read stdin liny by line
	while(fgets(buffer, MAX_STRING_SIZE, stdin) != NULL) {
		unsigned int countNonAscii = 0;

		//to avoid printing new line at end of output file
		if(count)
			printf("\n");

		//parse the line for non-ascii chars
		int i = 0;
		for(i=0; i<MAX_STRING_SIZE; i++) {
			if(buffer[i] == '\n' || buffer[i] == '\0' || buffer[i] == EOF)
				break;

			if((unsigned char)buffer[i] <= 127) {
				continue;
			}
			else {
				countNonAscii++;
				i = i + skipBytes((unsigned char)buffer[i]);
			}
		}
		printf("%d", countNonAscii);
		count++;
	}
	return 0;
}
