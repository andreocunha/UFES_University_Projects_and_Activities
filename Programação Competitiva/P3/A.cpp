#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

class QItem {
public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};


int short_func(vector<vector<char>>& graph, int root_row, int root_col, int end_row, int end_col, int R, int C) {
    queue<QItem> q;
    QItem root = QItem(root_row, root_col, 0);
    q.push(root);

    graph[root_row][root_col] = '=';
    while(!q.empty()) {
        QItem v = q.front();
        q.pop();

        if(v.row == end_row && v.col == end_col) {
            return v.dist;
        }
        printf("%d %d\n", v.row, v.col);

        //cima
        if(v.row -1 >= 0 && graph[v.row - 1][v.col] == '-') {
            q.push(QItem(v.row - 1, v.col, v.dist+1));
            graph[v.row - 1][v.col] = '=';
        }
        //baico
        if(v.row +1 < R && graph[v.row + 1][v.col] == '-') {
            q.push(QItem(v.row + 1, v.col, v.dist+1));
            graph[v.row + 1][v.col] = '=';
        }
        //esq
        if(v.col -1 >= 0 && graph[v.row][v.col-1] == '-') {
            q.push(QItem(v.row, v.col - 1, v.dist+1));
            graph[v.row][v.col - 1] = '=';
        }
        //dir
        if(v.col +1 < C && graph[v.row][v.col-1] == '-') {
            q.push(QItem(v.row, v.col + 1, v.dist+1));
            graph[v.row][v.col + 1] = '=';
        }
        
    }

    return -1;
}

int main() {
    int R, C;
    while(true) {
        scanf("%d %d", &R, &C);
        if(R == 0 && C == 0) break;

        vector<vector<char>> grid;
        for(int i = 0; i < R; i++) {
            vector<char> a;
            for(int j = 0; j < C; j++) {
                a.push_back('-');
            }
            grid.push_back(a);
        }
        
        int B;
        scanf("%d", &B);
        for(int i = 0; i < B; i++) {
            int row, num_bomb, bomb;
            scanf("%d %d", &row, &num_bomb);
            for(int j = 0; j < num_bomb; j++) {
                scanf("%d", &bomb);
                grid[row][bomb] = '!';
            }
        }
        int start_row, start_col, end_row, end_col;
        scanf("%d %d", &start_row, &start_col);
        scanf("%d %d", &end_row, &end_col);

        printf("%d\n", short_func(grid, start_row, start_col, end_row, end_col, R, C));

    }
}