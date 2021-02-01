#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>



#define SET_INDEX(type,v,n,nmax) \
if((n)+1>=(nmax)){v=(type*)realloc(v,(nmax=((n)*2+1))*sizeof(type));}
#define ARR(type,x) int x##__nmax=10; type *x=NULL; x=(type*)malloc(x##__nmax*sizeof(type));
#define SET_ARR(type,x,n) \
if((n)+1>=x##__nmax){x=(type*)realloc(x,(x##__nmax=((n)*2+1))*sizeof(type));}
struct S2
{
char x;int y;
};
struct S3
{
char x;char y;char z;
};
struct CStack_;
typedef
struct CStack_
{
int *s;
int n,nmax;
}CStack;
CStack *Create()
  {
  CStack *x; x=(CStack*)malloc(sizeof(*x));
  memset(x,0,sizeof(*x));
  return x;
  }
int Empty(CStack *s)
  {return s==NULL||s->n==0;}
  
int Push(CStack *s, int x)
{
  if(s==NULL)return -1;
  if(s->n>=s->nmax)
  s->s=(int*)realloc(s->s,(s->nmax=s->n*2+1)*sizeof(int));
  s->s[s->n++]=x;
  return 0;
}

int Get(CStack *s,int *top)
{
  if(s==NULL||s->n==0)return -1;
  *top=s->s[s->n-1];
  return 0;
}

int Pop(CStack *s)
{
  if(s==NULL||s->n==0)return -1;
  s->n--;
  return 0;
}

void Delete(CStack **s)
{
if(s!=NULL&&*s!=NULL)
{
if((*s)->s!=NULL)free((*s)->s);
free(*s);
*s=NULL;
}
}

int **Create2()
{int **s,nmax=10;
s=(int**)malloc(3*sizeof(int*)+nmax*sizeof(int));
s[0]=s[1]=(int*)(s+3);
s[2]=s[1]+nmax;
return s;
}

void Delete2(int ***s)
{
if(s==NULL||*s==NULL)return;
free(*s);
*s=NULL;
}

int Empty2(int **s)
{return s[0]==s[1];}

int Push2(int **s, int x)
{
if(s==NULL||s[1]==s[2])return -1;
*(s[1]++)=x;
return 0;
}

int Get2(int **s, int *x)
{
if(s==NULL ||Empty2(s))return -1;
*x=s[1][-1];
return 0;
}

int Pop2(int **s)
{
if(s==NULL||Empty2(s))return -1;
s[1]--;
return 0;
}

int main(void)
{
try{ 
int **s,i,x;
s=Create2();
for(i=0;i<18;i++)if(Push2(s,i))printf("Can't push %d\n",i);
for(i=0;i<18;i++)
{if(Get2(s,&x))printf("Can't get %d\n",i); else printf("top=%d\n",x); Pop2(s);}
Delete2(&s);
//getchar();
}catch(...)  {std::cout<<"error!\n";}

try{
CStack *s=NULL; int i,x;
s=Create();
for(i=0;i<10;i++)Push(s,2*i);
//while(!Empty(s)){Get(s,&x); printf("%d ",x); Pop(s);}
while(Get(s,&x)==0){printf("%d ",x);Pop(s);}
Delete(&s);
//getchar();
}catch(...)  {std::cout<<"error!\n";}

try{
struct S3 x[10];
CStack y;
memset(&(y.n),0,((char*)&y.n)-((char*)&y.s)+sizeof(y.n));
printf("%d %d %d %d\n",sizeof(CStack),sizeof(struct S2),sizeof(struct
S3),sizeof(x));
}catch(...)  {std::cout<<"error!\n";}
return 0;
}
