#pragma GCC optimize(3)
#include <stdio.h>
#include <stdlib.h>
#include <FreeImage.h>
#include <time.h>
#ifdef _OPENMP
#include <omp.h>
#endif

// 定义float32数据类型
typedef struct
{
    int height;
    int width;
    int channel;
    float ***data;
} float32;

// 读取图像
void read_image(char *filename, float32* input)
{
    FIBITMAP *bitmap = FreeImage_Load(FreeImage_GetFIFFromFilename(filename), filename, 0);
    if (!bitmap)
    {
        fprintf(stderr, "文件读取失败！\n");
    }

    input->height = FreeImage_GetHeight(bitmap);
    input->width = FreeImage_GetWidth(bitmap);
    int bpp = FreeImage_GetBPP(bitmap); // 获取位深
    input->channel = bpp / 8;

    // 为input分配内存
    input->data = (float ***)malloc(input->height * sizeof(float **));
    for (int i = 0; i < input->height; i++)
    {
        input->data[i] = (float **)malloc(input->width * sizeof(float *));
        for (int j = 0; j < input->width; j++)
        {
            input->data[i][j] = (float *)malloc(input->channel * sizeof(float));
        }
    }

    // 将数据分配到data中，data为三维矩阵，从内到外分别为高、宽、通道,通道按R、G、B分开
    RGBQUAD pixel;
    for (int i = 0; i < input->height; i++)
    {
        for (int j = 0; j < input->width; j++)
        {
            FreeImage_GetPixelColor(bitmap, j, i, &pixel);
            input->data[i][j][0] = (float)pixel.rgbRed;
            input->data[i][j][1] = (float)pixel.rgbGreen;
            input->data[i][j][2] = (float)pixel.rgbBlue;
        }
    }
    // for (int i = 0; i < input->height; i++)
    // {
    //     for (int j = 0; j < input->width; j++)
    //     {
    //         printf("%f\t",input->data[i][j][0]);
    //     }
    // }
    FreeImage_Unload(bitmap);
}

// 写入图像
void write_image(char *filename, const float32* output)
{
    // 分配内存以储存图像数据
    FIBITMAP *bitmap = FreeImage_Allocate(output->width, output->height, output->channel * 8, 0, 0, 0);

    RGBQUAD color;
    color.rgbReserved = 255;
    for (int y = 0; y < output->height; y++) {
        for (int x = 0; x < output->width; x++) {
            color.rgbRed = (BYTE)(output->data[y][x][0]);
            color.rgbGreen = (BYTE)(output->data[y][x][1]);
            color.rgbBlue = (BYTE)(output->data[y][x][2]);
            FreeImage_SetPixelColor(bitmap, x, y, &color);
        }
    }

    // BYTE* bits = FreeImage_GetBits(bitmap);
    // int pitch = FreeImage_GetPitch(bitmap);
    // for (int i = 0; i < output->height; i++) {
    //     for (int j = 0; j < output->width; j++) {
    //         for (int k = 0; k < output->channel; k++) {
    //             bits[i * pitch + j * output->channel + k] = (BYTE) (output->data[i][j][k]);
    //         }
    //     }
    // }

    // 生成图像
    FreeImage_Save(FreeImage_GetFIFFromFilename(filename), bitmap, filename, 0);
    FreeImage_Unload(bitmap);
}

// padding操作
void padding(const float32* input, int paddingSize,float32* paddingImage)
{    
    // 初始化
    paddingImage->width = input->width + 2*paddingSize;
    paddingImage->height = input->height + 2*paddingSize;
    paddingImage->channel = input->channel;

    // 分配内存
    paddingImage->data = (float ***)malloc(paddingImage->height * sizeof(float **));
    for (int i = 0; i < paddingImage->height; i++)
    {
        paddingImage->data[i] = (float **)malloc(paddingImage->width * sizeof(float *));
        for (int j = 0; j < paddingImage->width; j++)
        {
            paddingImage->data[i][j] = (float *)malloc(paddingImage->channel * sizeof(float));
        }
    }

    for(int i = 0; i < paddingImage->height; i++){
        for(int j = 0; j < paddingImage->width; j++){
            for(int k = 0; k < paddingImage->channel; k++){
                paddingImage->data[i][j][k] = 0;
            }
        }
    }
    // 赋值
    for (int i = 0; i < input->height; i++)
    {
        for (int j = 0; j < input->width; j++)
        {
            paddingImage->data[i + paddingSize][j + paddingSize][0] = input->data[i][j][0];
            paddingImage->data[i + paddingSize][j + paddingSize][1] = input->data[i][j][1];
            paddingImage->data[i + paddingSize][j + paddingSize][2] = input->data[i][j][2];
        }
    }

    // // 上边界复制像素值
    // for (int i = 0; i < paddingSize; i++)
    // {
    //     for (int j = 0; j < input->width; j++)
    //     {
    //         paddingImage->data[i][j + paddingSize][0] = input->data[0][j][0];
    //         paddingImage->data[i][j + paddingSize][1] = input->data[0][j][1];
    //         paddingImage->data[i][j + paddingSize][2] = input->data[0][j][2];
    //     }
    // }
    // // 下边界复制像素值
    // for (int i = input->height + paddingSize; i < input->height + 2 * paddingSize; i++)
    // {
    //     for (int j = 0; j < input->width; j++)
    //     {
    //         paddingImage->data[i][j + paddingSize][0] = input->data[input->height - 1][j][0];
    //         paddingImage->data[i][j + paddingSize][1] = input->data[input->height - 1][j][1];
    //         paddingImage->data[i][j + paddingSize][2] = input->data[input->height - 1][j][2];
    //     }
    // }
    // // 左边界复制像素值
    // for (int i = 0; i < input->height; i++)
    // {
    //     for (int j = 0; j < paddingSize; j++)
    //     {
    //         paddingImage->data[i + paddingSize][j][0] = input->data[i][0][0];
    //         paddingImage->data[i + paddingSize][j][1] = input->data[i][0][1];
    //         paddingImage->data[i + paddingSize][j][2] = input->data[i][0][2];
    //     }
    // }
    // // 右边界复制像素值
    // for (int i = 0; i < input->height; i++)
    // {
    //     for (int j = input->width + paddingSize; j < input->width + 2 * paddingSize; j++)
    //     {
    //         paddingImage->data[i + paddingSize][j][0] = paddingImage->data[i][input->width - 1][0];
    //         paddingImage->data[i + paddingSize][j][1] = paddingImage->data[i][input->width - 1][1];
    //         paddingImage->data[i + paddingSize][j][2] = paddingImage->data[i][input->width - 1][2];
    //     }
    // }

    // // 复制四个角的像素值
    // // 左上角
    // for (int i = 0; i < paddingSize; i++) {
    //     for (int j = 0; j < paddingSize; j++) {
    //         paddingImage->data[i][j][0] = input->data[0][0][0];
    //         paddingImage->data[i][j][1] = input->data[0][0][1];
    //         paddingImage->data[i][j][2] = input->data[0][0][2];
    //     }
    // }
    // // 左下角
    // for (int i = input->height + paddingSize; i < input->height + 2 * paddingSize; i++) {
    //     for (int j = 0; j < paddingSize; j++) {
    //         paddingImage->data[i][j][0] = input->data[input->height - 1][0][0];
    //         paddingImage->data[i][j][1] = input->data[input->height - 1][0][1];
    //         paddingImage->data[i][j][2] = input->data[input->height - 1][0][2];
    //     }
    // }
    // // 右下角
    // for (int i = input->height + paddingSize; i < input->height + 2 * paddingSize; i++) {
    //     for (int j = input->width + paddingSize; j < input->width + 2 * paddingSize; j++) {
    //         paddingImage->data[i][j][0] = input->data[input->height - 1][input->width - 1][0];
    //         paddingImage->data[i][j][1] = input->data[input->height - 1][input->width - 1][1];
    //         paddingImage->data[i][j][2] = input->data[input->height - 1][input->width - 1][2];
    //     }
    // }
    // // 右上角
    // for (int i = 0; i < paddingSize; i++) {
    //     for (int j = input->width + paddingSize; j < input->width + 2 * paddingSize; j++) {
    //         paddingImage->data[i][j][0] = input->data[0][input->width - 1][0];
    //         paddingImage->data[i][j][1] = input->data[0][input->width - 1][1];
    //         paddingImage->data[i][j][2] = input->data[0][input->width - 1][2];
    //     }
    // }

}

// 卷积操作
void convolution(const float32* input, float32* output, const float32* kernel, int paddingSize) {
    int kernel_size = kernel->height;

    // padding操作
    float32* paddingImage = (float32*)malloc(sizeof(float32));
    padding(input,paddingSize,paddingImage);

    // // 分配内存
    // paddingImage.data = (float ***)malloc(paddingImage.height * sizeof(float **));
    // for (int i = 0; i < paddingImage.height; i++)
    // {
    //     paddingImage.data[i] = (float **)malloc(paddingImage.width * sizeof(float *));
    //     for (int j = 0; j < paddingImage.width; j++)
    //     {
    //         paddingImage.data[i][j] = (float *)malloc(paddingImage.channel * sizeof(float));
    //     }
    // }

    // 时间计算
    clock_t start, end;
    double cpu_time_used;
    
    // 进行卷积操作
    start = clock();
    float sum = 0.0f;

    for (int c = 0; c < output->channel; c++) {
        for (int i = paddingSize; i < input->height + paddingSize - kernel_size + 1; i++) {
            for (int j = paddingSize; j < input->width + paddingSize - kernel_size + 1; j++) {
                sum = 0.0f;
                for (int k = 0; k < kernel_size; k++) {
                    for (int l = 0; l < kernel_size; l++) {
                        sum += kernel->data[k][l][c] * paddingImage->data[i + k][j + l][c];
                    }
                }
                output->data[i - paddingSize][j - paddingSize][c] = sum;
            }
        }
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("程序运行时间为 %f 秒\n", cpu_time_used);

    // 释放内存
    for (int i = 0; i < input->height + 2 * paddingSize; i++) {
        for (int j = 0; j < input->width + 2 * paddingSize; j++) {
            free(paddingImage->data[i][j]);
        }
        free(paddingImage->data[i]);
    }
    free(paddingImage->data);
}

void convolution_avx2(const float32* input, float32* output, const float32* kernel, int paddingSize) {
    #ifdef WITH_AVX2
    int kernel_size = kernel->height;

    // padding操作
    float32* paddingImage = (float32*)malloc(sizeof(float32));
    padding(input,paddingSize,paddingImage);

    // // 分配内存
    // paddingImage.data = (float ***)malloc(paddingImage.height * sizeof(float **));
    // for (int i = 0; i < paddingImage.height; i++)
    // {
    //     paddingImage.data[i] = (float **)malloc(paddingImage.width * sizeof(float *));
    //     for (int j = 0; j < paddingImage.width; j++)
    //     {
    //         paddingImage.data[i][j] = (float *)malloc(paddingImage.channel * sizeof(float));
    //     }
    // }

    // 时间计算
    clock_t start, end;
    double cpu_time_used;
    
    // 进行卷积操作
    start = clock();
    float sum = 0.0f;
    #pragma omp parallel for
    for (int c = 0; c < output->channel; c++) {
        for (int i = paddingSize; i < input->height + paddingSize - kernel_size + 1; i++) {
            for (int j = paddingSize; j < input->width + paddingSize - kernel_size + 1; j++) {
                sum = 0.0f;
                for (int k = 0; k < kernel_size; k++) {
                    for (int l = 0; l < kernel_size; l++) {
                        sum += kernel->data[k][l][c] * paddingImage->data[i + k][j + l][c];
                    }
                }
                output->data[i - paddingSize][j - paddingSize][c] = sum;
            }
        }
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("avx2程序运行时间为 %f 秒\n", cpu_time_used);

    // 释放内存
    for (int i = 0; i < input->height + 2 * paddingSize; i++) {
        for (int j = 0; j < input->width + 2 * paddingSize; j++) {
            free(paddingImage->data[i][j]);
        }
        free(paddingImage->data[i]);
    }
    free(paddingImage->data);
    #else
    //return 0.0;
    #endif
}

// 卷积操作
void convolution_avx2_omp(const float32* input, float32* output, const float32* kernel, int paddingSize) {
    #ifdef WITH_AVX2
    int kernel_size = kernel->height;

    // padding操作
    float32* paddingImage = (float32*)malloc(sizeof(float32));
    padding(input,paddingSize,paddingImage);

    // // 分配内存
    // paddingImage.data = (float ***)malloc(paddingImage.height * sizeof(float **));
    // for (int i = 0; i < paddingImage.height; i++)
    // {
    //     paddingImage.data[i] = (float **)malloc(paddingImage.width * sizeof(float *));
    //     for (int j = 0; j < paddingImage.width; j++)
    //     {
    //         paddingImage.data[i][j] = (float *)malloc(paddingImage.channel * sizeof(float));
    //     }
    // }

    // 时间计算
    clock_t start, end;
    double cpu_time_used;
    
    // 进行卷积操作
    start = clock();
    float sum = 0.0f;
    #pragma omp parallel for
    for (int c = 0; c < output->channel; c++) {
        for (int i = paddingSize; i < input->height + paddingSize - kernel_size + 1; i++) {
            for (int j = paddingSize; j < input->width + paddingSize - kernel_size + 1; j++) {
                sum = 0.0f;
                for (int k = 0; k < kernel_size; k++) {
                    for (int l = 0; l < kernel_size; l++) {
                        sum += kernel->data[k][l][c] * paddingImage->data[i + k][j + l][c];
                    }
                }
                output->data[i - paddingSize][j - paddingSize][c] = sum;
            }
        }
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("omp程序运行时间为 %f 秒\n", cpu_time_used);

    // 释放内存
    for (int i = 0; i < input->height + 2 * paddingSize; i++) {
        for (int j = 0; j < input->width + 2 * paddingSize; j++) {
            free(paddingImage->data[i][j]);
        }
        free(paddingImage->data[i]);
    }
    free(paddingImage->data);
    #else
    //return 0.0;
    #endif
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "输入规范: %s 输入文件 输出文件\n", argv[0]);
        return 1;
    }

    //FreeImage_Initialise();

    float32* input = (float32*)malloc(sizeof(float32));
    // 读取图像并初始化input
    read_image(argv[1],input);

    // 初始化output
    float32* output = (float32*)malloc(sizeof(float32));
    output->height = input->height;
    output->width = input->width;
    output->channel = input->channel;
    // 分配内存
    output->data = (float ***)malloc(output->height * sizeof(float **));
    for (int i = 0; i < output->height; i++)
    {
        output->data[i] = (float **)malloc(output->width * sizeof(float *));
        for (int j = 0; j < output->width; j++)
        {
            output->data[i][j] = (float *)malloc(output->channel * sizeof(float));
        }
    }

    // 初始化kernel
    float32* kernel = (float32*)malloc(sizeof(float32));
    kernel->height = 3;
    kernel->width = 3;
    kernel->channel = 3;
    // 分配内存
    kernel->data = (float ***)malloc(kernel->height * sizeof(float **));
    for (int i = 0; i < kernel->height; i++)
    {
        kernel->data[i] = (float **)malloc(kernel->width * sizeof(float *));
        for (int j = 0; j < kernel->width; j++)
        {
            kernel->data[i][j] = (float *)malloc(kernel->channel * sizeof(float));
        }
    }
    for(int k = 0; k < kernel->channel; k++){
        kernel->data[0][0][k] = 2;
        kernel->data[0][1][k] = -1;
        kernel->data[0][2][k] = 2;
        // kernel->data[0][3][k] = 1;
        // kernel->data[0][4][k] = 1;

        kernel->data[1][0][k] = -1;
        kernel->data[1][1][k] = 5;
        kernel->data[1][2][k] = -1;
    //    kernel->data[1][3][k] = 1;
    //     kernel->data[1][4][k] = 1;
        
        kernel->data[2][0][k] = 2;
        kernel->data[2][1][k] = -1;
        kernel->data[2][2][k] = 2;
        // kernel->data[2][3][k] = 1;
        // kernel->data[2][4][k] = 1;

        // kernel->data[3][0][k] = 1;
        // kernel->data[3][1][k] = 1;
        // kernel->data[3][2][k] = 1;
        // kernel->data[3][3][k] = 1;
        // kernel->data[3][4][k] = 1;

        // kernel->data[4][0][k] = 1;
        // kernel->data[4][1][k] = 1;
        // kernel->data[4][2][k] = 1;
        // kernel->data[4][3][k] = 1;
        // kernel->data[4][4][k] = 1;

    }

    // 定义paddingSize
    int paddingSize = (kernel->height - 1) / 2;
    // 卷积操作
    convolution(input,output,kernel,paddingSize);
    //convolution_avx2(input,output,kernel,paddingSize);
    //convolution_avx2_omp(input,output,kernel,paddingSize);
    // 写入结果
    write_image(argv[2],output);

    // 释放内存
    for (int i = 0; i < input->height; i++) {
        for (int j = 0; j < input->width; j++) {
            free(input->data[i][j]);
            free(output->data[i][j]);
        }
        free(input->data[i]);
        free(output->data[i]);
    }
    free(input->data);
    free(output->data);

    for (int i = 0; i < kernel->height; i++) {
        for (int j = 0; j < kernel->width; j++) {
            free(kernel->data[i][j]);
        }
        free(kernel->data[i]);
    }
    free(kernel->data);
    free(input);
    free(output);
    free(kernel);

    //FreeImage_DeInitialise();

    return 0;
}
