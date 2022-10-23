#include<bits/stdc++.h>
using namespace std;
map<string,double>Ar;
int n,top;
string s,s1;
char sta[1000];
double st[1000];
int main()
{
	freopen("Ar.txt","r",stdin);
	for(;;)
	{
		string s;
		double x=0;
		cin>>s>>x;
		if(s!="")
			Ar[s]=x;
		if(feof(stdin))
			break;
	}
	fclose(stdin);
	cin.clear();
	freopen("prob.txt","r",stdin);
	freopen("answer.txt","w",stdout);
	cin>>s;
	int len=s.length();
	bool flag1=0,flag=0;
	for(register int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			while(i<len && s[i]>='0' && s[i]<='9')
				s1+=s[i++];
			i--;
			if(!flag)
			{
				sta[++top]='*';
				sta[++top]='(';
				flag=1;
			}
			else
				s1+='*';
		}
		else
			if(s[i]=='.')
			{
				while(top && sta[top]!='(')
					s1+=sta[top--];
				sta[++top]='+';
				flag1=0;
				flag=0;
			}
			else
				if(s[i]>='A' && s[i]<='Z')
				{
					flag=1;
					if(flag1)
					{
						while(top && sta[top]!='(')
							s1+=sta[top--];
						sta[++top]='+';
					}
					else
						flag1=1;
					s1+=s[i++];
					while(i<len && s[i]>='a' && s[i]<='z')
						s1+=s[i++];
					i--;
				}
				else
					if(s[i]=='(')
					{
						while(top && sta[top]!='(')
							s1+=sta[top--];
						sta[++top]='+';
						sta[++top]=s[i];
						flag1=0;
					}
					else
						if(s[i]==')')
						{
							while(top && sta[top]!='(')
								s1+=sta[top--];
							top--;
						}
		s1+=' ';
	}
	while(top)
	{
		if(sta[top]=='(')
			top--;
		else
			s1+=sta[top--];
	}
	int len1=s1.length();
	for(register int i=0;i<len1;i++)
	{
		if(s1[i]==' ')
			continue;
		if(s1[i]=='+')
		{
			st[top-1]=st[top-1]+st[top];
			top--;
		}
		if(s1[i]=='*')
		{
			st[top-1]=st[top-1]*st[top];
			top--;
		}
		if(s1[i]>='A' && s1[i]<='Z')
		{
			string s2="";
			s2+=s1[i++];
			while(i<len1 && s1[i]>='a' && s1[i]<='z')
				s2+=s1[i++];
			i--;
			st[++top]=Ar[s2];
		}
		if(s1[i]>='0' && s1[i]<='9')
		{
			int x=0;
			while(i<len1 && s1[i]>='0' && s1[i]<='9')
				x=(x<<3)+(x<<1)+s1[i++]-48;
			i--;
			st[++top]=x;
		}
	}
	printf("%lf",st[1]);
	return 0;
}
