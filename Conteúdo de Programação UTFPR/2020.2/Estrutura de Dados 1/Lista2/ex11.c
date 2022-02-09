int main()
{
char vetor[3] = {'A','B','C'};
char *j = &vetor[0]; // *j = &4092;
char aux;
aux = vetor[0]; // aux = 'A';
aux = *(vetor + 2); // aux = 'C';
aux = *(j + 1); // aux = 'B';
aux = *j; // aux = 'A';
j = vetor + 1; // j = 4093
aux = *j; // aux = 'B';
aux = *(j + 1); // aux = 'C';
j = vetor; // j = 4092;
aux = *++j; // aux = *(&4093) = 'B';
aux = ++*j; // aux = ++*(j) = 'B';
aux = *j++; // aux = *(j)++ = 'A';
aux = *j; // aux = 'A';
return 0;
} 