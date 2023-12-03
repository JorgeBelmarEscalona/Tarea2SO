# Tarea2SO

Autores: Jorge Belmar, Cristian Contreras


Grupo: N°7


## Descripción
Este proyecto presenta tres versiones de un programa para convertir imágenes a escala de grises en C++, utilizando diferentes enfoques: secuencial, paralelo con OpenMP y paralelo con threads. 


El repositorio contiene la Tarea 2 del curso de Sistemas Operativos impartido por el profesor Alejandro Mauricio Valdés Jiménez.



```bash 
Supongamos que tiene una imagen a color representada como una matriz bidimensional
de pixeles. La tarea consiste en aplicar un filtro a dicha imagen para transformala a escala 
de grises (sin utilizar alguna funcion o metodo disponible, debe ser mediante la
manipulacion de la matriz que representa la imagen). Debe implementar una
version secuencial funcional y dos versiones paralelas, una de ellas utilizando la
clase thread y otra utilizando la API OpenMP (Revisar practicos de la Leccion 4 en moodle).
Para leer una imagen y manipularla como una matriz de pixeles utilizar la libreria OpenCV.
En Debian (y distribuciones basadas en) debe instalar el paquete libopencv-dev.
