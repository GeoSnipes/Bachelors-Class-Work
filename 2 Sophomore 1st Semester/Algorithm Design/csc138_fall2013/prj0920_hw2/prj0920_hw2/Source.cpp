#include <iostream>
using namespace std;
/*
Input- none
Output- Number for each individual letter that will let send+more=money
*/

void main ()
{
	//Variables
	int s, e, n, d, m, o, r, y;

	//Instructions
	for (s=0; s<=9;s++)
	{
		for (e=0; e<=9;e++)
		{
			for (n=0; n<=9;n++)
			{
				for (d=0; d<=9;d++)
				{
					for (m=0; m<=9;m++)
					{
						for (o=0; o<=9;o++)
						{
							for (r=0; r<=9;r++)
							{
								for (y=0; y<=9;y++)
								{
									if ((s!=e)&&(s!=n)&&(s!=d)&&(s!=m)&&(s!=o)&&(s!=r)&&(s!=y)&&(e!=n)&&(e!=d)&&(e!=m)&&(e!=o)&&(e!=r)&&(e!=y)&&(n!=d)&&(n!=m)&&(n!=o)&&(n!=r)&&(e!=y)&&(d!=m)&&(d!=o)&&(d!=r)&&(d!=y)&&(m!=o)&&(m!=r)&&(m!=y)&&(o!=r)&&(o!=y)&&(r!=y))
									{
										if((s*1000+e*100+n*10+d)+(m*1000+o*100+r*10+e)==(m*10000+o*1000+n*100+e*10+y))
										{
											cout<<"Send="<<(s*1000+e*100+n*10+d)<<endl<<"More="<<(m*1000+o*100+r*10+e)<<endl<<"Money="<<(m*10000+o*1000+n*100+e*10+y)<<endl;
											cout<<"Send+More=Money when s="<<s<<", e="<<e<<", n="<<n<<", d="<<d<<", m="<<m<<", o="<<o<<", r="<<r<<", and y="<<y<<endl<<endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

