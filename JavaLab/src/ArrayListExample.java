import java.util.*;

// 排序 自定义 实现接口 Comparable
class Hero implements Comparable<Object> {
	private String name;
	private int capability;

	Hero(String name, int capability) {
		this.name = name;
		this.capability = capability;
	}

	String getName() {
		return name;
	}

	int getCapability() {
		return capability;
	}

	@Override
	public String toString() {
		return new String("[" + name + "," + capability + "]");
	}

	@Override
	public int compareTo(Object rhs) {
		Hero rhs_hero = (Hero)rhs;
		
		// 如果this大于rhs，返回1，如果相等返回0,如果小于返回-1
		if (capability != rhs_hero.capability) {
			if (capability > rhs_hero.capability) {
				return -1;
			}
			else {
				return 1;
			}
		}
		else {
			return name.compareTo(rhs_hero.name);
		}
	}
}

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

		try {
			System.out.println(sites.get(100));	// 抛出异常
		} catch (IndexOutOfBoundsException e) {
			e.printStackTrace();
		}
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

	
	static void testCollectionsSort2() {
		List<Hero> hero_list = new ArrayList<Hero>();

		hero_list.add(new Hero("刘备", 80));
		hero_list.add(new Hero("关羽", 99));

		Collections.sort(hero_list);

		System.out.println(hero_list);
	}

	static void testCollectionsSort3() {
		List<Hero> hero_list = new ArrayList<Hero>();

		hero_list.add(new Hero("刘备", 80));
		hero_list.add(new Hero("关羽", 99));

		// 左边 优先级低返回1 优先级高返回-1
		Comparator<Hero> cmp = (Hero lhs, Hero rhs)->{
			if (lhs.getCapability() < rhs.getCapability()) {
				return 1;
			}
			else if (lhs.getCapability() > rhs.getCapability()) {
				return -1;
			}
			else {
				return lhs.getName().compareTo(rhs.getName());
			}
		};

		Collections.sort(hero_list, cmp);

		System.out.println(hero_list);
	}

	public static void main(String[] args) {
		//testArrayListTravel();
		//testArrayListAdd();
		//testArrayListGet();
		//testArrayListSet();
		//testArrayListRemove();
		//testCollectionsSort();
		//testCollectionsSort2();
		testCollectionsSort3();
	}
}