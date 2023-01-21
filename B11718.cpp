#include <stdio.h>
char c;

int main(void) {
	while (scanf("%c", &c) != EOF) 
        printf("%c", c);

	return 0;
}
