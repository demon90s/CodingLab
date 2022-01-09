package example;
import java.util.LinkedList;

public class LinkedListExample {

    static void testLinkedListCreate() {
        LinkedList<String> sites = new LinkedList<String>();
     
        sites.add("Google");
        sites.add("Bing");
        sites.add("163");
        sites.add("Weibo");

        System.out.println(sites);

        // 从开头添加元素
        sites.addFirst("Wiki");
        System.out.println(sites);

        // 向末尾添加元素
        sites.addLast("Taobao");
        System.out.println(sites);

        // 从开头移除元素 结尾移除就是 removeLast
        sites.removeFirst();
        System.out.println(sites);
    }

    static void testLinkedListTravel() {
        LinkedList<String> sites = new LinkedList<String>();
     
        sites.add("Google");
        sites.add("Bing");
        sites.add("163");
        sites.add("Weibo");

        for (String s : sites) {
            System.out.println(s);
        }
    }

    public static void main(String[] args) {
        //testLinkedListCreate();
        testLinkedListTravel();
    }
}