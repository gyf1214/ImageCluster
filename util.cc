#include "util.hpp"

int input(FILE *f, VecI **pm) {
    *pm = NULL;
    int t = 0, r = 0, nt = 0, n;
    int tmp[BufSize];
    bool flag = false;
    for (char ch = getc(f); ch != -1; ch = getc(f)) {
        if (ch >= '0' && ch <= '9') {
            t = 10 * t + ch - '0';
            flag = true;
        } else {
            if (flag) {
                tmp[nt++] = t;
                t = 0;
                flag = false;
            }
            if (ch == '\n') {
                if (!*pm) {
                    n = nt;
                    *pm = new VecI[n];
                }
                for (int i = 0; i < nt; ++i) (*pm)[i][r] = tmp[i];
                ++r;
                nt = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        (*pm)[i].dim = r;
    }
    return n;
}
