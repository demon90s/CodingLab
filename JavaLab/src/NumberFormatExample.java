
import java.text.NumberFormat;

public class NumberFormatExample {
    public static void main(String[] args)
    {
        NumberFormat nf = NumberFormat.getInstance();
        System.out.println(nf.getClass().getName());
        System.out.println(nf.format(123456));
    }
}