import java.util.HashSet;

public class HashSetExample {

    static void testHashSetCreate() {
        HashSet<String> sites = new HashSet<String>();

        sites.add("Taobao");
        sites.add("Weibo");
        sites.add("Taobao");        // 重复的元素不会被添加

        System.out.println(sites);

        // 判断元素是否存在
        System.out.println(sites.contains("Taobao")); // true
    }

    static void testHashSetRemove() {
        HashSet<String> sites = new HashSet<String>();

        sites.add("Taobao");
        sites.add("Weibo");

        sites.remove("Taobao");

        System.out.println(sites);

        // 删除所有
        sites.clear();
        System.out.println(sites);
    }

    // 迭代
    static void testHashSetTravel() {
        HashSet<String> sites = new HashSet<String>();

        sites.add("Taobao");
        sites.add("Weibo");

        for (String s : sites) {
            System.out.println(s);
        }
    }

    public static void main(String[] args) {
        //testHashSetCreate();
        //testHashSetRemove();
        testHashSetTravel();
    }
}