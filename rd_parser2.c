#include<stdio.h>
#include<string.h>


/*

    S->aABCD
    A->aA|b
    B->bB|c
    C->cC|d
    D->dD|e

*/

char input[100] = {'a','a','b','b','c','c','d','d','e'};
char prod[100][100];
int st=0;
int l;
int pos=0;

void A();
void B();
void C();
void D();


void advance()
{
    pos++;
}

void S()
{
    if(input[pos]=='a')
    {
        advance();
        strcpy(prod[st++],"S->aABCD");
        A();
        B();
        C();
        D();

    }
}

void A()
{
    if(input[pos]=='a')
    {
        advance();
        strcpy(prod[st++],"A->aA");
        A();

    }
    if(input[pos]=='b')
    {
        advance();
        strcpy(prod[st++],"A->b");
    }
}

void B()
{
    if(input[pos]=='b')
    {
        advance();
        strcpy(prod[st++],"B->bB");
        B();

    }
    if(input[pos]=='c')
    {
        advance();
        strcpy(prod[st++],"B->c");
    }
}

void C()
{
    if(input[pos]=='c')
    {
        advance();
        strcpy(prod[st++],"C->cC");
        C();

    }
    if(input[pos]=='d')
    {
        advance();
        strcpy(prod[st++],"C->d");
    }
}

void D()
{
    if(input[pos]=='d')
    {
        advance();
        strcpy(prod[st++],"D->dD");
        D();

    }
    if(input[pos]=='e')
    {
        advance();
        strcpy(prod[st++],"D->e");
    }
}



int main()
{
    
    l=strlen(input);
    int i;

    input[l]='S';
    S();

    if(pos==l)
    {
        printf("String Accepted\n");
        for(i=0;i<=st;i++)
        {
            printf("%s\n",prod[i]);
        }
    }
    else
    {
        printf("String Rejected\n");
    }
    
        return 0;
}