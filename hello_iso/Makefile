hello:hello.o
	gcc -o hello hello.o
hello.o:hello.s
	gcc -c -o hello.o hello.s
hello.s:hello.i
	gcc -S -o hello.s hello.i
hello.i:hello.c
	gcc -E -o hello.i hello.c
.PHONY:clean
clean:
	rm -f hello.i hello.s hello.o hello
