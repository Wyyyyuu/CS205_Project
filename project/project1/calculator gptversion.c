#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [expression]\n", argv[0]);
        return 1;
    }

    // 将参数字符串转换为标准格式，例如 "1+2" 转换为 "1 + 2"
    char *expression = argv[1];
    size_t len = strlen(expression);
    char *formatted = (char *) malloc((len * 2 + 1) * sizeof(char));
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            formatted[j++] = ' ';
            formatted[j++] = expression[i];
            formatted[j++] = ' ';
        } else {
            formatted[j++] = expression[i];
        }
    }
    formatted[j] = '\0';

    // 解析表达式并计算结果
    double result = 0;
    char op = '+';
    char *token = strtok(formatted, " ");
    while (token != NULL) {
        if (sscanf(token, "%lf", &result) != 1) {
            printf("Error: Invalid number '%s'\n", token);
            free(formatted);
            return 1;
        }
        switch (op) {
            case '+':
                result = result;
                break;
            case '-':
                result = -result;
                break;
            case '*':
                result = result * atof(strtok(NULL, " "));
                token = strtok(NULL, " ");
                continue;
            case '/':
                double divisor = atof(strtok(NULL, " "));
                if (divisor == 0) {
                    printf("Error: Division by zero\n");
                    free(formatted);
                    return 1;
                }
                result = result / divisor;
                token = strtok(NULL, " ");
                continue;
            default:
                printf("Error: Invalid operator '%c'\n", op);
                free(formatted);
                return 1;
        }
        op = token[0];
        token = strtok(NULL, " ");
    }

    printf("%.2f\n", result);
    free(formatted);
    return 0;
}