import java.io.*;
public class Main {
	
	public static void main(String args[]) throws IOException
	{
		int T;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		T=Integer.parseInt(br.readLine());
		long a[]=new long[10000];
		long b[]=new long[10000];
		long max1[]=new long[10000];
		long min1[]=new long[10000];
		long max2[]=new long[10000];
		long min2[]=new long[10000];
		while(T-->0)
		{
			int n=Integer.parseInt(br.readLine());
			String arr[]=br.readLine().split(" " );
			int i=0;
			for(String s:arr)
			{
				a[i]=Integer.parseInt(arr[i]);
				b[i]=-a[i];
				i++;
			}
			
			long maxsofar=a[0],maxendinghere=a[0];max1[0]=a[0];
			for(i=1;i<n;i++)
			{
					//maxendinghere=maxendinghere+a[i]>0?maxendinghere+a[i]:0;
					maxendinghere=maxendinghere+a[i];
					maxendinghere=maxendinghere>a[i]?maxendinghere:a[i];
					maxsofar=maxsofar>maxendinghere?maxsofar:maxendinghere;
					max1[i]=maxsofar;
			}
		
			max2[n-1]=maxendinghere=maxsofar=a[n-1];
			for(i=n-2;i>=0;i--)
			{
					//maxendinghere=maxendinghere+a[i]>0?maxendinghere+a[i]:0;
					maxendinghere=maxendinghere+a[i];
					maxendinghere=maxendinghere>a[i]?maxendinghere:a[i];
					maxsofar=maxsofar>maxendinghere?maxsofar:maxendinghere;
					max2[i]=maxsofar;
				
			}
			maxendinghere=maxsofar=b[0];
			min1[0]=-b[0];
			
			for(i=1;i<n;i++)
			{
					//maxendinghere=maxendinghere+b[i]>0?maxendinghere+b[i]:0;
					maxendinghere=maxendinghere+b[i];
					maxendinghere=maxendinghere>b[i]?maxendinghere:b[i];
					maxsofar=maxsofar>maxendinghere?maxsofar:maxendinghere;
					min1[i]=-maxsofar;
			}


		/*	for(i=0;i<n;i++)
				System.out.print(min1[i]+" ");
				System.out.println();
		*/
			maxendinghere=maxsofar=b[n-1];
			min2[n-1]=-b[n-1];
			
			for(i=n-2;i>=0;i--)
			{
					//maxendinghere=maxendinghere+b[i]>0?maxendinghere+b[i]:0;
					maxendinghere=maxendinghere+b[i];
					maxendinghere=maxendinghere>b[i]?maxendinghere:b[i];
					maxsofar=maxsofar>maxendinghere?maxsofar:maxendinghere;
					min2[i]=-maxsofar;
			}

		/*	for(i=0;i<n;i++)
				System.out.print(min2[i]+" ");
				System.out.println();
		*/	
			long globalmax=0;
			
		/*	for(i=0;i<n;i++)
			{
				System.out.println(a[i]+" "+b[i]+" "+min1[i]+" "+max1[i]+" "+min2[i]+" "+max2[i]);
			}
		*/	
			for(i=1;i<n;i++)
			{
				long m1=max1[i-1]-min2[i];
				m1=Math.abs(m1);
				long m2=max2[i]-min1[i-1];
				m2=Math.abs(m2);
				m1=m1>m2?m1:m2;
				globalmax=globalmax>m1?globalmax:m1;
			}
			System.out.println(globalmax);
		}
		
	}

}