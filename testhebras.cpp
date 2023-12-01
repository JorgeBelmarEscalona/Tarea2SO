#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>

using namespace cv;
using namespace std;
using namespace std::chrono;

void processImage(Mat image, int startRow, int endRow) {
    // Convertir la imagen a escala de grises y leer cada píxel.
    for (int r = startRow; r < endRow; r++) {
        for (int c = 0; c < image.cols; c++) {
            uchar intensity = image.at<uchar>(r, c);
        }
    }
}

int main() {
    // Leer el archivo de imagen.
    Mat image = imread("imagenacolor.jpg", IMREAD_COLOR);

    // Verificar si la imagen se carga correctamente.
    if (image.empty()) {
        cout << "Error al cargar la imagen." << endl;
        return -1;
    }

    // Convertir la imagen a escala de grises.
    Mat grayscaleImage;
    cvtColor(image, grayscaleImage, COLOR_BGR2GRAY);

    // Iniciar el temporizador.
    auto start = high_resolution_clock::now();

    // Crear 4 hilos y dividir la imagen en 4 partes para procesar.
    int rowsPerThread = grayscaleImage.rows / 4;
    thread t1(processImage, grayscaleImage, 0, rowsPerThread);
    thread t2(processImage, grayscaleImage, rowsPerThread, 2 * rowsPerThread);
    thread t3(processImage, grayscaleImage, 2 * rowsPerThread, 3 * rowsPerThread);
    thread t4(processImage, grayscaleImage, 3 * rowsPerThread, grayscaleImage.rows);

    // Esperar a que todos los hilos terminen.
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // Detener el temporizador.
    auto stop = high_resolution_clock::now();

    // Calcular y mostrar la duración del procesamiento de la imagen.
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo de procesamiento de la imagen: " << duration.count() << " microsegundos." << endl;

    // Mostrar la imagen
    namedWindow("Imagen", WINDOW_NORMAL);
    imshow("Imagen", grayscaleImage);
    waitKey(0);

    return 0;
}