import java.util.HashMap;



public class TestMain {

    static void testVar()
    {
        var map = new HashMap<Integer, String>();
        map.put(1, "one");

        System.out.println(map);
    }

    public static void main(String[] args) {
        testVar();
    }
}