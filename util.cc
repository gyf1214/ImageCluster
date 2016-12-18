#include "util.hpp"

static VecI vec[MaxN];

int input(FILE *f, VecI *&pm) {
    pm = vec;
    for (int n = 0; n < MaxN; ++n) {
        for (int i = 0; i < Rows; ++i) {
            if (fscanf(f, "%d", &vec[n][i]) <= 0) {
                return n;
            }
        }
        vec[n].dim = Rows;
    }
    return MaxN;
}
