#include <iostream>
#include <opencv2/opencv.hpp>
#include <unistd.h>  // getcwd
#include <limits.h>  // PATH_MAX

using namespace cv;

void printCurrentWorkingDirectory() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::cout << "Diretório atual: " << cwd << std::endl;
    } else {
        std::cerr << "Erro ao obter diretório atual!" << std::endl;
    }
}

int main() {
    printCurrentWorkingDirectory();
    
    // OBS: The build directory is built in out/build
    Mat img = imread("../../img/apple.jpg");
    if (img.empty()) {
        std::cerr << "Erro ao carregar imagem!\n";
        return -1;
    }

    resize(img, img, Size(), 0.5, 0.5);

    Mat grayImg, imgBlur, imgBWBlur, imgCanny, imgCanny2;
    Mat imgBWBlurCanny, imgDilate, imgErode, imgOpening, imgClosing;

    cvtColor(img, grayImg, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlur, Size(5, 5), 0);
    GaussianBlur(grayImg, imgBWBlur, Size(5, 5), 0);

    Canny(img, imgCanny, 10, 100);
    Canny(img, imgCanny2, 50, 100);
    Canny(imgBWBlur, imgBWBlurCanny, 50, 100);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(imgCanny, imgDilate, kernel, Point(-1,-1), 5);
    erode(imgCanny, imgErode, kernel, Point(-1,-1), 2);

    morphologyEx(imgCanny, imgOpening, MORPH_OPEN, kernel);
    morphologyEx(imgCanny, imgClosing, MORPH_CLOSE, kernel);

    imshow("image", img);
    imshow("dilate", imgDilate);
    imshow("erode", imgErode);
    imshow("opening", imgOpening);
    imshow("closing", imgClosing);

    waitKey(0);
    return 0;
}
