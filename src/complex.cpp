#include <lab/complex.hpp>

void Complex::Read(std::istream& stream) {
    stream >> re >> im;
}

void Complex::Write(std::ostream& stream) const {
    stream << re << " " << im;
}

int Compare(const Complex& left, const Complex& right) {
    double leftMod = left.Mod();
    double rightMod = right.Mod();

    return (leftMod < rightMod)
        ? -1
        : (leftMod == rightMod
            ? 0
            : 1);
}
