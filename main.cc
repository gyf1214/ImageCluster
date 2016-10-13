#include "util.hpp"
#include <cstdio>

Vec *m;
VecI *mi;
Vec eigen;
int n;
double tmp2[BufSize];

void pre(FILE *f) {
    n = input(f, &mi);
    m = new Vec[n];
    eigen.dim = mi[0].dim;
    for (int i = 0; i < n; ++i) {
        m[i].dim = mi[i].dim;
        whiteBalance(mi[i], m[i]);
    }
    center(m, n);
}

void work() {
    feature(m, n, eigen);
    for (int i = 0; i < n; ++i) {
        tmp2[i] = m[i] * eigen;
    }
    for (int i = 0; i < n; ++i) {
        if (tmp2[i] >= .0) printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        if (tmp2[i] < .0) printf("%d ", i);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    FILE *f;
    if (argc >= 2) {
        f = fopen(argv[1], "r");
    } else {
        f = stdin;
    }

    if (!f) {
        printf("error!\n");
    } else {
        pre(f);
        work();
    }

    return 0;
}
