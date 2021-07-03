#
# Makefile
#
# Aula 13
# Estrutura de Dados 2
#

compile1:
	gcc -o exec.out main.c quicksort1.c -Wno-error=implicit-function-declaration

compile2:
	gcc -o exec.out main.c quicksort2.c -Wno-error=implicit-function-declaration

compile3:
	gcc -o exec.out main.c quicksort3.c -Wno-error=implicit-function-declaration

compile4:
	gcc -o exec.out main.c quicksort4.c -Wno-error=implicit-function-declaration

run:
	time ./exec.out 10000000 ./few_uniq/10M_const_keys_sorted.txt saida1.txt
	time ./exec.out 10000000 ./few_uniq/10M_const_keys_unif_rand.txt saida2.txt
	time ./exec.out 10000000 ./nearly_sorted/10000000.txt saida3.txt
	time ./exec.out 10000000 ./reverse_sorted/10000000.txt saida4.txt
	time ./exec.out 10000000 ./sorted/10000000.txt saida5.txt
	time ./exec.out 10000000 ./unif_rand/10000000.txt saida6.txt

diff:
	diff saida1.txt saida2.txt
	diff saida3.txt saida4.txt
	diff saida3.txt saida5.txt
	diff saida3.txt saida6.txt

execute:
	make run
	make diff
	make clean

executeAll:
	make compile1
	make execute
	make compile2
	make execute
	make compile3
	make execute
	make compile4
	make execute

clean:
	rm *.out *.txt