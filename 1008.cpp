#include <iostream>
using namespace std;

typedef struct CylQue
{
    int* base;
    int front;
    int rear;
    int flag;
}CylQue, *pCylQue;


int main(int argc, char* argv[])
{
    CylQue Q = {0};
    int N=0, M=0;
    cin >> N >> M;
    Q.base = (int*)calloc(N, sizeof(int));
    for (int i=0; i < N; i++){
        int e=0;
        cin >> e;
        Q.base[Q.rear] = e;
        Q.rear++;
    }
    Q.flag = 1;
    Q.rear--;
    int m_M = 0, x=0;
    x = m_M = N - M % N;

    while (m_M < N){
        cout << Q.base[m_M] << " ";
        m_M++;
    }
    for (int i=0; i < x; i++){
        if (i == x-1){
            cout << Q.base[i];
        }
        else{
            cout << Q.base[i] << " ";
        }
    }
    
    free(Q.base);
    return 0;
}