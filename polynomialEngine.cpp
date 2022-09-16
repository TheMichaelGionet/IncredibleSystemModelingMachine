#include "polynomial.cpp"

template <typename T>
polynomial<T> * addPoly( polynomial<T> * op1, polynomial<T> * op2 )
{
    polynomial<T> * result = new polynomial<T>;
    std::size_t order1 = op1->order();
    std::size_t order2 = op2->order();
    std::size_t order = order1 > order2 ? order1 : order2;

    std::size_t iterator;
    for( iterator = 0; iterator < order; iterator++ )
    {
        result->setCoeff( iterator, op1->coeffAt( iterator ) + op2->coeffAt( iterator ) );
    }

    return result;
}

template <typename T>
polynomial<T> * subPoly( polynomial<T> * op1, polynomial<T> * op2 )
{
    polynomial<T> * result = new polynomial<T>;
    std::size_t order1 = op1->order();
    std::size_t order2 = op2->order();
    std::size_t order = order1 > order2 ? order1 : order2;

    std::size_t iterator;
    for( iterator = 0; iterator < order; iterator++ )
    {
        result->setCoeff( iterator, op1->coeffAt( iterator ) - op2->coeffAt( iterator ) );
    }

    return result;
}

template <typename T>
polynomial<T> * scalePoly( polynomial<T> * op, T scale )
{
    polynomial<T> * result = new polynomial<T>;
    std::size_t order = op->order();
    std::size_t iterator;

    for( iterator = 0; iterator < order; iterator++ )
    {
        result->setCoeff( iterator, scale * op->coeffAt( iterator ) );
    }

    return result;
}

template <typename T>
polynomial<T> * mulPoly( polynomial<T> * op1, polynomial<T> * op2 )
{
    polynomial<T> * result = new polynomial<T>;
    std::size_t order1 = op1->order();
    std::size_t order2 = op2->order();

    std::size_t iterator1;
    std::size_t iterator2;
    for( iterator1 = 0; iterator1 < order1; iterator1++ ) for( iterator2 = 0; iterator2 < order2; iterator2++ )
    {
        T accumulator = result->coeffAt( iterator1 + iterator2 );
        accumulator += op1->coeffAt( iterator1 )*op2->coeffAt( iterator2 );
        result->setCoeff( iterator1 + iterator2, accumulator );
    }

    return result;
}

template <typename T>
polynomial<T> * derivPoly( polynomial<T> * op )
{
    polynomial<T> * result = new polynomial<T>;
    std::size_t order = op->order();
    
    std::size_t iterator;
    for( iterator = 0; iterator < order-1; iterator++ )
    {
        result->setCoeff( iterator, op->coeffAt( iterator+1 ) * ( iterator + 1 ) );
    }

    return result;
}

template <typename T>
polynomial<T> * antiderivPoly( polynomial<T> * op, T newCoeff )
{
    polynomial<T> * result = new polynomial<T>;
    std::size_t order = op->order();

    result->setCoeff( 0, newCoeff );

    std::size_t iterator;
    for( iterator = 0; iterator < order; iterator++ )
    {
        result->setCoeff( iterator + 1, op->coeffAt( iterator ) / ( iterator + 1 ) );
    }

    return result;
}

// op1(op2(x))
template <typename T>
polynomial<T> * combinePoly( polynomial<T> * op1, polynomial<T> * op2 )
{
    polynomial<T> * polyPower = new polynomial<T>;
    polynomial<T> * result = new polynomial<T>;
    polyPower->setCoeff( 0, (T) 1 );

    std::size_t order = op1->order();
    std::size_t iterator;
    for( iterator = 0; iterator < order; iterator++ )
    {
        polynomial<T> * subresult = scalePoly<T>( polyPower, op2->coeffAt( iterator ) );
        polynomial<T> * nextResult = addPoly<T>( subresult, result );

        polynomial<T> * nextPolyPower = mulPoly<T>( polyPower, op2 );
        delete polyPower;

        polyPower = nextPolyPower;
        delete nextResult;
        delete subresult;
        nextResult = nullptr;
        subresult = nullptr;
    }

    delete polyPower;
    polyPower = nullptr;

    return result;
}

