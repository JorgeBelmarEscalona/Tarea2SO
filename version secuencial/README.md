## Descripción

Este programa en C++ utiliza la biblioteca OpenCV para procesar imágenes. 

Al iniciar, incluye las bibliotecas necesarias y establece espacios de nombres para simplificar el código. 
El programa espera dos argumentos de línea de comandos: el archivo de entrada y el de salida. 
Si no se proporcionan exactamente dos argumentos, se emite un mensaje de error y finaliza.

Después de cargar la imagen de entrada en color, el programa imprime sus dimensiones y mide el tiempo de procesamiento. 
Luego, convierte la imagen a escala de grises y recorre cada píxel. Tras finalizar el procesamiento, detiene el temporizador, imprime el tiempo en microsegundos y muestra la imagen en una ventana. 

Finalmente, espera a que el usuario presione una tecla, y guarda la imagen en escala de grises en el archivo de salida.
