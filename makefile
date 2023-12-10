cartao: main.o aplicador.o estoque.o gerente.o historico.o paciente.o usuario.o vacina.o
	g++ main.o aplicador.o estoque.o gerente.o historico.o paciente.o usuario.o vacina.o -o cartao

main.o: main.cpp
	g++ -c main.cpp

aplicador.o: aplicador.cpp
	g++ -c aplicador.cpp

estoque.o: estoque.cpp
	g++ -c estoque.cpp

gerente.o: gerente.cpp
	g++ -c gerente.cpp

historico.o: historico.cpp
	g++ -c historico.cpp

paciente.o: paciente.cpp
	g++ -c paciente.cpp

usuario.o: usuario.cpp
	g++ -c usuario.cpp

vacina.o: vacina.cpp
	g++ -c vacina.cpp

run:
	./cartao

clean:
	rm *.o cartao