#pragma once
#include <iostream>
#include <concepts>
#include <numeric>

template<typename I> requires std::integral<I>

class rational {

    I num_;
    I den_;

public:

    rational() : num_(0), den_(1) {}

    rational(const I& n, const I& d){

        if (d == 0) {

            num_ = n;
            den_ = 0;

            return;

        }


        I g = std::gcd(n, d);

        num_ = n / g;
        den_ = d / g;


        if (den_ < 0) {

            num_ = -num_;
            den_ = -den_;

        }


    }

    I num() const {return num_;}
    I den() const {return den_;}
// somma
    rational& operator+=(const rational& other) {

        if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((den_ == 0 && num_ != 0) || (other.den_ == 0 && other.num_ != 0)) {

            if ((num_ > 0 && other.num_ < 0) || (num_ < 0 && other.num_ > 0)) {

                num_ = 0;
                den_ = 0;

            }

            return *this;
        }

        if (den_ == 0 && num_ != 0) return *this;

        if ( other.den_ == 0 && other.num_ != 0) {

            num_ = other.num_;
            den_ = 0;

            return *this;
        }

        I new_den_ = std::lcm(den_, other.den_);
        I new_num_ = num_ *(new_den_/den_) + other.num_ *(new_den_/other.den_);
        I g = std::gcd(new_num_, new_den_);
        num_ = new_num_/ g;
        den_ = new_den_/ g;

        return *this;

    }

    rational operator+(const rational& other) const {

        rational tmp =*this;
        return tmp += other;

    }
// sottrazione
    rational& operator-=(const rational& m) {

        if ((den_ == 0 && num_ == 0) || (m.den_ == 0 && m.num_ == 0)) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((den_ == 0 && num_ != 0) || (m.den_ == 0 && m.num_ != 0)) {

            if ((num_ > 0 && m.num_ < 0) || (num_ < 0 && m.num_ > 0)) {

                num_ = 0;
                den_ = 0;

            }

            return *this;
        }

        if (den_ == 0 && num_ != 0) return *this;

        if ( m.den_ == 0 && m.num_ != 0) {

            num_ = m.num_;
            den_ = 0;

            return *this;
        }

        I new_den_ = std::lcm(den_, m.den_);
        I new_num_ = num_ *(new_den_/den_) - m.num_ *(new_den_/m.den_);
        I g = std::gcd(new_num_, new_den_);
        num_ = new_num_/ g;
        den_ = new_den_/ g;

        return *this;

    }

    rational operator-(const rational& m) const {

        rational tmp =*this;
        return tmp -= m;

    }
// moltiplicazione
    rational& operator*=(const rational& s) {

        if ((den_ == 0 && num_ == 0) || (s.den_ == 0 && s.num_ == 0)) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((den_ == 0 && num_ != 0) || (s.den_ == 0 && s.num_ != 0)) {

            if ((num_ < 0 && s.num_ < 0)||(num_ > 0 && s.num_ > 0)) {

                num_ = 1;
                den_ = 0;

            }
            if ((num_ > 0 && s.num_ < 0)||(num_ < 0 && s.num_ > 0)) {

                num_ = -1;
                den_ = 0;

            return *this;
            }
        }
        I g = std::gcd(num_ * s.num_, den_ * s.den_);
        I new_num_ = num_ * s.num_ / g;
        den_ = den_ * s.den_ / g;
        num_ = new_num_;

        return *this;

    }

    rational operator*(const rational& s) const {

        rational tmp =*this;
        return tmp *= s;

    }
// divisione
    rational& operator/=(const rational& h) {

        if ((den_ == 0 && num_ == 0) || (h.den_ == 0 && h.num_ == 0)) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if (h.num_ == 0){
            if (num_ == 0) {

                num_ = 0;
                den_ = 0;

            } else {

                num_ = (num_ > 0 ? 1 : -1);
                den_ = 0;

            }

            return *this;
        }
        if (den_ == 0 && h.den_ == 0) {

            num_ = 0;
            den_ = 0;

            return *this;
        }

        if (den_ == 0) {

            return *this;
        }

        if (h.den_ == 0) {

            num_ = 0;
            den_ = 1;

            return *this;

        }

        I g = std::gcd(num_ * h.den_, den_ * h.num_);
        I new_num_ = num_ * h.den_ / g;
        den_ = den_ * h.num_ / g;
        num_ = new_num_;

        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }

        return *this;

    }

    rational operator/(const rational& h) const {

        rational tmp =*this;

        return tmp /= h;

    }

};


template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& v){


    if (v.den() == 0 && v.num()== 0) {

        return os << "NaN";
    }
    if (v.den() == 0 && v.num() > 0){

        return os << "+Inf";
    }
    if (v.den() == 0 && v.num() < 0){

        return os << "-Inf";
    }
    if (v.den() != 0 && v.num() == 0){

        return os << "0";
    }

os << v.num() << "/" << v.den() ;

return os;

}
