
class Box<T> {
    private T t;

    public void add(T t) {
        this.t = t;
    }

    public T get() {
        return t;
    }
}

public class GenericClassExample {

    public static void main(String[] args) {
        Box<String> intBox = new Box<String>();
        intBox.add(new String("Haha"));

        System.out.println(intBox.get());
    }
}