## Descripción

Este programa en C++ utiliza las bibliotecas OpenCV y de hilos para procesar imágenes. Inicia incluyendo las bibliotecas necesarias, estableciendo espacios de nombres para simplificar el código. El programa define la función processImage, que procesa una porción de la imagen en escala de grises.

El usuario debe proporcionar tres argumentos de línea de comandos: el archivo de entrada, el de salida y el número de hilos. En caso de error en la entrada de argumentos, se emite un mensaje y el programa termina.

Después de cargar la imagen de entrada en color, el programa imprime sus dimensiones, convierte la imagen a escala de grises y la guarda en el archivo de salida. Luego, inicia un temporizador y crea hilos según la especificación del usuario. Cada hilo procesa una parte de la imagen en paralelo.

Tras finalizar el procesamiento paralelo, se detiene el temporizador, se imprime el tiempo en microsegundos y se muestra la imagen en una ventana. El programa espera a que el usuario presione una tecla antes de finalizar.
