import java.util.*;

public class HashMapExample {
	public static void main(String[] args) {
		Map<String, String> map = new HashMap<String, String>();
		map.put("1", "value1");
		map.put("2", "value2");
		map.put("3", "value3");

		// 第一种：普遍使用 二次取值
		System.out.println("通过Map.keySet遍历key和value:");
		for (String key : map.keySet()) {
			String v = map.get(key);
			System.out.println("key=" + key + " add value=" + v);
		}
	}
}