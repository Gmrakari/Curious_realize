public static String myReverse(String s)
{
	//define a new string
	String result = "";

	//change String change into String array
	char[] chs = line.toCharArray();

	//from back to up search and print String ,get per char
	for(int x = chs.length - 1;x>=0;x--)
	{
		result += chs[x];
	}
	return result;
}

import java.util.*;
class Demo
{
	private static Scanner sc;

	public static void main(String[] args) 
	{
		sc = new Scanner(System.in);
		System.out.println("please input a string :");
		String line = sc.nextLine();
		String s = my Reverse(line);
		System.out.println(s);
	}
}

