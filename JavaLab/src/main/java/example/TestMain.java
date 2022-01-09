
package example;
class Foo {

}

public class TestMain {
    public static void main(String[] args) {
        Foo a = new Foo();
        
        Foo b = a;
        Foo c = a;

        if (b == c) {
            System.out.println("b == c");
        }
        else
        {
            System.out.println("b != c");
        }
    }
}