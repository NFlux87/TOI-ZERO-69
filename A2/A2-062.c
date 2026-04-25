#include <stdio.h>
#include <ctype.h>


void printAEIOU(int a, int e, int i, int o, int u);

#define SIZE 1001
char buff[SIZE];

int main(void)
{
    fgets(buff, sizeof(buff), stdin);
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;

    // printf("beff: %s\n", buff);
    for(int j = 0; buff[j] != '\0'; j++)
    {
        char character = tolower(buff[j]);
        if(character == 'a') {a++;}
        else if(character == 'e') { e++; }
        else if(character == 'i') { i++; }
        else if(character == 'o') { o++; }
        else if(character == 'u') { u++; }
    }


    printAEIOU(a, e, i, o, u);
    return 0;
}

void printAEIOU(int a, int e, int i, int o, int u)
{
    if(a != 0){ printf("a: %d\n", a);}
    if(e != 0){ printf("e: %d\n", e);}
    if(i != 0){ printf("i: %d\n", i);}
    if(o != 0){ printf("o: %d\n", o);}
    if(u != 0){ printf("u: %d\n", u);}


}
