calculadora: calculadora.o titulo.o funciones.o
	g++ -o calculadora calculadora.o titulo.o funciones.o

calculadora.o: calculadora.cpp titulo.h
	g++ -c calculadora.cpp

titulo.o: titulo.cpp titulo.h
	g++ -c titulo.cpp

funciones.o: funciones.cpp funciones.h
	g++ -c funciones.cpp

clean:
	rm -f *.o calculadora
