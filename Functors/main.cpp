#include <iostream>
#include <cmath>

using namespace std;

class psc_f {
public:
    psc_f(double alfa) {
        _alfa = alfa;
    }

    double operator()(double x) const {
        return sin(_alfa * x) + cos(x);
    }
private:
    double _alfa;
};

template <typename F, typename T>
class derivative {
public:
    derivative(const F& f, const T& h) : _f(f), _h(h) {}
    T operator()(const T& x) const {
        return (_f(x+_h) - _f(x))/_h;
    }
private:
    const F& _f;
    T _h;
};

int main() {
    psc_f psc_o(1.0);
    derivative<psc_f, double> d_psc_o(psc_o, 0.001);

    cout << d_psc_o(0.0) << endl;
    return 0;
}
