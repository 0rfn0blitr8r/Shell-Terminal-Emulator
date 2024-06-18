all:dir.c date.c Q_2.c
	gcc -o dir dir.c
	gcc -o date date.c
	gcc -o Q_2 Q_2.c
	./Q_2