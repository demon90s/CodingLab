
import java.util.concurrent.ThreadLocalRandom;

public class ThreadLocalRandomExample {

    public static void main(String[] args)
    {
        ThreadLocalRandom tlr = ThreadLocalRandom.current();

        for (int i = 0; i < 10; ++i)
        {
            // [0, 100)
            System.out.println(tlr.nextInt(0, 100));
        }
    }

}