public class TestEquals
{
	public static void main(String[] args)
	{
		Integer i = 42;
		if (i.equals(42))
		{
			System.out.println("PASS 1");
		}


		Foo foo = new Foo();
		Foo foo2 = foo;
		if (foo.euqals(foo2)) // 必须实现了equals方法
		{
			System.out.println("PASS 2");
		}
	}
}