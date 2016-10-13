#include "vector.hpp"
#include <cmath>

void mul(const Vec *m, const Vec &a, Vec &b) {
    int n = b.dim;
    int r = a.dim;
    bool t = m[0].dim == n;
    for (int i = 0; i < n; ++i) {
        b[i] = .0;
        for (int j = 0; j < r; ++j) {
            double x = t ? m[j][i] : m[i][j];
            b[i] += x * a[j];
        }
    }
}

double angle(const Vec &a, const Vec &b) {
    return a * b / sqrt(a.vabs2()) / sqrt(b.vabs2());
}

void norm(Vec &a) {
    double t = sqrt(a.vabs2());
    int n = a.dim;
    for (int i = 0; i < n; ++i) a[i] /= t;
}

void feature(const Vec *m, int n, Vec &a) {
    Vec b(n);
    int r = a.dim;
    for (int i = 0; i < r; ++i) a[i] = 1.0;
    for (int i = 0; i < n; ++i) b[i] = 1.0;
    Vec a0(r), b0(n);
    do {
        a0 = a, b0 = b;
        mul(m, b0, a), mul(m, a0, b);
        norm(a), norm(b);
    } while (1 - angle(a, a0) < eps && 1 - angle(b, b0) < eps);
}

void whiteBalance(const VecI &a, Vec &b) {
    double h[Colors], p[Colors];
    int n = a.dim;
    for (int i = 0; i < Colors; ++i) h[i] = .0;
    for (int i = 0; i < n; ++i) ++h[a[i]];
    for (int i = 1; i < Colors; ++i) h[i] += h[i - 1];
    for (int i = 0; i < Colors; ++i) p[i] = h[i] / h[Colors - 1];
    for (int i = 0; i < n; ++i) b[i] = p[a[i]];
}

void center(Vec *m, int n) {
    int r = m[0].dim;
    Vec center(r);
    for (int j = 0; j < r; ++j) center[j] = .0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r; ++j) {
            center[j] +=  m[i][j] / (double)n;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r; ++j) {
            m[i][j] -= center[j];
        }
    }
}
