prog.exe:main.c iir.o fir.o affichage.o fichiers.o integration.o mesure.o lecture.o define.h
	gcc main.c iir.o fir.o affichage.o fichiers.o integration.o mesure.o lecture.o -lftd2xx -o prog.exe
main.o:main.c main.h
	gcc -c main.c
iir.o:iir.c iir.h
	gcc -c iir.c
fir.o:fir.c fir.h
	gcc -c fir.c
affichage.o:affichage.c affichage.h
	gcc -c affichage.c
fichiers.o:fichiers.c fichiers.h
	gcc -c fichiers.c
integration.o:integration.c integration.h
	gcc -c integration.c
mesure.o:mesure.c mesure.h
	gcc -c mesure.c
lecture.o:lecture.c lecture.h
	gcc -c lecture.c
clean:
	rm -rf *.o *.exe
