all :  main ta_main interface;
	./main

main : Polynomial.h CircularList.h  Node.h Interface.h main.cpp;
	g++ main.cpp -o main

ta_main: Polynomial.h CircularList.h  Node.h Interface.h damon_driver.cpp;
	g++ damon_driver.cpp -o ta_main

interface: Polynomial.h CircularList.h  Node.h Interface.h interfacemain.cpp;
	g++ interfacemain.cpp -o interface

clean:
	rm main ta_main interface;