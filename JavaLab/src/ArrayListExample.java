import java.util.*;

// 测试遍历
public class ArrayListExample {
	public static void main(String[] args) {
		List<String> list = new ArrayList<String>();
		list.add("Hello");
		list.add("World");
		list.add("Java");

		// For-Each遍历
		for (String str : list) {
			System.out.println(str);
		}
		System.out.println("----------------");

		// 数组遍历 链表内容复制到数组
		String[] strArray = new String[list.size()];
		list.toArray(strArray);
		for (int i = 0; i < strArray.length; i++)
		{
			System.out.println(strArray[i]);
		}

		System.out.println("----------------");

		// 使用迭代器遍历
		Iterator<String> ite = list.iterator();
		while (ite.hasNext())
		{
			System.out.println(ite.next());
		}

		System.out.println("----------------");
	}
}