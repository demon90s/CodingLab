package example;

import java.util.*;

public class HashMapExample {

	static void testHashMapCreate() {
		Map<String, String> map = new HashMap<String, String>();
		map.put("1", "value1");
		map.put("2", "value2");
		map.put("3", "value3");

		System.out.println(map);
	}

	static void testHashMapTravel() {
		Map<String, String> map = new HashMap<String, String>();
		map.put("1", "value1");
		map.put("2", "value2");
		map.put("3", "value3");

		// 第一种：普遍使用 二次取值
		System.out.println("通过Map.keySet遍历key和value:");
		for (String key : map.keySet()) {
			String v = map.get(key);
			System.out.println("key=" + key + " and value=" + v);
		}

		System.out.println("----------------");

		// 遍历所有的值
		for (String value : map.values()) {
			System.out.println(value);
		}
	}

	static void testHashMapGet() {
		Map<String, String> map = new HashMap<String, String>();
		map.put("1", "value1");
		map.put("2", "value2");
		map.put("3", "value3");

		System.out.println(map.get("2"));	// "value2"
	}

	// 删除元素
	static void testHashMapRemove() {
		Map<String, String> map = new HashMap<String, String>();
		map.put("1", "value1");
		map.put("2", "value2");
		map.put("3", "value3");

		String remove_key = "2";
		map.remove(remove_key);

		System.out.println(map);
	}

	public static void main(String[] args) {
		//testHashMapCreate();
		testHashMapTravel();
		//testHashMapGet();
		//testHashMapRemove();
	}
}