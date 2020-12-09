MF= Makefile
F=*.c #source files
O=*.o #object files
H=*.h #header files
CC=gcc #compiler
FILE=$1

all:
			make -f ${MF} run

$FILE: $FILE.o
				$(CC) -o $@ $<

$FILE.c: $O
				$(CC) -l $@ $<
run: $F
			./$F

clean:
		#rm $F
