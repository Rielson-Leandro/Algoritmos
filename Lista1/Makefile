OBJS = GeradorAleatorio.o Aviao.o ListaEncadeada.hpp FilaAviao.o \
	Pista.o ListaCircular.hpp ListaPista.o Aeroporto.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

sim : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)

GeradorAleatorio.o : GeradorAleatorio.h GeradorAleatorio.cpp
	$(CC) $(CFLAGS) GeradorAleatorio.cpp

Aviao.o : Aviao.h Aviao.cpp GeradorAleatorio.h
	$(CC) $(CFLAGS) Aviao.cpp

ListaEncadeada.o : ListaEncadeada.hpp
	$(CC) $(CFLAGS) ListaEncadeada.hpp

FilaAviao.o : FilaAviao.h FilaAviao.cpp aviao.h ListaEncadeada.hpp
	$(CC) $(CFLAGS) FilaAviao.cpp

Pista.o : Pista.h Pista.cpp FilaAviao.h
	$(CC) $(CFLAGS) Pista.cpp

ListaCircular.o : ListaCircular.hpp
	$(CC) $(CFLAGS) ListaCircular.hpp

ListaPista.o : ListaPista.h ListaPista.cpp ListaCircular.hpp Pista.h
	$(CC) $(CFLAGS) ListaPista.cpp

Aeroporto.o : Aeroporto.h Aeroporto.cpp GeradorAleatorio.o ListaPista.h Pista.h Aviao.h
	$(CC) $(CFLAGS) Aeroporto.cpp

main.o : main.cpp Aeroporto.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o *~ *.out *.gch
