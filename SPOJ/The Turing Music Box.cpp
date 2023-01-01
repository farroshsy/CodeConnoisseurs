#include<iostream>
int main()
{
    printf("000 dada 000 dada da\n000 umda 000 dada da\n000 shsh 000 shsh da\n000 didi 001 didi di\n001 dada 002 didi di\n");

    int i;
    for(i=2;i<999;i++)
        printf("%3d dada %3d didi di\n",i,i+1);

    for(i=999;i>=1;i--)
        printf("%3d didi %3d didi di\n",i,i-1);

    return 0;
}
