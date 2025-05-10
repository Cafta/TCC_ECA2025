#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture video;
    std::string ip = "https://192.168.15.34:8080/video";

    if (!video.open(ip)) {
        std::cerr << "Erro ao abrir o vídeo!" << std::endl;
        return -1;
    }

    while (true) {
        cv::Mat frame;
        bool ret = video.read(frame);

        if (!ret) {
            std::cerr << "Erro ao ler o frame!" << std::endl;
            break;
        }

        cv::Mat small_frame;
        cv::resize(frame, small_frame, cv::Size(), 0.25, 0.25);
        
        cv::Mat imgCanny;
        cv::Canny(small_frame, imgCanny, 15.0, 150.0, 3, true);

        cv::imshow("Video Com Filtro Canny", imgCanny);
        cv::imshow("video ao vivo", small_frame);

        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    video.release();
    cv::destroyAllWindows();

    return 0;
}