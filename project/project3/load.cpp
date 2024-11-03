#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void img2matrix(string filename) {
    Mat img = imread(filename, IMREAD_COLOR); // 读取图像
    if (img.empty()) { // 判断图像是否读取成功
        cerr << "Failed to read image " << filename << endl;
        return;
    }

    // 将图像转换为矩阵
    int rows = img.rows;
    int cols = img.cols;
    int channels = img.channels();
    Mat matrix(rows, cols*channels, CV_32F);
    int idx = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Vec3b pixel = img.at<Vec3b>(i, j);
            matrix.at<float>(i, idx++) = pixel[0];
            matrix.at<float>(i, idx++) = pixel[1];
            matrix.at<float>(i, idx++) = pixel[2];
        }
        idx = 0;
    }

    // 将矩阵写入txt文件
    string output_filename = filename.substr(0, filename.find_last_of(".")) + ".txt";
    ofstream output_file(output_filename);
    if (output_file.is_open()) {
        output_file << rows << " " << cols*channels << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols*channels; ++j) {
                output_file << matrix.at<float>(i, j) << " ";
            }
            output_file << endl;
        }
        output_file.close();
    } else {
        cerr << "Failed to open output file " << output_filename << endl;
    }

    namedWindow("image", WINDOW_NORMAL);
    imshow("image", img);
    waitKey(0);
    destroyWindow("image");
}

int main() {
    string filename = "123.png";
    img2matrix(filename);

    return 0;
}


// 编译时加上$(pkg-config --cflags --libs opencv4)