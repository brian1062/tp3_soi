WWp = gcc -Wall -Werror -pedantic
# $(W) para poder usarla
# poniendo @adelante de algun comando no imprimimos el comando por consola
# 

programa: cJSON.o BrianGerard_punto1.o BrianGerard_punto2.o filesystems.o
	

cJSON.o:
	$(WWp) cJSON.c -c

BrianGerard_punto1.o:
	cd ./library/ && $(WWp) BrianGerard_punto1.c -c

BrianGerard_punto2.o:
	cd ./library/ && $(WWp) BrianGerard_punto2.c -c


clean:
	rm -f *.o
