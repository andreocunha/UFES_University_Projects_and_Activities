#
# Makefile
#
# Aula 11
# Estrutura de Dados 2
#

compile:
	gcc -o exec1.out main.c merge1.c
	gcc -o exec2.out main.c merge2.c
	gcc -o exec3.out main.c merge3.c  
	gcc -o exec4.out main.c merge4.c  
	gcc -o exec5.out main.c merge5.c
	gcc -o exec6.out main.c merge6.c
	gcc -o exec7.out main.c merge7.c

run:
	time ./exec1.out 1000000 ./input/sorted/1000000.txt saida1.txt
	time ./exec2.out 1000000 ./input/sorted/1000000.txt saida2.txt
	time ./exec3.out 1000000 ./input/sorted/1000000.txt saida3.txt
	time ./exec4.out 1000000 ./input/sorted/1000000.txt saida4.txt
	time ./exec5.out 1000000 ./input/sorted/1000000.txt saida5.txt
	time ./exec6.out 1000000 ./input/sorted/1000000.txt saida6.txt
	time ./exec7.out 1000000 ./input/sorted/1000000.txt saida7.txt

diff:
	diff saida1.txt saida2.txt
	diff saida1.txt saida2.txt
	diff saida1.txt saida3.txt
	diff saida1.txt saida4.txt
	diff saida1.txt saida5.txt
	diff saida1.txt saida6.txt
	diff saida1.txt saida7.txt

execute:
	make compile
	make run
	make diff
	make clean

clean:
	rm *.out *.txt