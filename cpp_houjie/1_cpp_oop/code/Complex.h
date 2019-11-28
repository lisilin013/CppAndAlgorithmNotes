#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

#include <iostream>

class Complex;

Complex &
__doapl(Complex *ths, const Complex &r);

Complex &
__doami(Complex *ths, const Complex &r);

Complex &
__doaml(Complex *ths, const Complex &r);


class Complex {
public:
    // 默认参数
    // 列表初始化，相比body内赋值少了一层运算
    Complex(double r = 0, double i = 0) : re(r), im(i) {}

    //--------------------------------------------------------
    // 【总结】运算符重载写在类内还是类外
    // 0. 想要链式操作，那么就return by reference。此外，有的只能
    //    return by value，有的只能return by reference
    // 1. 流操作符必须写在类外
    // 2. 对于一元运算符，一般都是写在类外
    // 3. 对于二元运算符，如果第一个参数（左边的那个）是class类型的object
    //    那么可以写在类内，也可以写在类外，如果有类内类外两种，会优先调用
    //    类内成员函数
    // 4. 对于二元运算符，如果第一个参数（左边的那个）不是class类型的object
    //    必须写成类外函数
    //--------------------------------------------------------

    // 类内操作符重载，表面看传入一个参数，事实上是(this, const Complex&)两个参数
    // return Reference是为了考虑用户的链式操作，此时一定是类内成员函数
    Complex &operator+=(const Complex &);
    Complex &operator-=(const Complex &);
    Complex &operator*=(const Complex &);
    Complex &operator/=(const Complex &);//未实现

    // 必须return value
    // 有类内和类外两种函数写法，如果两种都有，优先调用类内成员函数写法
    // 表面看传入一个参数，事实上是(this, const Complex&)两个参数
    Complex operator+(const Complex &complex) {
        std::cout << "I am a class member function!\n";
        return {re + complex.getReal(), im + complex.getImage()};
    }

    // const成员函数的使用，是为了考虑用户将class实例化const对象的时候
    // 如果调用该函数，则会编译报错，显示非const成员函数
    // 所以如果是不改变变量值的函数，直接写成const形式
    // 显得大气
    // get
    double getReal() const { return re; }
    double getImage() const { return im; }

    // set
    void setReal(const double &r) { re = r; }
    void setImage(const double &i) { im = i; }

private:
    double re, im;

    // friend函数可以通过实例化的object直接访问私有变量，
    // 好处是不需要通过接口函数，少了一层开销
    friend Complex &__doapl(Complex *, const Complex &);
    friend Complex &__doami(Complex *, const Complex &);
    friend Complex &__doaml(Complex *, const Complex &);
};


//--------------------------------------------------------
// friend member function
//--------------------------------------------------------
// class body内自动inline，类外需要手动inline
inline Complex &
__doapl(Complex *ths, const Complex &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline Complex &
Complex::operator+=(const Complex &r) {
    return __doapl(this, r);
}

inline Complex &
__doami(Complex *ths, const Complex &r) {
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}

inline Complex &
Complex::operator-=(const Complex &r) {
    return __doami(this, r);
}

inline Complex &
__doaml(Complex *ths, const Complex &r) {
    double f = ths->re*r.re - ths->im*r.im;
    ths->im = ths->re*r.im + ths->im*r.re;
    ths->re = f;
    return *ths;
}

inline Complex &
Complex::operator*=(const Complex &r) {
    return __doaml(this, r);
}


//--------------------------------------------------------
// 类外全局函数
//--------------------------------------------------------
inline double
imag(const Complex &x) {
    return x.getImage();
}

inline double
real(const Complex &x) {
    return x.getReal();
}

//--------------------------------------------------------
// 类外操作符重载
//--------------------------------------------------------

// 输入输出流操作符只能在类外重载
// 返回引用是为了链式操作
std::ostream &operator<<(std::ostream &os, const Complex &x) {
    return os << '(' << real(x) << ',' << imag(x) << ')';
}


inline Complex
operator+(const Complex &x, const Complex &y) {
    return Complex(real(x) + real(y), imag(x) + imag(y));
}

// ！！ 这个写法其实也可以写在类内
inline Complex
operator+(const Complex &x, double y) {
    return Complex(real(x) + y, imag(x));
}

// ！！ 这个就只能写在类外
inline Complex
operator+(double x, const Complex &y) {
    return Complex(x + real(y), imag(y));
}

inline Complex
operator-(const Complex &x, const Complex &y) {
    return Complex(real(x) - real(y), imag(x) - imag(y));
}

inline Complex
operator-(const Complex &x, double y) {
    return Complex(real(x) - y, imag(x));
}

inline Complex
operator-(double x, const Complex &y) {
    return Complex(x - real(y), -imag(y));
}

inline Complex
operator*(const Complex &x, const Complex &y) {
    return Complex(real(x)*real(y) - imag(x)*imag(y),
            real(x)*imag(y) + imag(x)*real(y));
}

inline Complex
operator*(const Complex &x, double y) {
    return Complex(real(x)*y, imag(x)*y);
}

inline Complex
operator*(double x, const Complex &y) {
    return Complex(x*real(y), x*imag(y));
}

Complex
operator/(const Complex &x, double y) {
    return Complex(real(x)/y, imag(x)/y);
}

inline Complex
operator+(const Complex &x) {
    return x;
}

// 这个一元操作符，也是只能写在类外
inline Complex
operator-(const Complex &x) {
    return Complex(-real(x), -imag(x));
}

// 可以写在类内
inline bool
operator==(const Complex &x, const Complex &y) {
    return real(x) == real(y) && imag(x) == imag(y);
}

inline bool
operator==(const Complex &x, double y) {
    return real(x) == y && imag(x) == 0;
}

// 只能类外
inline bool
operator==(double x, const Complex &y) {
    return x == real(y) && imag(y) == 0;
}

inline bool
operator!=(const Complex &x, const Complex &y) {
    return real(x) != real(y) || imag(x) != imag(y);
}

inline bool
operator!=(const Complex &x, double y) {
    return real(x) != y || imag(x) != 0;
}

inline bool
operator!=(double x, const Complex &y) {
    return x != real(y) || imag(y) != 0;
}

#include <cmath>

inline Complex
polar(double r, double t) {
    return Complex(r*cos(t), r*sin(t));
}

inline Complex
conj(const Complex &x) {
    return Complex(real(x), -imag(x));
}

inline double
norm(const Complex &x) {
    return real(x)*real(x) + imag(x)*imag(x);
}

#endif   //__MYCOMPLEX__




