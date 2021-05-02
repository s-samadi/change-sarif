#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE (1024) 
 
// BAD: using gets 
void echo_bad() { 
    char buffer[BUFFERSIZE]; 
    gets(buffer); 
    printf("Input was: '%s'\n", buffer); 
} 
 
// GOOD: using fgets 
void echo_good() { 
    char buffer[BUFFERSIZE]; 
    fgets(buffer, BUFFERSIZE, stdin); 
    printf("Input was: '%s'\n", buffer); 
} 
 
int main(void) { 
    return 0; 
} 
