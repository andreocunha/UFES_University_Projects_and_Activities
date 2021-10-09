#include <stdio.h>
#include <stack>

using namespace std;
stack<char> pilha;

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        scanf("%*c");
        int count = 0;

        for(int j = 0; j < n; j++) {
            char c;
            scanf("%c", &c);
            if(c == '(') pilha.push(c);
            else {
                if(pilha.empty()) {
                    count++;
                } else {
                    pilha.pop();
                }
            }
        }
        printf("%d\n", count);
        while(!pilha.empty()) {
            pilha.pop();
        }
    }
    return 0;
}
