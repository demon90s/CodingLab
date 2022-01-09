package example;

import java.util.*;

public class GenericExample {

    // 泛型方法
    public static <E> void printArray(E[] inputArray)
    {
        // 输出数组元素
        for (E element : inputArray) {
            System.out.printf("%s ", element);
        }
        System.out.println();
    }

    static void testGenericFunction() {
        // 创建不同类型的数组 Integer Double 和 Character
        Integer[] intArray = {1, 2, 3};
        Double[] doubleArray = {1.1, 2.2, 3.3};
        Character[] charArray = {'H', 'E', 'L', 'L', 'O'};

        System.out.println("整型数组元素为：");
        printArray(intArray); // 传递一个整型数组

        System.out.println("双精度数组为：");
        printArray(doubleArray);

        System.out.println("字符型数组为：");
        printArray(charArray);
    }
    
    // 有界的类型参数
    // 比较三个值并返回最大值
    public static <T extends Comparable<T>> T maximum(T x, T y, T z) {
        T max = x;
        if (y.compareTo(max) > 0) {
            max = y;
        }
        if (z.compareTo(max) > 0) {
            max = z;
        }
        return max;
    }

    static void testGenericFunction2() {
        System.out.printf("%d %d %d 中最大数为: %d\n", 3, 4, 5, maximum(3, 4, 5));

        System.out.printf("%s %s %s 中最大的值是: %s\n", "ABC", "BCD", "DEF", maximum("ABC", "BCD", "DEF"));
    }

    public static void main(String[] args) {
        //testGenericFunction();
        testGenericFunction2();
    }
}