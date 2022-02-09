#include <stdlib.h>
int main() {
int *p = (int *) malloc(2*sizeof(int));
int p2 = &p;
return 0;
}