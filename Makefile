all: lang perms

lang: dirs temp/main.o temp/prompt.o temp/script.o
	gcc temp/*.o -o lang

dirs:
	test -d "temp" || mkdir temp

temp/main.o:
	gcc -c src/lang.c -o temp/main.o

temp/prompt.o:
	gcc -c src/prompt.c -o temp/prompt.o

temp/script.o:
	gcc -c src/script.c -o temp/script.o

perms:
	chmod +x lang

clean:
	rm -Rf temp

rebuild: clean lang

