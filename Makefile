all: lang

lang: dirs temp/main.o temp/prompt.o temp/script.o temp/context.o temp/variable.o temp/error.o
	gcc temp/*.o -lpthread -o lang

dirs:
	test -d "temp" || mkdir temp

temp/main.o:
	gcc -c src/lang.c -o temp/main.o

temp/prompt.o:
	gcc -c src/prompt.c -o temp/prompt.o

temp/script.o:
	gcc -c src/script.c -o temp/script.o

temp/context.o:
	gcc -c src/context.c -o temp/context.o

temp/variable.o:
	gcc -c src/variable.c -o temp/variable.o

temp/error.o:
	gcc -c src/error.c -o temp/error.o

clean:
	rm -Rf temp

rebuild: clean lang

