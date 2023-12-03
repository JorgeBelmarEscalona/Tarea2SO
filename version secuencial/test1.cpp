#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace std::chrono;

int main(int argc, char** argv) {
    // Verificar si se proporcionaron los argumentos correctos.
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <imagen_entrada> <imagen_salida>" << endl;
        return -1;
    }

    // Leer el archivo de imagen.
    Mat image = imread(argv[1], IMREAD_COLOR);

    // Verificar si la imagen se carga correctamente.
    if (image.empty()) {
        cout << "Error al cargar la imagen." << endl;
        return -1;
    }

    // Mostrar las dimensiones de la imagen.
    cout << "Dimensiones de la imagen: " << image.rows << "x" << image.cols << endl;

    // Iniciar el temporizador.
    auto start = high_resolution_clock::now();

    // Convertir la imagen a escala de grises.
    Mat grayscaleImage;
    cvtColor(image, grayscaleImage, COLOR_BGR2GRAY);

    // Leer cada píxel (píxel en escala de grises).
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

    // Mostrar la imagen en escala de grises.
    namedWindow("Imagen en escala de grises", WINDOW_NORMAL);
    imshow("Imagen en escala de grises", grayscaleImage);
    waitKey(0);

    // Guardar la imagen en escala de grises.
    imwrite(argv[2], grayscaleImage);

    return 0;
}