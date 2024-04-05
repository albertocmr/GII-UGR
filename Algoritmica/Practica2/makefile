# Título: Makefile para la práctica 2 de algorítmica.
# Práctica 2. Algoritmos Divide y Vencerás.

PROYECTO = "Algoritmos Divide y Venceras."
HOME = .
CODIGOS = $(HOME)/codigos
TIEMPOS = $(HOME)/tiempos

all: preambulo ejecutables final

#------------------------------------------------------------------------------
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Realizacion de la practica 2.
	@echo PROYECTO: $(PROYECTO)	
	@echo
	@echo ALGORITMICA
	@echo
	@echo Alberto Camara Ortiz
	@echo Jose Vera Castillo
	@echo Pablo Rejon Camacho
	@echo Cristobal Perez Simon
	@echo Miguel Rodriguez Ayllon
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo


#------------------------------------------------------------------------------
ejecutables:
	@echo Creacion de los archivos .bin de todos los algoritmos.
	@echo
	
	@g++ -o $(CODIGOS)/Ej1_FB.bin $(CODIGOS)/Ej1_FB.cpp -std=c++11
	@echo Creado el archivo Ej1_FB.bin
		
	@g++ -o $(CODIGOS)/Ej1_DyV.bin $(CODIGOS)/Ej1_DyV.cpp -std=c++11
	@echo Creado el archivo Ej1_DyV.bin
	
	@g++ -o $(CODIGOS)/Ej2_FB.bin $(CODIGOS)/Ej2_FB.cpp -std=c++11
	@echo Creado el archivo Ej2_FB.bin
		
	@g++ -o $(CODIGOS)/Ej2_DyV.bin $(CODIGOS)/Ej2_DyV.cpp -std=c++11
	@echo Creado el archivo Ej2_FB.bin
	
	@g++ -o $(CODIGOS)/Ej3_FB.bin $(CODIGOS)/Ej3_FB.cpp -std=c++11
	@echo Creado el archivo Ej3_FB.bin
		
	@g++ -o $(CODIGOS)/Ej3_DyV.bin $(CODIGOS)/Ej3_DyV.cpp -std=c++11
	@echo Creado el archivo Ej3_DyV.bin
	
	@g++ -o $(CODIGOS)/Ej4_FB.bin $(CODIGOS)/Ej4_FB.cpp -std=c++11
	@echo Creado el archivo Ej4_FB.bin
		
	@g++ -o $(CODIGOS)/Ej4_DyV.bin $(CODIGOS)/Ej4_DyV.cpp -std=c++11
	@echo Creado el archivo Ej4_DyV.bin
	
	@g++ -o $(CODIGOS)/Ej5_FB.bin $(CODIGOS)/Ej5_FB.cpp -std=c++11
	@echo Creado el archivo Ej5_FB.bin
		
	@g++ -o $(CODIGOS)/Ej5_DyV.bin $(CODIGOS)/Ej5_DyV.cpp -std=c++11
	@echo Creado el archivo Ej5_DyV.bin
	
	@echo
	
	@echo Fin creacion de archivos .bin
	
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej1:
	@echo
	@echo Ejecucion del algoritmo Ej1_FB
	$(CODIGOS)/Ej1_FB.bin 4 10
	@echo
	@echo
	@echo Ejecucion del algoritmo Ej1_DyV
	$(CODIGOS)/Ej1_DyV.bin 4 10
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej2:
	@echo
	@echo Ejecucion del algoritmo Ej2_FB
	$(CODIGOS)/Ej2_FB.bin 45
	@echo
	@echo
	@echo Ejecucion del algoritmo Ej2_DyV
	$(CODIGOS)/Ej2_DyV.bin 4
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej3:
	@echo
	@echo Ejecucion del algoritmo Ej3_FB con el numero 140556, valor cerca del umbral
	$(CODIGOS)/Ej3_FB.bin 140556
	@echo
	@echo
	@echo Ejecucion del algoritmo Ej3_DyV con el numero 140556, valor cerca del umbral
	$(CODIGOS)/Ej3_DyV.bin 140556
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej4:
	@echo
	@echo
	@echo Ejecucion del algoritmo Ej4_FB con un vector de 16 elementos aleatorios
	$(CODIGOS)/Ej4_FB.bin 16
	@echo
	@echo
	@echo Ejecucion del algoritmo Ej4_DyV con un vector de 16 elementos aleatorios
	$(CODIGOS)/Ej4_DyV.bin 16
	@echo
	@echo ------------------------------------------------------------
	@echo
	@echo
	@echo
	@echo Ejecucion del algoritmo Ej4_FB con un vector de 500 elementos aleatorios
	$(CODIGOS)/Ej4_FB.bin 500
	@echo
	@echo
	@echo Ejecucion del algoritmo Ej4_DyV con un vector de 500 elementos aleatorios
	$(CODIGOS)/Ej4_DyV.bin 500
	@echo
	@echo ------------------------------------------------------------
	@echo
	@echo Este algoritmo cuenta con dos ejecuciones, una con un vector de 16 elementos y otra con un vector de 500 elementos.
	@echo Esto se debe a que con un vector de tantos elementos aleatorios no se puede ver a simple vista los elementos eliminados.
	@echo 16 - Se puede ver a simple vista los elementos eliminados.
	@echo 500 - Valor proximo al umbral == Tiempos parecidos.
	@echo
	@echo ------------------------------------------------------------
#------------------------------------------------------------------------------
ej5:
	@echo
	@echo Ejecucion del algoritmo Ej5_FB
	$(CODIGOS)/Ej5_FB.bin 8
	@echo
	@echo
	@echo Ejecucion del algoritmo Ej5_DyV
	$(CODIGOS)/Ej5_DyV.bin 4
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
clean-bin:
	@echo Borrando ejecutables
	-rm $(CODIGOS)/*.bin
	@echo ...Borrados ejecutables del proyecto
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
clean-txt:
	@echo Borrando tiempos
	-rm $(TIEMPOS)/*.txt
	@echo ...Borrados tiempos del proyecto
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
final:

	@echo Para probar diferentes valores, puede modificar cualquier argumento de cada ejecucion dentro del makefile.
	@echo Si quieres ejecutar cada algoritmo por separado, puedes hacerlo con los siguientes comandos:
	@echo "make ej1"
	@echo "make ej2"
	@echo "make ej3"
	@echo "make ej4"
	@echo "make ej5"
	@echo Final de la ejecucion.
	@echo
	@echo ------------------------------------------------------------
#------------------------------------------------------------------------------
