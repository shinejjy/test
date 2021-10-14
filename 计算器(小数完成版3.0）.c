#include <stdio.h>
#include <math.h>

int main() 
{
	char ch;
	int sumnum=1;
	int sum=0;
	int c[1000],pos[1000],start[1000],end[1000],bucket[1000]={0},firstend; 
	char b[1000],d[1000];
	double decimal;
	int sump;
	int j,p,i,num_decimal,f=1,brackets=0,o,brackets_num;
	int flag;
	
    printf("你渴望力量吗，输入你想算的吧（那个那个如果不在最后输入等号的话，会有非常非常可怕的结果发生）\n");
    while(f==1)
  {
  	double a[1000]={0};
        i=1;
        flag=num_decimal=decimal=0;
	while(ch=getchar(),ch!='\n')
	{
	  if(ch=='(')
	  {
	  	brackets++;
	        d[brackets]=ch;
	        pos[brackets]=i;
	  }
	  else if (ch==')')
	  {
	  	brackets++;
	        d[brackets]=ch;
	        pos[brackets]=i+1;
	  }
	  else if(ch=='.')
	  {
	  	flag=1;
	  }
	  else if(ch<='9'&&ch>='0'&&flag==0) 
	    a[i]=a[i]*10+(ch-'0');
	  else if (ch<='9'&&ch>='0'&&flag==1)
	  {
	  	num_decimal++;
	  	decimal=decimal+(ch-'0')/pow(10,num_decimal);
	  }
          else
          {
            	flag=0;
        	a[i]=a[i]+decimal;
         	num_decimal=decimal=0;
        	i++;
        	b[i]=ch;
	        i++;
	  }
     } 
     
    p=1;
    sumnum=i-1; 
    j=i=1;
    //括号配对 
	for(o=1;o<=brackets;o++)
    {
    	if(d[o]=='(')
    	bucket[j++]=o;
    	else if(d[o]==')'&&bucket[j-1]!=0)
    	{
		    start[i]=pos[bucket[j-1]];
    		end[i]=pos[o];
    		bucket[j-1]=0;
    		i++;
    	    j--; 
		}
	}
	brackets_num=i;
	//括号配对 
	end[i]=sumnum;
	start[i]=1;
  for(o=1;o<=brackets_num;o++)
  {
  	firstend=end[o];
	for(j=start[o];j<end[o];j++)
	{
		if(b[j]=='*'||b[j]=='/')
		{
			c[p]=j;
			p=p+1;
		}	
	}
	sump=p-1;
	p=1;
	while(p<=sump)
	{
		if (b[c[p]]=='*') 
		a[c[p]-1]=a[c[p]-1]*a[c[p]+1];
		else 
		a[c[p]-1]=a[c[p]-1]/a[c[p]+1];
		for(i=c[p];i<end[o]-2;i++)
		{
			a[i]=a[i+2];
			b[i]=b[i+2];
		}
		for(i=p+1;i<=sump;i++)
		{
		  c[i]=c[i]-2;
    	}
		end[o]=end[o]-2;
		p++;
	}
	
	
	p=1;
	for(j=start[o];j<end[o];j++)
	{
		if(b[j]=='+'||b[j]=='-')
		{
			c[p]=j;
			p=p+1;
		}	
	}
	sump=p-1;
	p=1;
	while(p<=sump)
	{   
		if (b[c[p]]=='+') 
	    {	a[c[p]-1]=a[c[p]-1]+a[c[p]+1];
	    printf("%d\n",a[c[p]-1]);
	}
		else 
		a[c[p]-1]=a[c[p]-1]-a[c[p]+1];
		for(i=c[p];i<end[o]-2;i++)
		{
			a[i]=a[i+2];
			b[i]=b[i+2];
		}
		for(i=p+1;i<=sump;i++)
		{
		  c[i]=c[i]-2;
    	}
		end[o]=end[o]-2;
		p++;
	}
  	for(i=start[o]+1;i<=end[brackets_num];i++)
    {
       a[i]=a[i+firstend-start[o]-1];
       b[i]=b[i+firstend-start[o]-1];
	}
	for(i=o+1;i<=brackets_num;i++)
	  end[i]=end[i]-(firstend-start[o]-1);
  }
	if(b[2]=='=')
	printf("what you want:%lf\n",a[1]);
	else
	printf("可恶，你竟然不加等号，你..你你完了！！please put '='\n");
  }  
	return 0;
}






















