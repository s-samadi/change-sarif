#include <stdio.h>

int main(int argc, char** argv) {
  char *userName = argv[2];
  
  // BAD
  char query1[1000] = {0};
  sprintf(query1, "SELECT UID FROM USERS where name = \"%s\"", userName);
	
  return 0;
}
