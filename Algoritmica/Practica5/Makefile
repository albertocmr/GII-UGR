# Título: Makefile para la práctica 5 de Algorítmica.
# Práctica 5. Programacion Dinamica.

PROYECTO = "Programacion Dinamica."
HOME = .
CODIGOS = $(HOME)/codigos
TIEMPOS = $(HOME)/tiempos

all: preambulo ejecutables final

#------------------------------------------------------------------------------
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Realizacion de la practica 5.
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
	
	@g++ -o $(CODIGOS)/Ej1.bin $(CODIGOS)/Ej1.cpp -std=c++11
	@echo Creado el archivo Ej1.bin
	
	@g++ -o $(CODIGOS)/Ej2.bin $(CODIGOS)/Ej2.cpp -std=c++11
	@echo Creado el archivo Ej2.bin
	
	@g++ -o $(CODIGOS)/Ej3.bin $(CODIGOS)/Ej3.cpp -std=c++11
	@echo Creado el archivo Ej3.bin
	
	@g++ -o $(CODIGOS)/Ej4.bin $(CODIGOS)/Ej4.cpp -std=c++11
	@echo Creado el archivo Ej4.bin
	
	@echo
	@echo Fin creacion de archivos .bin
	@echo
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej1:
	@echo
	@echo Ejecucion del algoritmo Ej1
	$(CODIGOS)/Ej1.bin 1 5
	@echo
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej2:
	@echo
	@echo Ejecucion del algoritmo Ej2
	$(CODIGOS)/Ej2.bin
	@echo
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej3:
	@echo
	@echo Ejecucion del algoritmo Ej3
	$(CODIGOS)/Ej3.bin
	@echo
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej4:
	@echo
	@echo Ejecucion del algoritmo Ej4
	$(CODIGOS)/Ej4.bin
	@echo
	@echo
	@echo ------------------------------------------------------------
#------------------------------------------------------------------------------
clean:
	@echo Borrando ejecutables
	-rm $(CODIGOS)/*.bin
	@echo ...Borrados ejecutables del proyecto
	@echo
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
