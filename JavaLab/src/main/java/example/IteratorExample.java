package example;

import java.util.Iterator;
import java.util.ArrayList;

public class IteratorExample {

    static void testIterator1() {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(1);
        arr.add(2);

        // 获取迭代器
        Iterator<Integer> it = arr.iterator();

        // 输出第一个元素
        Integer first_element = it.next();
        System.out.println(first_element);

        System.out.println("--------------------");

        // 循环遍历
        it = arr.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }

    static void testIteratorRemove() {
        ArrayList<Integer> arr = new ArrayList<Integer>();

        arr.add(1);
        arr.add(10);
        arr.add(2);
        arr.add(20);

        Iterator<Integer> it = arr.iterator();
        while (it.hasNext()) {
            Integer i = it.next();
            if (i >= 10) {
                it.remove();
            }
        }

        System.out.println(arr);
    }

    public static void main(String[] args) {
        //testIterator1();
        testIteratorRemove();

    }
}