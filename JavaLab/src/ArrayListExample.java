import java.util.*;

// 测试遍历
public class ArrayListExample {

	// 遍历元素
	static void testArrayListTravel() {

		System.out.println("testArrayListTravel");

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

		// 使用for循环遍历
		for (int i = 0; i < list.size(); ++i)
		{
			System.out.println(list.get(i));
		}

		System.out.println("----------------");
	}

	// 添加元素
	static void testArrayListAdd() {
		ArrayList<String> sites = new ArrayList<String>();
		sites.add("Google");
		sites.add("Runnoob");
		sites.add("Taobao");
		sites.add("Weibo");
		System.out.println(sites);
	}

	// 访问元素 下标从0开始
	static void testArrayListGet() {
		ArrayList<String> sites = new ArrayList<String>();
		sites.add("Google");
		sites.add("Runnoob");
		sites.add("Taobao");
		sites.add("Weibo");
		System.out.println(sites.get(1));			// Runnoob
	}

	// 修改元素
	static void testArrayListSet() {
		ArrayList<String> sites = new ArrayList<String>();
		sites.add("Google");
		sites.add("Runnoob");
		sites.add("Taobao");
		sites.add("Weibo");

		System.out.println(sites.get(2));		// Taobao
		sites.set(2, "Wiki");
		System.out.println(sites.get(2));		// Wiki
	}

	// 删除元素
	static void testArrayListRemove() {
		ArrayList<String> sites = new ArrayList<String>();
		sites.add("Google");
		sites.add("Runnoob");
		sites.add("Taobao");
		sites.add("Weibo");

		sites.remove(3);
		System.out.println(sites);
	}

	// 排序 需要 import java.util.Collections
	static void testCollectionsSort() {
		ArrayList<Integer>sites = new ArrayList<Integer>();
		sites.add(66);
		sites.add(111);
		sites.add(2);
		sites.add(898);

		Collections.sort(sites);
		System.out.println(sites);
	}

	public static void main(String[] args) {
		//testArrayListTravel();
		//testArrayListAdd();
		//testArrayListGet();
		//testArrayListSet();
		//testArrayListRemove();
		testCollectionsSort();
	}
}