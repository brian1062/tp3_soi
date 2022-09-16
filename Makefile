WWp = gcc -Wall -Werror -pedantic
# $(W) para poder usarla
# poniendo @adelante de algun comando no imprimimos el comando por consola
 
programa: main.o lib_static.a libfsys.so
	$(WWp) -o main main.o -L./libs/ -l_static -ldl -Wl,-rpath,./libs/
	
main.o: main.c ./library/utils.h
	$(WWp) main.c -c	

cJSON.o:
	$(WWp) cJSON.c -c

BrianGerard_punto1.o: ./library/BrianGerard_punto1.c ./library/utils.h
	$(WWp) ./library/BrianGerard_punto1.c -c

BrianGerard_punto2.o: ./library/BrianGerard_punto2.c ./library/utils.h
	$(WWp) ./library/BrianGerard_punto2.c -c

lib_static.a: cJSON.o BrianGerard_punto1.o BrianGerard_punto2.o
	mkdir -p ./libs/
	ar cr ./libs/lib_static.a BrianGerard_punto1.o BrianGerard_punto2.o cJSON.o 

filesystems.o: ./library/filesystems.c
	$(WWp) ./library/filesystems.c -c

libfsys.so: filesystems.o cJSON.o
	$(WWp) -shared -fPIC -o libfsys.so filesystems.o cJSON.o
	mv ./libfsys.so ./libs/	

clean:
	rm -f *.o
	rm -f -d ./libs/* ./libs/
	rm -f main
