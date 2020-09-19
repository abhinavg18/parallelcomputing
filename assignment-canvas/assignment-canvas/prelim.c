#include <unistd.h>
#include <stdio.h>

void check(int x) {
	if (x == -1) {
		printf("ERROR, no hostname");
	}
}
int main () {

  char name[256];
  int hostname;

  hostname = gethostname(name, sizeof(name));
  check(hostname);

  printf("Hostname: %s\n", name);
	
 
  return 0;
}
