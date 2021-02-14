#include <stdio.h>
#include <stdlib.h>
void initial(int t[12])
{
    int i;
    for(i=0; i<12; i++)
    {
        t[i]=4;
    }

}
void plateau1(int t[12],int score1,int score2,int numcase)
{
    numcase=6+numcase;
    int jetons=t[numcase];
    int i,a;
    for(i=1; jetons>0; i++)
    {
        t[numcase]=0;
        a=numcase+i;
        do
        {
            if(a>11)
            {
                a=17-a;
            }
            if(a<0)
            {
                a=5-a;
            }
        }
        while(a<0||a>11);
        if(a==numcase)
        {
            i=i+1;
            a=a+1;
        }
        t[a]=t[a]+1;
        jetons=jetons-1;
    }
}
void plateau2(int t[12],int score1,int score2,int numcase)
{
    int jetons=t[numcase];
    int i,a;
    for(i=1; jetons>0; i++)
    {
        t[numcase]=0;
        a=numcase-i;
        do
        {
            if(a>11)
            {
                a=17-a;
            }
            if(a<0)
            {
                a=5-a;
            }
        }
        while(a<0||a>11);
        if(a==numcase)
        {
            i=i+1;
            a=a+1;
        }
        t[a]=t[a]+1;
        jetons=jetons-1;
    }
}
void victory(int sommecaset2(t),int sommecaset1(t),int score2,int score1,int t[12])
{
    if(sommecaset2(t)==0)
    {
        printf("Le joueur 1 a gagne avec %i points",score1);
    }
    if(sommecaset1(t)==0)
    {
        printf("Le joueur 2 a gagne avec %i points",score2);
    }
}
int sommecaset2(int t[12])
{
    int i,sommet2;
    sommet2=0;
    for(i=0; i<12; i++)
    {
        if(i<6)
        {
            sommet2=sommet2+t[i];
        }
    }
    return sommet2;
}
int sommecaset1(int t[12])
{
    int i,sommet1;
    sommet1=0;
    for(i=0; i<12; i++)
    {
        if(i>5)
        {
            sommet1=sommet1+t[i];
        }
    }
    return sommet1;
}
void affplat(int t[12],int score1,int score2)
{
    int i;
    for(i=0; i<12; i++)
    {
        printf("%i   ",t[i]);
        if(i==5)
        {
            printf("score :  %i\n",score1);
            printf("\n");
        }
        if(i==11)
        {
            printf("score :  %i\n",score2);
        }
    }
}

int main()
{
    int t[12],numcase;
    int score1=0;
    int score2=0;
    initial(t);
    do
    {
            affplat(t,score1,score2);
            printf("joueur 1 :\n");
            printf("Veuillez selectionner une case (les cases sont numerotees de 0 a 5 en partant de la gauche):\n");
            scanf("%i",&numcase);
            plateau1(t,score1,score2,numcase);
            affplat(t,score1,score2);
                printf("joueur 2 :\n");
                printf("Veuillez selectionner une case (les cases sont numerotees de 0 a 5 en partant de la gauche):\n");
                scanf("%i",&numcase);
                plateau2(t,score1,score2,numcase);
    }
    while(sommecaset2(t)!=0);
    return 0;
}
