# Alberto Cámara Ortiz
# Título: Makefile para la práctica 1 de algorítmica.
# Práctica 1. Cálculo de la eficiencia de algoritmos.

PROYECTO = "Calculo de la eficiencia de algoritmos."
HOME = .
TIEMPOS = $(HOME)$(HOME)/tiempos

all: preambulo ejecutables ejecucion clean-bin final

#------------------------------------------------------------------------------
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Realizacion de la practica 1.
	@echo PROYECTO: $(PROYECTO)	
	@echo
	@echo ALGORITMICA
	@echo
	@echo Alberto Camara Ortiz
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo


#------------------------------------------------------------------------------
ejecutables:
	@echo Creacion de los archivos .bin de todos los algoritmos.
	@echo
	
	@g++ -o Burbuja.bin Burbuja.cpp -std=c++11
	@echo Creado el archivo Burbuja.bin
	
	@g++ -o Mergesort.bin mergesort.cpp -std=c++11
	@echo Creado el archivo Mergesort.bin
	
	@g++ -o Insertionsort.bin insertionsort.cpp -std=c++11
	@echo Creado el archivo Insertionsort.bin
	
	@g++ -o Countingsort.bin countingsort.cpp -std=c++11
	@echo Creado el archivo Countinsort.bin
	
	@g++ -o Quicksort.bin Quicksort.cpp -std=c++11
	@echo Creado el archivo Quicksort.bin
	
	@echo
	@echo Tambien es posible ejecutar todos los archivos .bin \
		con el siguiente comando: "make ejecucion"
	
	@echo Fin creacion de archivos .bin
	
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------	
ejecucion:
	@echo Esta ejecución va a ejecutar todos los ficheros ejecutables, \
		puede que tarde un par de minutos dependiendo de los argumentos\
		de entrada.
	@echo
	@echo
	@echo Ejecucion del algoritmo Burbuja:
	$(HOME)/Burbuja.bin $(HOME)/$(TIEMPOS)/burbuja.txt \
					12345 10000 20000 30000 40000 50000
	@echo
	
	@echo
	@echo
	@echo Ejecucion del algoritmo Mergesort
	$(HOME)/Mergesort.bin $(TIEMPOS)/mergeSort.txt \
					12345 10000 20000 30000 40000 50000
	
	@echo
	@echo
	@echo Ejecucion del algoritmo Quicksort
	$(HOME)/Quicksort.bin $(TIEMPOS)/Quicksort.txt  \
					12345 10000 20000 30000 40000 50000
	
		
	@echo
	@echo
	@echo Ejecucion del algoritmo InsertionSort
	$(HOME)/Insertionsort.bin $(TIEMPOS)/insertionSort.txt \
					12345 10000 20000 30000 40000 50000
	
	@echo
	@echo
	@echo Ejecucion del algoritmo Countingsort
	@echo
	$(HOME)/Countingsort.bin $(TIEMPOS)/countingSort.txt \
					12345 10000 20000 30000 40000 50000
	
	@echo
	@echo Se han modificado los valores para evitar tiempos de espera \
		mayores, hay que tener en cuenta que todos los algoritmos no \
		tienen el mismo roden de eficiencia.
	@echo Los valores obtenidos se encuentran en la carpeta $(TIEMPOS)
	
	@echo ------------------------------------------------------------
#-------------------------------------------------------------------------------
clean-bin:
	@echo Borrando ejecutables
	-rm $(HOME)/*.bin
	@echo ...Borrados ejecutables del proyecto
	@echo
	@echo ------------------------------------------------------------
	@echo
#-------------------------------------------------------------------------------
clean-txt:
	@echo Borrando tiempos
	-rm $(TIEMPOS)/*.txt
	@echo ...Borrados tiempos del proyecto
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
final:
	@echo
	@echo Final de la ejecucion.
	@echo
	@echo ------------------------------------------------------------
#------------------------------------------------------------------------------
