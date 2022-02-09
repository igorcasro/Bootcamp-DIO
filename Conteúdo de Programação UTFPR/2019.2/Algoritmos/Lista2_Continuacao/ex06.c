#include <stdio.h>
#include <stdlib.h>
int main() {
unsigned char a[2] = {255,255};
unsigned short int *b = (unsigned short int *) a;
printf("%d\n", *b);
return 0;
}