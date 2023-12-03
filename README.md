# Tarea2SO

Autores: Jorge Belmar, Cristian Contreras


Grupo: N°7


## Descripción
Este proyecto presenta tres versiones de un programa para convertir imágenes a escala de grises en C++, utilizando diferentes enfoques: secuencial, paralelo con OpenMP y paralelo con threads. 


El repositorio contiene la Tarea 2 del curso de Sistemas Operativos impartido por el profesor Alejandro Mauricio Valdés Jiménez.



--bash 
Supongamos que tiene una imagen a color representada como una matriz bidimensional
de p´ıxeles. La tarea consiste en aplicar un filtro a dicha imagen para transformala a escala
de grises (sin utilizar alguna funci´on o m´etodo disponible, debe ser mediante la
manipulaci´on de la matriz que representa la imagen). Debe implementar una
versi´on secuencial funcional y dos versiones paralelas, una de ellas utilizando la clase
thread1 y otra utilizando la API OpenMP2 (Revisar pr´acticos de la Lecci´on 4 en moodle).
Para leer una imagen y manipularla como una matriz de p´ıxeles utilizar la librer´ıa OpenCV3.
En Debian (y distribuciones basadas en) debe instalar el paquete libopencv-dev.
