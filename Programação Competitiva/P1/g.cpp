#include <iostream>
#include <string>

using namespace std;

void buildRec(int* T, int* A, int node, int start, int end) {
    if(start == end) {
        //# Folha representa um elemento único 
        T[node] = (A[start] < 0 ? -1 : (A[start] > 0 ? 1 : 0) );
    } else {
        int mid = (start + end) / 2;
        //# Chamada recursiva para filho à esquerda 
        buildRec(T, A, 2 * node, start, mid);
        //# Chamada recursiva para filho à direita
        buildRec(T, A, 2 * node + 1, mid+1, end);
        //# Nó interno tem o produto dos dois filhos 
        T[node] = T[2 * node] * T[2 * node + 1];        //# <======= IMPORTANTE
    }
}

void build(int *T, int *A, int n) {
    buildRec(T, A, 1, 0, n-1); //# A raíz tem nó 1 e representa o segmento A[0, ..., n-1]
}


int queryRec(int *T, int node, int start, int end, int l, int r) {
    if(r < start or end < l) {
        //# [start, end] está fora de [l, r] -- não há interseção
        return 1; //retornando zero ele vai zera o no   <======= IMPORTANTE
    }
    if(l <= start and end <= r){
        //# [start, end] está contido em [l, r] 
        return T[node];
    }
    //# [start, end] e [l, r] têm interseção 
    int mid = (start + end) / 2;
    int p1 = queryRec(T, 2 * node, start, mid, l, r);
    int p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
    return p1 * p2;                                   //# <======= IMPORTANTE
}


int query(int* T, int n, int l, int r) { //#Soma(A[l, ..., r])
    return queryRec(T, 1, 0, n-1, l, r);
}


void updateRec(int* T, int* A, int node, int start, int end, int idx, int val) {
    if(start == end) {
        //# Nó folha, atualiza A e T
        A[idx] = val;
        T[node] = (A[start] < 0 ? -1 : (A[start] > 0 ? 1 : 0) );
    } else {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid) {
            //# idx está no filho à esquerda 
            updateRec(T, A, 2 * node, start, mid, idx, val);
        } else {
            //# idx está no filho à direita 
            updateRec(T, A, 2 * node + 1, mid + 1, end, idx, val);
        }
        //# Faz atualização do nó pai 
        T[node] = T[2 * node] * T[2 * node + 1];        //# <======= IMPORTANTE
    }
}


void update(int *T, int *A, int n, int idx, int val) { 
    updateRec(T, A, 1, 0, n - 1, idx, val);
}

//# Exemplo
int main() {
  int n = 0;
  int k = 0;

  while(cin >> n >> k){ 
    int a[n] = {0};
    for(int i=0;i < n; i++){
        cin >> a[i];
    }

    int T[4*n] = {0};  
    build(T, a, n);                //# Constrói a SegTree
    int x =0 ,y = 0;
    string linha;
    
        for(int j =0; j< k; j++){
            cin >> linha;
            if(linha == "C"){
                cin >> x >> y;
                update(T, a, n, x-1, y);
            }

            if(linha == "P"){
                cin >> x >> y;
                int result = query(T, n, x-1, y-1); 
                if(result > 0){
                    cout << "+";
                }
                else if(result < 0){
                    cout << "-";
                }
                else{
                    cout << "0";
                }
            }
        }
    cout<< endl;
  }
  return 0;
}