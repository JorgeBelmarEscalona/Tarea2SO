#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <omp.h> // Incluir la biblioteca OpenMP

using namespace cv;
using namespace std;
using namespace std::chrono;

int main(int argc, char** argv) {
    // Verificar si se proporcionan los argumentos correctos.
    if (argc != 4) {
        cout << "Uso: ./programa <ruta_imagen> <ruta_imagen_escala_grises> <num_hebras>" << endl;
        return -1;
    }

    // Leer el archivo de imagen.
    Mat image = imread(argv[1], IMREAD_COLOR);

    // Verificar si la imagen se carga correctamente.
    if (image.empty()) {
        cout << "Error al cargar la imagen." << endl;
        return -1;
    }

    // Iniciar el temporizador.
    auto start = high_resolution_clock::now();

    // Convertir la imagen a escala de grises.
    Mat grayscaleImage;
    cvtColor(image, grayscaleImage, COLOR_BGR2GRAY);

    // Establecer el número de hilos.
    omp_set_num_threads(atoi(argv[3]));

    // Leer cada píxel (píxel en escala de grises).
    #pragma omp parallel for // Directiva OpenMP para paralelizar el bucle
    for (int r = 0; r < grayscaleImage.rows; r++) {
        for (int c = 0; c < grayscaleImage.cols; c++) {
            uchar intensity = grayscaleImage.at<uchar>(r, c);
        }
    }

    // Detener el temporizador.
    auto stop = high_resolution_clock::now();

    // Calcular y mostrar la duración del procesamiento de la imagen.
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo de procesamiento de la imagen: " << duration.count() << " microsegundos." << endl;

    // Guardar la imagen en escala de grises.
    imwrite(argv[2], grayscaleImage);

    // Mostrar la imagen en escala de grises.
    namedWindow("Imagen en escala de grises", WINDOW_NORMAL);
    imshow("Imagen en escala de grises", grayscaleImage);
    waitKey(0);

    return 0;
}