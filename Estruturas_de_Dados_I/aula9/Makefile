compile: testador.c Aluno.c Arvore.c
	gcc -ggdb -std=c99 -Wall -Werror -o testador *.c

clean:
	rm -f *.o a.out core main

run: 
	valgrind --leak-check=full --show-leak-kinds=all ./testador -s