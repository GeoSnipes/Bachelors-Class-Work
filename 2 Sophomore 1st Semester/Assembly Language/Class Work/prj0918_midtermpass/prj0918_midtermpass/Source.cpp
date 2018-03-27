#include <iostream>
using namespace std;

void main()
{
	int t=0, o=0, g=0,d=0;
	for (t=0; t<=9; t++)
	{
		for (o=0; o<=9; o++)
		{
				for (g=0; g<=9; g++)
				{
					for (d=0; d<=9; d++)
					{
						if ((t!=g)&&(t!=o)&&(t!=d)&&(o!=g)&&(o!=d)&&(g!=d))
						{
							if ((4*(t*100+o*10+o))==(g*1000+o*100+o*10+d))
								{
									cout<<4*(t*100+o*10+o)<<endl;
									cout<<g*1000+o*100+o*10+d<<endl;
									cout<<"Too=Good when T="<<t<<", o="<<o<<", g="<<g<<", and d="<<d<<".\n\n";
								}
						}
					}
				}
		}
	}
	int s=0, e=0, n=0 ,m=0, r=0,y=0;
	for (s=0; s<=9; s++)
	{
		for (e=0; e<=9; e++)
		{
				for (n=0; n<=9; n++)
				{
					for (d=0; d<=9; d++)
					{
						for (m=0; m<=9; m++)
						{
							for (o=0; o<=9; o++)
							{
								for (r=0; r<=9; r++)
								{
									for (y=0; y<=9; y++)
									{
										if ((s!=e)&&(s!=n)&&(s!=d)&&(s!=m)&&(s!=o)&&(s!=r)&&(s!=y)&&(e!=n)&&(e!=d)&&(e!=m)&&(e!=o)&&(e!=r)&&(e!=y)&&(n!=d)&&(n!=m)&&(n!=o)&&(n!=r)&&(n!=y))
										{
											if ((d!=m)&&(d!=o)&&(d!=r)&&(d!=y)&&(m!=o)&&(m!=r)&&(m!=y)&&(o!=r)&&(o!=y)&&(r!=y))
											{
												if ((s*1000+e*100+n*10+d)+(m*1000+o*100+r*10+e)==(m*10000+o*1000+n*100+e*10+y))
												{
													cout<<(s*1000+e*100+n*10+d)+(m*1000+o*100+r*10+e)<<endl;
													cout<<(m*10000+o*1000+n*100+e*10+y)<<endl;
													cout<<"Send+More=Money when s"<<s<<", e="<<e<<", n="<<n<<", d="<<d<<", m="<<m<<endl
														<<"o="<<o<<", r="<<r<<", y="<<y<<".\n\n";
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
}