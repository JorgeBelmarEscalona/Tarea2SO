#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <omp.h>
#include <iostream>

void applyFilterSequential(cv::Mat& img) {
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            cv::Vec3b pixel = img.at<cv::Vec3b>(i, j);
            int gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
            img.at<cv::Vec3b>(i, j) = cv::Vec3b(gray, gray, gray);
        }
    }
}

void applyFilterParallelThread(cv::Mat& img) {
    #pragma omp parallel for
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            cv::Vec3b pixel = img.at<cv::Vec3b>(i, j);
            int gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
            img.at<cv::Vec3b>(i, j) = cv::Vec3b(gray, gray, gray);
        }
    }
}

void applyFilterParallelOpenMP(cv::Mat& img) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            cv::Vec3b pixel = img.at<cv::Vec3b>(i, j);
            int gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
            img.at<cv::Vec3b>(i, j) = cv::Vec3b(gray, gray, gray);
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Uso: " << argv[0] << " <imagen de entrada> <imagen de salida>" << std::endl;
        return -1;
    }

    cv::Mat img = cv::imread(argv[1]);

    if (img.empty()) {
        std::cout << "Error al cargar la imagen " << argv[1] << std::endl;
        return -1;
    }

    applyFilterSequential(img);
    cv::imwrite(argv[2], img);

    img = cv::imread(argv[1]);
    applyFilterParallelThread(img);
    cv::imwrite("thread_" + std::string(argv[2]), img);

    img = cv::imread(argv[1]);
    applyFilterParallelOpenMP(img);
    cv::imwrite("openmp_" + std::string(argv[2]), img);

    return 0;
}