#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// 对齐整数函数
char *orderInt(int width, char c[]) {
    int len = strlen(c);
    char *buffer = (char *) malloc((width + 1) * sizeof(char));
    int i, j;

    // 将buffer数组初始化为'0'
    for (i = 0; i < width; i++) {
        buffer[i] = '0';
    }
    buffer[width] = '\0';// 添加字符串结尾符

    // 将字符串c插入到buffer数组的右端
    i = width - 1;
    j = len - 1;
    while (j >= 0 && i >= 0) {
        buffer[i] = c[j];
        j--;
        i--;
    }
    return buffer;
}

// 对齐小数函数
char *orderDeci(int width, char c[]) {
    int len = strlen(c);
    char *buffer = (char *) malloc((width + 1) * sizeof(char));
    int i, j;

    // 将buffer数组初始化为'0'
    for (i = 0; i < width; i++) {
        buffer[i] = '0';
    }
    buffer[width] = '\0';// 添加字符串结尾符

    // 将字符串c插入到buffer数组的左端
    i = 0;
    j = 0;
    while (i < width && j < len) {
        buffer[i] = c[j];
        i++;
        j++;
    }
    return buffer;
}

// 打印数组
void printArray(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]);
        i++;
    }
}

// 在数组前面插入一个字符
char *insertAns(char num, char c[]) {
    char *buffer = (char *) malloc((strlen(c) + 2) * sizeof(char));

    // 将buffer第0位设为num，其余与c一一对应
    buffer[0] = num;
    for (int i = 1; i < strlen(buffer); i++) {
        buffer[i] = c[i - 1];
    }
    buffer[strlen(c) + 1] = '\0';  // 添加字符串结尾符
    return buffer;
}

// 比较最大值函数
char *maxChar(char *a, char *b) {
    // 先比较位数
    if (strlen(a) > strlen(b)) {
        return a;
    } else if (strlen(a) < strlen(b)) {
        return b;
    } else { // 如果二者位数相等
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] > b[i]) {
                return a;
            } else if (a[i] < b[i]) {
                return b;
            }
        }
        return a;
    }
}

int maxInt(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

// 加法函数
char *addition(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = maxInt(len1, len2);
    char *result = (char *) malloc((len + 2) * sizeof(char)); // 分配足够的内存

    int carry = 0;
    int i, j, k;

    for (i = len1 - 1, j = len2 - 1, k = len - 1; i >= 0 || j >= 0; i--, j--, k--) {
        int num1 = (i >= 0) ? s1[i] - '0' : 0;
        int num2 = (j >= 0) ? s2[j] - '0' : 0;
        int sum = num1 + num2 + carry;
        result[i] = sum % 10 + '0';
        carry = sum / 10;
    }
    if (carry > 0) { // 如果最高位有进位，则需要在结果的最前面再加上进位的数字
        char *carryStr = (char *) malloc((len + 2) * sizeof(char));
        carryStr[0] = carry + '0';
        carryStr[1] = '\0';
        strcat(carryStr, result); // 将carryStr字符串连接到result字符串的前面
        result = carryStr; // 将carryStr的地址赋值给result
        len++; // 字符串长度加1
    }
    result[len] = '\0'; // 添加字符串结尾符
    return result;
}

// // 减法函数
// char *subtract(char *s1, char *s2) {
//     int len1 = strlen(str1);
//     int len2 = strlen(str2);
//     int len = maxInt(len1, len2);
//     char *result = (char *) malloc((len) * sizeof(char)); // allocate memory
//     int carry = 0;
//     int i, j, k;
//     char *s1 = maxChar(str1, str2);
//     char *s2 = maxChar(str1, str2) == str1 ? str2 : str1;

//     for (i = len1 - 1, j = len2 - 1, k = len - 1; i >= 0 || j >= 0; i--, j--, k--) {
//         int num1 = (i >= 0) ? s1[i] - '0' : 0;
//         int num2 = (j >= 0) ? s2[j] - '0' : 0;
//         int sum = num1 - num2 - carry;
//         if (sum < 0) {
//             sum = -sum;
//             carry = 1;
//         }else{
//             carry = 0;
//         }
//         result[i] = sum + '0';
//     }
//     if (carry > 0) { // 如果最高位有进位，则需要在结果的最前面再加上进位的数字
//         char *carry_str = (char *) malloc((len + 2) * sizeof(char));
//         carry_str[0] = carry + '0';
//         carry_str[1] = '\0';
//         strcat(carry_str, result); // 将carry_str字符串连接到result字符串的前面
//         result = carry_str; // 将carry_str的地址赋值给result
//         len++; // 字符串长度加1
//     }
//     result[len] = '\0'; // 添加字符串结尾符
//     while (*result == '0' && *(result + 1) != '\0') {
//         result++;
//     }
//     return result;
// }

// 乘法函数
char *multiply(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 + len2;
    char *result = (char *) malloc(sizeof(char) * (len + 1));
    result[len] = '\0';
    int i, j, k;
    // 初始化result
    for (i = 0; i < len; i++) {
        result[i] = '0';
    }
    // 逐位相乘
    for (i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        for (j = len2 - 1; j >= 0; j--) {
            int temp = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = temp % 10 + '0';
            carry = temp / 10;
        }
        result[i] += carry;
    }
    // 去掉前导0
    while (*result == '0' && *(result + 1) != '\0') {
        result++;
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Arguments number illegal! Please check the number of your argument!\n");
        return -1;
    }
    if (*argv[2] != '+' && *argv[2] != '-' && *argv[2] != 'x' && *argv[2] != '/') {
        printf("illegal operator!\n");
        return -1;
    }
    int i = 0;
    while (argv[1][i] != '\0') {
        if (argv[1][i] > '9' || argv[1][i] < 0) {
            printf("The input cannot be interpret as numbers!\n");
            return -1;
        }
        i++;
    }
    i = 0;
    while (argv[3][i] != '\0') {
        if (argv[1][i] > '9' || argv[1][i] < 0) {
            printf("The input cannot be interpret as numbers!\n");
            return -1;
        }
        i++;
    }
    if (*argv[2] == '/' && argv[3][0] == '0') {
        printf("Cannot divided by zero.\n");
        return -1;
    }


    // 传入参数
    char *num11 = argv[1];
    char op = *argv[2];
    char *num22 = argv[3];
    // 声明num1，num2数组
    char num1[strlen(num11)];
    char num2[strlen(num22)];
    strcpy(num1, num11);
    strcpy(num2, num22);

    char *token1, *token2; // 分割字符串
    char *int1, *int2; // 数字的整数部分
    char *deci1, *deci2; // 数字的小数部分
    char *resultInt; // 整数部分计算结果
    char *resultDeci; // 小数部分计算结果
    char *result = "0"; // 最终输出结果

    // 对第一个数字的处理
    token1 = strtok(num1, ".");
    if (token1 == NULL) {
        int1 = num1;
        deci1 = NULL;
    } else {
        int1 = token1;
        token1 = strtok(NULL, ".");
        deci1 = token1;
    }
    // 第二个数字同理
    token2 = strtok(num2, ".");
    if (token2 == NULL) {
        int2 = num2;
        deci2 = NULL;
    } else {
        int2 = token2;
        token2 = strtok(NULL, ".");
        deci2 = token2;
    }

    // 对齐整数
    if (strlen(int1) >= strlen(int2)) {
        int2 = orderInt(strlen(int1), int2);
    } else {
        int1 = orderInt(strlen(int2), int1);
    }
    // 对齐小数
    if (deci1 != NULL && deci2 != NULL) { // 防止报错
        if (strlen(deci1) >= strlen(deci2)) {
            deci2 = orderDeci(strlen(deci1), deci2);
        } else {
            deci1 = orderDeci(strlen(deci2), deci1);
        }
    }

    /*
    * 加法按字符串位置逐个计算，先计算小数，
    * 得出整数部分后，再进行整数部分的运算
    */
    if (op == '+') {

        if (deci1 != NULL && deci2 != NULL) {
            char carry[1] = {'0'}; // 小数进位部分
            resultDeci = addition(deci1, deci2); // 小数部分求和计算
            // 若有进位，则将进位部分取出,并且加上小数点
            if (strlen(resultDeci) > strlen(deci1)) {
                int1 = addition(int1, "1");
                resultDeci++;
            } 

            // 计算整数部分
            resultInt = addition(int1, int2);

            // 拼接整数和小数的字符串，输出最终结果
            result = strcat(resultInt, ".");
            result = strcat(result, resultDeci);
        } else if (deci1 == NULL && deci2 != NULL) {
            deci1 = "0";
            resultInt = addition(int1, int2);
            resultDeci = insertAns('.', deci2);
            result = strcat(resultInt, resultDeci);
        } else if (deci2 == NULL && deci1 != NULL) {
            deci2 = "0";
            resultInt = addition(int1, int2);
            resultDeci = insertAns('.', deci1);
            result = strcat(resultInt, resultDeci);
        } else {
            resultInt = addition(int1, int2);
            result = resultInt;
        }
        // 输出结果
        printArray(num11);
        printf(" %c ", op);
        printArray(num22);
        printf(" = ");
        printArray(result);
        printf("\n");

    }
        // 减法同理
    else if (op == '-') {
        // 先对小数进行减法，若有负号，则往整数部分借一位
        char *tmp1 = (char*) malloc(sizeof(char) * strlen(deci1));
        char *tmp2 = (char*) malloc(sizeof(char) * strlen(int1));
        strcpy(tmp1,deci1);
        deci1 = maxChar(num11,num22)==num11? deci1:deci2;
        deci2 = maxChar(num11,num22)==num11? deci2:tmp1;
        strcpy(tmp2,int1);
        int1 = maxChar(num11,num22)==num11? int1:int2;
        int2 = maxChar(num11,num22)==num11? int2:tmp2;

        if (deci1 != NULL && deci2 != NULL) {
            char carry[1] = {'0'}; // 小数进位部分
            resultDeci = subtract(deci1, deci2); // 小数部分求和计算
            // 若有借位，则将进位部分取出,并且加上小数点
            if (deci1 != maxChar(deci1,deci2)) {
                int1 = subtract(int1, "1");
//                resultDeci++;
            } else {
//                resultDeci = insert_ans('.', resultDeci); // 将小数点插入第0个位置
            }

            // 计算整数部分
            resultInt = subtract(int1, int2);
//            resultInt = addition(carry, resultInt);

            // 拼接整数和小数的字符串，输出最终结果
            if (maxChar(num11,num22)!=num11){
                result--;
                result[0] = '-';
            }
            result = strcat(resultInt, ".");
            result = strcat(result, resultDeci);
        } else if (deci1 == NULL && deci2 != NULL) {
            deci1 = "0";
            resultInt = subtract(int1, int2);
            resultDeci = insert_ans('.', deci2);
            if (maxChar(num11,num22)!=num11){
                result--;
                result[0] = '-';
            }
            result = strcat(resultInt, resultDeci);
        } else if (deci2 == NULL && deci1 != NULL) {
            deci2 = "0";
            resultInt = subtract(int1, int2);
            resultDeci = insert_ans('.', deci1);
            if (maxChar(num11,num22)!=num11){
                result--;
                result[0] = '-';
            }
            result = strcat(resultInt, resultDeci);
        } else {
            resultInt = subtract(int1, int2);
            if (maxChar(num11,num22)!=num11){
                result--;
                result[0] = '-';
            }
            result = resultInt;
        }
    }

    // 乘法方法
    else if (op == 'x') {
        bool bl = false;// 判断小数还是整数
        for (int i = 0; i < strlen(num11); i++) {
            if (num11[i] == '.' || num22[i] == '.') {
                bl = true;
            }
        }

        if (bl == true) {
            double a = atof(num11);
            double b = atof(num22);
            double result1 = a * b;
            printArray(num11);
            printf(" %c ", op);
            printArray(num22);
            printf(" = ");
            printf("%.10g", result1);
            printf("\n");
        } else{
            long long int a = atoll(num11);
            long long int b = atoll(num22);
            long long int result1 = a * b;
            printArray(num11);
            printf(" %c ", op);
            printArray(num22);
            printf(" = ");
            printf("%lld", result1);
            printf("\n");
        }

    }

    // 除法(同乘法）
    else if (op == '/') {       
        double a = atof(num11);
        double b = atof(num22);
        double result1 = a / b;  
        printArray(num11);
        printf(" %c ", op);
        printArray(num22);
        printf(" = ");
        printf("%.10g", result1);
        printf("\n");
    }



//    char* s1 = "123";
//    char* s2 = "456";
//    printf("%s", subtract(s1,s2));

}