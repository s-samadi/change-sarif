#include <stdio.h>
#include <stdlib.h>

char *copy;
char *copy2;

void copyArgv(char **argv) {
	copy = argv[1];
}

void setCopy2(char *val) {
	copy2 = val;
}

void printWrapper(char *str) {
	printf(str);
}

int main(int argc, char **argv) {
	copyArgv(argv);

	// BAD: format comes from argv through copy
	printf(copy);

	// BAD: format comes from argv through copy
	printWrapper(copy);

	// GOOD: constant format
	printf("%s", copy);

	setCopy2(copy);

	// BAD: format comes from argv through copy2 (that is set to copy that is set to argv[1])
	printf(copy2);

	// BAD: format comes from argv through copy2 (that is set to copy that is set to argv[1])
	printWrapper(copy2);

	// GOOD: constant format
	printf("%s", copy2);

	setCopy2("asdf");

	// Should be GOOD because copy2 has value "asdf"
	// But we flag this case because once a global variable gets tainted we mark all usages as tainted
	printf(copy2);
}
