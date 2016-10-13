template <class T, int n>
class Vector {
    T data[n];

public:
    int dim;

    inline Vector(int dim = n) : dim(dim) {}

    inline T &operator [](int index) {
        return data[index];
    }

    inline const T &operator [](int index) const {
        return data[index];
    }

    inline T operator *(const Vector<T, n> &other) const {
        T ans = T();
        for (int i = 0; i < dim; ++i) ans += data[i] * other[i];
        return ans;
    }

    inline T vabs2() const {
        return (*this) * (*this) / (T)dim;
    }
};

const int Rows = 2016;
const int Colors = 256;
const double eps = 1e-6;

typedef Vector<int, Rows> VecI;
typedef Vector<double, Rows> Vec;

void whiteBalance(const VecI &, Vec &);

void mul(const Vec *, const Vec &, Vec &);
double angle(const Vec &, const Vec &);
void norm(Vec &);
void feature(const Vec *, int, Vec &);
void center(Vec *, int);
