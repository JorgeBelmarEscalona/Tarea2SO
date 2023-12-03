Este programa en C++ utiliza las bibliotecas OpenCV y OpenMP para procesar imágenes. 
Toma una imagen de entrada, la convierte a escala de grises, procesa la imagen en paralelo usando múltiples hilos, muestra y guarda la imagen en escala de grises, y mide el tiempo de procesamiento. 

Se espera que el usuario proporcione tres argumentos: el nombre del archivo de entrada, el nombre del archivo de salida y el número de hilos. 
Si no se proporcionan tres argumentos, el programa emite un mensaje de error y finaliza. 

Después de cargar la imagen, inicia un temporizador, convierte la imagen a escala de grises, configura el número de hilos y procesa la imagen en paralelo. 

Al final, detiene el temporizador, imprime el tiempo de procesamiento, guarda la imagen y la muestra en una ventana.
