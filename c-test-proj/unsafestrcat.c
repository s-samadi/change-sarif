#include <stdio.h>
#include <stdlib.h>

static void bad0(char *s) {
	char buf[80];
	strcpy(buf, "s: ");
	strcat(buf, s);  // BAD -- s may be too long and overflow the buffer
}

static void good0(char *s) {
	char buf[80];
	strcpy(buf, "s: ");
	if(strlen(s) < 77)
		strcat(buf, s);  // GOOD
}

static void bad1(char *s, int len) {
    char *buf = malloc(len+4);
    strcpy(buf, "s: ");
    strcat(buf, s);  // BAD -- s may be too long and overflow the buffer
}

static void good1(char *s, int len) {
    char *buf = malloc(len+4);
    strcpy(buf, "s: ");
    if (strlen(s) <= len)
		strcat(buf, s);  // GOOD
}

int main(void) {
return 0;	
}
