
template<typename T>
class polynomial
{
    private:
        std::size_t numTerms;
        T * coefficients;

        void resizeCoefficients( std::size_t newSize )
        {
            if( newSize > numTerms )
            {
                T * newcoeffs = new T[newSize];
                std::size_t iterator;
                for( iterator = 0; iterator < numTerms; iterator++ )
                {
                    newcoeffs[iterator] = coefficients[iterator];
                }
                for( iterator = numTerms; iterator < newSize; iterator++ )
                {
                    newcoeffs[iterator] = (T) 0;
                }

                if( coefficients )
                {
                    delete[] coefficients;
                    coefficients = nullptr;
                }

                coefficients = newcoeffs;
                numTerms = newSize;
            }
            else if( newSize < numTerms )
            {
                T * newcoeffs = new T[newSize];
                std::size_t iterator;
                for( iterator = 0; iterator < newSize; iterator++ )
                {
                    newcoeffs[iterator] = coefficients[iterator];
                }
                if( coefficients )
                {
                    delete[] coefficients;
                    coefficients = nullptr;
                }

                coefficients = newcoeffs;
                numTerms = newSize;
            }
        }

    public:
        polynomial()
        {
            numTerms = 0;
            coefficients = nullptr;
        }

        ~polynomial()
        {
            if( coefficients )
            {
                delete[] coefficients;
                coefficients = nullptr;
            }
            numTerms = 0;
        }

        void setCoeff( std::size_t term, T value )
        {
            if( term >= numTerms )
                resizeCoefficients( term + 1 );

            coefficients[term] = value;
        }

        T coeffAt( std::size_t term )
        {
            if( term < numTerms )
                return coefficients[term];
            else
                return (T) 0;
        }

        std::size_t order()
        {
            return numTerms;
        }


        T eval( T val )
        {
            std::size_t iterator;
            T lePow = (T) 1;
            T result = (T) 0;
            for( iterator = 0; iterator < numTerms; iterator++ )
            {
                result += coefficients[iterator]*lePow;
                lePow *= val;
            }

            return result;
        }
};
