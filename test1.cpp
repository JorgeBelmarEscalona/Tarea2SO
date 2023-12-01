#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace std::chrono;

int main() {
    // Leer el archivo de imagen.
    Mat image = imread("imagenacolor.jpg", IMREAD_COLOR);

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

    // Mostrar la imagen en escala de grises (opcional).
    imshow("Grayscale Image", grayscaleImage);
    waitKey(0);

    return 0;
}