package example;

public class ArrayExample {
    public static void main(String[] args) {

        // {
        //     String[] str_list = new String[4];
        //     System.out.println(str_list.getClass());
        // }
        

        // {
        //     String[] str_list = {"刘备", "关羽", "张飞"};
        //     for (int i = 0; i < str_list.length; i++)
        //     {
        //         System.out.println(str_list[i]);
        //     }
        // }

        {
            String[] str_list = {"刘备", "关羽", "张飞"};
            for (String str : str_list)
            {
                System.out.println(str);
            }
        }
    }

}