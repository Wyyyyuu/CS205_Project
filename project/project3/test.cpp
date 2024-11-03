#include <opencv2/opencv.hpp>

int main() {
    // 读取图像
    cv::Mat image = cv::imread("123.png");

    // 定义卷积核
    cv::Mat kernel = (cv::Mat_<float>(3,3) << 2, -1, 2,
                                              -1, 5, -1,
                                              2, -1, 2);

    // 对图像进行卷积运算
    cv::Mat result;
    cv::filter2D(image, result, -1, kernel);

    // 显示结果
    cv::imshow("Result", result);
    cv::waitKey(0);

    return 0;
}