package example;

class FreshJuice {
    enum FreshJuiceSize { SMALL, MEDIUM, LARGE }
    FreshJuiceSize size;
}

public class EnumExample
{
    public static void main(String[] arg) {
        FreshJuice juice = new FreshJuice();
        juice.size = FreshJuice.FreshJuiceSize.MEDIUM;

        System.out.println(juice.size); // MEDIUM
    }
}