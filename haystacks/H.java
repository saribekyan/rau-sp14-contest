import java.util.Scanner;


public class H
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; ++i) 
			a[i] = in.nextLong();
		long[] l = new long[n];
		for (int i = 0; i < n; ++i)
			l[i] = in.nextLong();
		in.close();			
		int i = 0;
		while (i < n)
		{
			long x = 0;
			int k = 0;
			int j = i; 
			while (k < n && x >= 0)
			{
				x += a[j] - l[j];												
				++k;
				j = (j + 1) % n;
			}
			if (k == n && x >= 0) {
				System.out.println(i + 1);
				return;				
			}						
			i += k;
		}		
		System.out.println(-1);				
	}
};