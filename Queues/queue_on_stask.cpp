#include <iostream>
#include <stack>
using namespace std;

struct Queue {
    stack<int> s1, s2;
};

void enqueue(Queue *Q, int data) {
    Q->s1.push(data);
}

int dequeue(Queue *Q) {
    int top;
    if (!Q->s2.empty()) {
        top = Q->s2.top();
        Q->s2.pop();
    } else {
        while (!Q->s1.empty()) {
            Q->s2.push(Q->s1.top());
            Q->s1.pop();
        }
        top = Q->s2.top();
        Q->s2.pop();
    }
    return top;
}

int main() {
    Queue *Q = new Queue();
    cout<<"enqueue 1,2,3,4\n";
    enqueue(Q, 1);    
    enqueue(Q, 2);    
    enqueue(Q, 3);    
    enqueue(Q, 4);
    cout<<"Dequeuing front 3\n";
    int i = 0;
    while (i < 3) {
        cout<<dequeue(Q)<<" ";
        i++;
    }
    cout<<endl<<"enqueue 5,6,7,8\n";
    enqueue(Q, 5);
    enqueue(Q, 6);
    enqueue(Q, 7);
    enqueue(Q, 8);
    cout<<"Dequeuing again front 3\n";
    i = 0;
    while (i < 3) {
        cout<<dequeue(Q)<<" ";
        i++;
    }
    cout<<endl<<"enqueue 9,10\n";
    enqueue(Q, 9);
    enqueue(Q, 10);
    cout<<"Dequeuing again front 3\n";
    i = 0;
    while (i < 3) {
        cout<<dequeue(Q)<<" ";
        i++;
    }
    cout<<endl;
    delete Q;
    return 0;
}
