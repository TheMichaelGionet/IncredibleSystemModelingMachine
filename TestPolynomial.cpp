#include <cstddef>
#include "polynomial.hpp"
#include "polynomialEngine.hpp"


// Doing it this way for auto-constructor/destructor stuff.
class TestPolynomial
{
    Polynomial<double> * leConst1;
    Polynomial<double> * leLine1;
    Polynomial<double> * leQuad1;
    Polynomial<double> * leSexDeca1;
    Polynomial<double> * leChonker1;

    Polynomial<double> * leConst2;
    Polynomial<double> * leLine2;
    Polynomial<double> * leQuad2;
    Polynomial<double> * leSexDeca2;
    Polynomial<double> * leChonker2;


    TestPolynomial()
    {
        //leConst1
    }






};

bool testSetup()
{
    // Test 1: Setup a constant.

    // Test 2: Setup a line.

    // Test 3: Setup a quadratic.

    // Test 4: Setup 16 terms.

    // Test 5: Setup 2^16 terms.
}

bool testOps()
{
    // Test 1: Perform standard operations on constants.

    // Test 2: Perform standard ops on a line.

    // Test 3: Perform standard ops on a quadratic.

    // Test 4: Perform standard ops on 16 terms.

    // Test 5: Perform standard ops on 2^16 terms.
}

int main()
{
    TestPolynomial leTest;

    
    return 0;
}
