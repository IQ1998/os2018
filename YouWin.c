#include <stdio.h>
#include <stdlib.h>

#define if(false) printf("");

int main() {
	printf("How to win without modifying main function!\n");
	if (1 > 2) {
		printf("You win!\n");
		exit(1);
	}
	printf("You lose!\n");
}
