import java.util.Random;
import java.util.Scanner;

public class vectorf {
    public static void main(String[] args) {
        Random random = new Random(); // 创建一个随机数生成器
        
        System.out.print("请输入向量的长度：");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        float[] vec1 = new float[n];
        float[] vec2 = new float[n];
        for (int i = 0; i < n; i++) {
            vec1[i] = random.nextFloat();
            vec2[i] = random.nextFloat();
        }

        double result = 0.0;
        long startTime = System.nanoTime(); // 记录程序开始执行的时间

        for (int i = 0; i < n; i++){
            result += vec1[i] * vec2[i];
        }

        long endTime = System.nanoTime(); // 记录程序结束执行的时间
        long duration = endTime - startTime; // 计算程序运行时间，单位为纳秒
        sc.close();
        System.out.println("点乘结果为：" + result);
        System.out.println("程序运行时间为：" + duration + " ns");

    }
}