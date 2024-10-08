all: tp3

run: tp3
		@./tp3

tp3: main.o BMH.o ShiftAndExato.o tempo.o 
		gcc -g main.o BMH.o ShiftAndExato.o tempo.o -o tp3

main.o: main.c
		gcc -c main.c -g

BMH.o: BMH.c BMH.h
		gcc -c BMH.c -g

ShiftAndExato.o: ShiftAndExato.c ShiftAndExato.h
		gcc -c ShiftAndExato.c -g

tempo.o: tempo.c tempo.h
		gcc -c tempo.c -g

clean:
		rm *.o tp3*