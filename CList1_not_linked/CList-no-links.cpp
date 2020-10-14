#include <iostream> 
using namespace std;
/*
1.	Создать
2.	Уничтожить 
3.      Очистить
4.	Пуст ли?
5.      Получить пред. знач.
6.	Получить след. знач.
7.	Перейти на следующий
5.	Перейти на предыдущий
9.	Уничтожить следующий
10.	Уничтожить предыдущий
12.	Перейти в начало
13.	Перейти в конец
*/
template<class T> class CStack1 
{
private: T *v; int N,top; 
public: 
CStack1(int N=100){SetZero(); this->N=N; v=new T[N];}
~CStack1(){Clean();}
CStack1(const CStack1&b){CopyOnly();}
CStack1 &operator=(const CStack1&b){if(this!=&b){Clean();CopyOnly(b);} return *this;} 
void SetZero(){v=NULL;N=0;top=0;} 
void Clean(){delete[] v; SetZero();}
void CopyOnly(const CStack1&b){v=new T[N=b.N]; for(int i=0;i<N;i++)v[i]=b.v[i]; top=b.top;} int IsEmpty(){return top==0;}
int Push(const T &x){if(top>=N){T *w=new T[2*N]; for(int i=0;i<N;i++)w[i]=v[i]; delete[]v; v=w; N*=2;} v[top++]=x; return 1;} 
T Pop(){if(top<=0)throw(-1); T x=v[--top]; return x;}
T Get(){if(top<=0)throw(-2); T x=v[top-1]; return x;}
};
template<class T>class CList 
{
private: CStack1<T> b,e; 
public: 
CList(){}
void Clean(){b.Clean();e.Clean();}
int IsEmpty(){return b.IsEmpty()&&e.IsEmpty();}
int GetPrev(T &v){if(b.IsEmpty())return 0; v=b.Get(); return 1;}
int GetNext(T &v){if(e.IsEmpty())return 0; v=e.Get(); return 1;}
int GoToNext(){if(e.IsEmpty())return 0; b.Push(e.Pop()); return 1;}
int GoToPrev(){if(b.IsEmpty())return 0; e.Push(b.Pop()); return 1;}
int DelNext(){if(e.IsEmpty())return 0; e.Pop(); return 1;}
int DelPrev(){if(b.IsEmpty())return 0; b.Pop(); return 1;}
void Add(const T&x){e.Push(x);}
void GoToBegin(){while(!b.IsEmpty())e.Push(b.Pop());} void GoToEnd(){while(!e.IsEmpty())b.Push(e.Pop());}
};
int main(void)
{CList<int> l; int i; l.Add(1); l.Add(2); l.Add(3); l.Add(4);
for(l.GoToBegin();l.GoToNext();)cout<<(l.GetPrev(i),i)<<" "; cout<<endl; return 0;
}
