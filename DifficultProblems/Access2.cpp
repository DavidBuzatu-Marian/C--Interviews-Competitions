#include <iostream>
#include <fstream>
#include <queue>
int n, m;
char mat[1001][1001];
int zoneScore, score;
std::priority_queue<int> zones_q, no_P_q;
int movesI[4] ={ 0, 0, -1, 1 };
int movesJ[4] ={ 1, -1, 0, 0 };
bool inMatrix(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void DFS(int i, int j) {
    if (mat[i][j] == 'P') {
        ++zoneScore;
    }
    mat[i][j] = '#';
    for (int k = 0; k < 4; ++k) {
        int nextI = i + movesI[k];
        int nextJ = j + movesJ[k];
        if (inMatrix(nextI, nextJ)) {
            if (mat[nextI][nextJ] != '#') {
                DFS(nextI, nextJ);
            }
        }
    }
}


int main() {

    std::ifstream input_f("acces2.in");
    std::ofstream output_g("acces2.out");
    input_f >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            input_f >> mat[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] != '#') {
                zoneScore = 0;
                DFS(i, j);
                if (zoneScore == 0) {
                    no_P_q.push(zoneScore);
                }
                else {
                    zones_q.push(zoneScore);
                }
            }
        }
    }
    while (!no_P_q.empty()) {

        no_P_q.pop();
        if (!zones_q.empty() && zones_q.top() > 1) {
            int P_zone = zones_q.top();
            --P_zone;
            score++;
            zones_q.pop();
            zones_q.push(P_zone);
        }
        else {
            score += 2;
        }
    }

    output_g << score;
    input_f.close();
    output_g.close();
    return 0;
}
