All: MakeObjBin Polynomials Tests


MakeObjBin:
	-mkdir ./obj/
	-mkdir ./bin/


Polynomials: polynomial.cpp polynomialEngine.cpp
	-g++ -c -o ./obj/polynomial.o polynomial.cpp
	-g++ -c -o ./obj/polynomialEngine.o polynomialEngine.cpp


Tests: TestPolynomial.cpp polynomial.o
	-g++ -c -o ./obj/TestPolynomial.o TestPolynomial.cpp
	-g++ -o ./bin/TestPolynomial ./obj/TestPolynomial.o ./obj/polynomial.o ./obj/polynomialEngine.o

clean:
	-rm -r ./obj
	-rm -r ./bin
