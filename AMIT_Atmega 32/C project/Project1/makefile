build: main.c
	gcc -E main.c -o main.i
	gcc -S main.c -o main.s
	gcc -c main.c -o main.o
	gcc main.c -o main.exe
run: main.exe
	main.exe