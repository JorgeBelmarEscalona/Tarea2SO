#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include <vector>

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

int main(int argc, char** argv) {
    // Verificar si se proporcionaron los argumentos correctos.
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <ruta de la imagen> <ruta de la imagen en escala de grises> <número de hilos>" << endl;
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

    // Convertir la imagen a escala de grises.
    Mat grayscaleImage;
    cvtColor(image, grayscaleImage, COLOR_BGR2GRAY);

    // Guardar la imagen en escala de grises.
    imwrite(argv[2], grayscaleImage);

    // Iniciar el temporizador.
    auto start = high_resolution_clock::now();

    // Crear hilos y dividir la imagen en partes para procesar.
    int numThreads = stoi(argv[3]);
    vector<thread> threads(numThreads);
    int rowsPerThread = grayscaleImage.rows / numThreads;
    for (int i = 0; i < numThreads; i++) {
        threads[i] = thread(processImage, grayscaleImage, i * rowsPerThread, (i + 1) * rowsPerThread);
    }

    // Esperar a que todos los hilos terminen.
    for (auto& t : threads) {
        t.join();
    }

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