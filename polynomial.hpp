
#ifndef polynomial_H
#define polynomial_H

#include <cstddef>

template<typename T>
class polynomial
{
    private:
        std::size_t numTerms;
        T * coefficients;

        void resizeCoefficients( std::size_t newSize );

    public:
        polynomial();

        ~polynomial();

        void setCoeff( std::size_t term, T value );

        T coeffAt( std::size_t term );

        std::size_t order();

        T eval( T val );
};

#endif


