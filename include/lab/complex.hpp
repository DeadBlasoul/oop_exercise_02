#pragma once

#include <cmath>
#include <cassert>
#include <string>
#include <sstream>
#include <ostream>

class Complex;

class Complex {
public:
    Complex() = default;

    explicit Complex(double real, double imaginary) noexcept
        : re{ real }
        , im{ imaginary }
    {}

    Complex(const Complex& other) noexcept
        : re(other.re)
        , im(other.im)
    {}


    double& Real() noexcept { return re; }
    const double& Real() const noexcept { return re; }

    double& Imag() noexcept { return im; }
    const double& Imag() const noexcept { return im; }

    Complex operator+(const Complex& other) const noexcept {
        Complex tmp = *this;
        tmp.Add(other);
        return tmp;
    }

    Complex operator-(const Complex& other) const noexcept {
        Complex tmp = *this;
        tmp.Sub(other);
        return tmp;
    }

    Complex operator*(const Complex& other) const noexcept {
        Complex tmp = *this;
        tmp.Mul(other);
        return tmp;
    }

    Complex operator/(const Complex& other) const noexcept {
        Complex tmp = *this;
        tmp.Div(other);
        return tmp;
    }

    Complex& operator+=(const Complex& other) noexcept {
        Add(other);
        return *this;
    }

    Complex& operator-=(const Complex& other) noexcept {
        Sub(other);
        return *this;
    }

    Complex& operator*=(const Complex& other) noexcept {
        Mul(other);
        return *this;
    }

    Complex& operator/=(const Complex& other) noexcept {
        Div(other);
        return *this;
    }

    bool operator==(const Complex& other) noexcept {
        double thisMod = this->Mod();
        double otherMod = other.Mod();

        return (thisMod < otherMod)
            ? -1
            : (thisMod == otherMod
                ? 0
                : 1);
    }

    double& operator[](size_t ix) {
        assert(ix < (sizeof(values) / sizeof(*values)));
        return values[ix];
    }

    const double& operator[](size_t ix) const {
        assert(ix < (sizeof(values) / sizeof(*values)));
        return values[ix];
    }

    // IO methods
    void Read(std::istream& stream);
    void Write(std::ostream& stream) const;

private:
    void Add(const Complex& other) noexcept {
        this->re += other.re; 
        this->im += other.im;
    }

    void Sub(const Complex& other) noexcept {
        Add(Complex{ -other.re, -other.im });
    }

    void Mul(const Complex& other) noexcept {
        this->re = this->re * other.re - this->im * other.im;
        this->im = this->re * other.im + this->im * other.re;
    }

    void Div(const Complex& other) noexcept {
        double denominator = (other * other.Conj()).re;
        Complex numerator = *this * other.Conj();
        *this = Complex{ numerator.re / denominator, numerator.im / denominator };
    }

    bool Equ(const Complex& other) noexcept {
        return (this->re == other.re) && (this->im == other.im);
    }

    Complex Conj() const noexcept {
        return Complex{ this->re, -this->im };
    }
    
    double Mod() const noexcept {
        return std::sqrt((*this * this->Conj()).re);
    }

    std::string Str() const {
        std::stringstream string;
        Write(string);
        return string.str();
    }

    union {
        double values[2];
        struct {
            double re, im;
        };
    };

    friend int Compare(const Complex& left, const Complex& right);
};

inline std::ostream& operator<<(std::ostream& out, const Complex& c) {
    c.Write(out);
    return out;
}

inline std::istream& operator>>(std::istream& input, Complex& c) {
    c.Read(input);
    return input;
}

int Compare(const Complex& left, const Complex& right);
