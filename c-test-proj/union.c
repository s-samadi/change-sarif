#include <stdio.h>
#include <stdlib.h>

//// Test code /////

typedef union {
	char *ptr;
	char buffer[15];
} MyUnion;

void unions_test(MyUnion *mu)
{
	char buffer[25];

	strcpy(mu, "1234567890"); // GOOD
	strcpy(&(mu->ptr), "1234567890"); // GOOD (dubious)
	strcpy(&(mu->buffer), "1234567890"); // GOOD
	strcpy(mu, "12345678901234567890"); // BAD [NOT DETECTED]
	strcpy(&(mu->ptr), "12345678901234567890"); // BAD
	strcpy(&(mu->buffer), "12345678901234567890"); // BAD
	
	mu->ptr = buffer;
	strcpy(mu->ptr, "1234567890"); // GOOD
	strcpy(mu->ptr, "12345678901234567890"); // GOOD
	strcpy(mu->ptr, "123456789012345678901234567890"); // BAD
}

int main(void) {
return 0;	
}
