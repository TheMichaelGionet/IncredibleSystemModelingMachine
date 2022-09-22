
#ifndef polynomialEngine_H
#define polynomialEngine_H

#include <cstddef>

template <typename T>
polynomial<T> * addPoly( polynomial<T> * op1, polynomial<T> * op2 );

template <typename T>
polynomial<T> * subPoly( polynomial<T> * op1, polynomial<T> * op2 );

template <typename T>
polynomial<T> * scalePoly( polynomial<T> * op, T scale );

template <typename T>
polynomial<T> * mulPoly( polynomial<T> * op1, polynomial<T> * op2 );

template <typename T>
polynomial<T> * derivPoly( polynomial<T> * op );

template <typename T>
polynomial<T> * antiderivPoly( polynomial<T> * op, T newCoeff );

// op1(op2(x))
template <typename T>
polynomial<T> * combinePoly( polynomial<T> * op1, polynomial<T> * op2 );

#endif

