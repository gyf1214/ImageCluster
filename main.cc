#include "util.hpp"
#include <cstdio>

Vec *m;
VecI *mi;
Vec eigen;
int n;
double tmp2[MaxN];

void pre(FILE *f) {
    n = input(f, mi);
    m = new Vec[n];
    eigen.dim = mi[0].dim;
    for (int i = 0; i < n; ++i) {
        m[i].dim = mi[i].dim;
        whiteBalance(mi[i], m[i]);
    }
    center(m, n);
}

void work(FILE *f) {
    feature(m, n, eigen);
    for (int i = 0; i < n; ++i) {
        tmp2[i] = m[i] * eigen;
    }
    for (int i = 0; i < n; ++i) {
        if (tmp2[i] >= .0) fprintf(f, "%d ", 1 + i);
    }
    fprintf(f, "\n");
    for (int i = 0; i < n; ++i) {
        if (tmp2[i] < .0) fprintf(f, "%d ", 1 + i);
    }
    fprintf(f, "\n");
}

int main(int argc, char **argv) {
    FILE *f, *o;
    const char *path = argc >= 2 ? argv[1] : "test.txt";
    f = fopen(path, "r");
    const char *opath = argc >= 3 ? argv[2] : "result.txt";
    o = fopen(opath, "w");

    if (!f || !o) {
        printf("error!\n");
    } else {
        pre(f);
        work(o);
    }

    delete []m;
    fclose(f);
    fclose(o);

    return 0;
}
