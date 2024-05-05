# Título: Makefile para la práctica 3 de algorítmica.
# Práctica 3. Algoritmos voraces.

PROYECTO = "Algoritmos Greedy."
HOME = .
CODIGOS = $(HOME)/codigos
TIEMPOS = $(HOME)/tiempos

all: preambulo ejecutables final

#------------------------------------------------------------------------------
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Realizacion de la practica 3.
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
	
	@g++ -o $(CODIGOS)/Ej5.bin $(CODIGOS)/Ej5.cpp -std=c++11
	@echo Creado el archivo Ej5.bin
	
	@echo
	
	@echo Fin creacion de archivos .bin
	
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej1:
	@echo
	@echo Ejecucion del algoritmo Ej1
	$(CODIGOS)/Ej1.bin
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej2:
	@echo
	@echo Ejecucion del algoritmo Ej2
	$(CODIGOS)/Ej2.bin
	@echo
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej3:
	@echo
	@echo Ejecucion del algoritmo Ej3
	$(CODIGOS)/Ej3.bin 1000 20 150
	@echo
	@echo ------------------------------------------------------------
	@echo Esta ejecucion está hecha con los argumentos ./Ej3.bin 1000 20 150
	@echo Al usar una semilla aleatoria, habrá veces que genere gasolineras 
	@echo que no se pueden alcanzar. Puede volver a ejecutar y probar suerte
	@echo o cambiar el número que corresponde al número de gasolineras o al
	@echo tanque de gasolina.
	@echo ------------------------------------------------------------
	@echo
#------------------------------------------------------------------------------
ej4:
	@echo
	@echo
	@echo Ejecucion del algoritmo Ej4
	$(CODIGOS)/Ej4.bin
	@echo
	@echo
	@echo
	@echo ------------------------------------------------------------
#------------------------------------------------------------------------------
ej5:
	@echo
	@echo Ejecucion del algoritmo Ej5
	$(CODIGOS)/Ej5.bin
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
