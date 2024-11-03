#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FreeImage.h"

int main() {
    const int width = 1000;
    const int height = 4;
    const int channels = 3;

    // 生成随机矩阵
    float data[height][width][channels];
    srand(time(NULL));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                data[i][j][k] = (float) rand() / RAND_MAX;
            }
        }
    }

    // 初始化FreeImage
    FreeImage_Initialise(TRUE);

    // 创建FreeImage位图
    FIBITMAP* bitmap = FreeImage_Allocate(width, height, channels * 8, 0, 0, 0);
    if (!bitmap) {
        fprintf(stderr, "Failed to allocate FreeImage bitmap.\n");
        return 1;
    }

    // 将矩阵数据复制到位图中
    BYTE* bits = FreeImage_GetBits(bitmap);
    int pitch = FreeImage_GetPitch(bitmap);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                bits[i * pitch + j * channels + k] = (BYTE) (data[i][j][k] * 255.0f);
            }
        }
    }

    // 保存位图为PNG文件
    if (!FreeImage_Save(FIF_PNG, bitmap, "output.png", 0)) {
        fprintf(stderr, "Failed to save output image.\n");
        FreeImage_Unload(bitmap);
        FreeImage_DeInitialise();
        return 1;
    }

    // 释放位图内存
    FreeImage_Unload(bitmap);

    // 反初始化FreeImage
    FreeImage_DeInitialise();

    return 0;
}
