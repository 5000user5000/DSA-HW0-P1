//#include<iostream>
#include<stdio.h>
#include <string.h>
//using namespace std;

int getLength(char arr[256]);
void copy(char a[],char m[]);
void subtract(char m[],char n[]);
void arrange(char m[],int len);
void half(char a[]);
void multify(int times,char n[]);//����n�Ϊ���ƥ��ŧi 

int main()
{
	char a[256]={},b[256]={},m[256]={},n[256]={};//�@��u�Ǥ@�ӭ� ,��int�n�� ,�̦h�u��256��� ,���q�Ŧ�,���M�|�ü� 
	int ans =1,mLength,nLength;
	
	scanf("%s",a);//��J�]�ܳ·� ,�ݱ��p�M�w�n���n��& ,�٦��`�N�̤j��Ʀb�Ĥ@��a[0]�B 
	scanf("%s",b);
	
	/*int i=0;
	while(a[i]) //output�޳N 
	{
		printf("%d",(int)a[i]-48);ascii code
		i++;
	}*/
	
	
	//��j����m,�p����n 
	if(getLength(a)>getLength(b))//�����Ƥj�p 
	{
		copy(a,m);
		copy(b,n);
	}
	else if(getLength(a)<getLength(b))
	{
		copy(b,m);
		copy(a,n);
	}
	else//��ƬۦP�N�u��ѹ�� 
	{
		int i=0;
		while(a[i])
		{
			if((int)a[i]>(int)b[i])
			{ copy(a,m);
		      copy(b,n);
		      break;//�Y�ϸ��X�j��ٮɶ� 
				
			}
			if((int)a[i]<(int)b[i])
			{ copy(b,m);
		      copy(a,n);
		      break;
				
			}
		}
		
	}
	

	  
	
	//�}�l�䤽�]�� 
	while((int)m[0]-48>0 && (int)n[0]-48>0) 
	{
		mLength = getLength(m);
		nLength = getLength(n);
		int mEnd,nEnd;
		mEnd = (int)m[mLength-1]-48;
		nEnd = (int)n[nLength-1]-48;
		
		if(mEnd% 2==0 && nEnd%2==0 )
		{
			ans*=2;
			half(n);
			half(m); 
		}
		else if(nEnd%2==0)half(n);
		else if(mEnd%2==0)half(m); 
		
		//�p�Gn���j�N�洫
		mLength = getLength(m);
		nLength = getLength(n);
		if(nLength>mLength) 
		{
			char temp[256]={};
			copy(m,temp);
			copy(n,m);
			memset(n, (char)(0), 256);//string.h,��n���k�s,���Mcopy����,�]��n��Ʀh,�L�k�Ψ�n������ 
			copy(temp,n);
		}
		else if(nLength==mLength)
		{
			for(int i=0;i<mLength;i++)
			{
				
				
				if((int)n[i]>(int)m[i])
				{
					char temp[256]={};
			        copy(m,temp);
			        copy(n,m);
			        memset(n, (char)(0), 256);//�k0���O'0' 
			        copy(temp,n);
			        break;
				
				  
				}
				
				if((int)m[i]>(int)n[i])//��b�U��,�p�G�񦨲Ĥ@��if,�|����U��if��,loop�����X 
				    break;
								
				
			}
		}
		//m = m -n;
		subtract(m,n);
	
		
		
	}
	multify(ans,n);
	
	for(int i=0;i<getLength(n);i++)
     printf("%d",(int)n[i] - 48);
	
	return 0;
}


/////////////////  �\����      ////////////////////////

int getLength(char arr[256])
{
	int i=0;
	while((int)arr[i]-48>=0)i++;//�u�n�O0~9���|�ŦX,�p�G�O�w�]��0�|�ܦ�-48 
	return i;//�`�N����+1,�]�����]�� 
}
void arrange(char m[],int len)//�ƦC,���ӦC���e��,�]�\�Φ�queue���n 
{
	
	for(int i=0;i<len-1;i++ )m[i]=m[i+1];
	if(len<256)m[len-1]=m[len];
	else m[255] = (char)(0);//�`�Nchar 0�M'0'�O���P��,char 0��ascill code =0,��-48 =-48 
	
}
void copy(char a[],char m[])//array�����N�O����,�ҥH�|��� 
{	int i=0;
	while(a[i]){
	m[i]=a[i];
	i++;
	}
	
}
void subtract(char m[],char n[])//m = m-n
{
	int mLen = getLength(m);
	int	nLen = getLength(n);
	
	int i = mLen - 1;
	int j = nLen - 1;
	int down=0;
	int nVal =0;//�Ψ����Im��Ƥj�Ln���H�W
	while(i >= 0)
	{
		if(j>=0)
		{
		    nVal=(int)n[j];
		}
		else nVal =48;
		  
		  
		if((int)m[i]-down>=nVal)
		 { 
			m[i] = (char)((int)m[i]-nVal-down + 48);
			down=0;
		 }
		 else
		 {
			m[i] = (char)((int)m[i] + 10 - nVal -down + 48);//�[��k,�q�e���n10
			down =1;
			//m[i - 1] = (char)((int)m[i - 1] - 1 );if pre is 0 
		 }
		    
		
		i--;
		j--;
	}
	while((int)m[0] - 48==0)
	{
		arrange(m,mLen);
		
	}
	
} 

void half(char a[])//���H2
{

   int len = getLength(a);
   for(int i=0;i<len;i++)
   {
    
	if( ((int)a[i] - 48)%2 !=0 && i!= len-1 )a[i+1] = (char)( (int)a[i+1] +10);
	a[i] = (char)( ((int)a[i] - 48)/2+48);
   	
   	
   	
   }
   
   while((int)a[0] - 48==0)
   {
		arrange(a,len);
		
	}
}
void multify(int times,char n[])
{
	int len = getLength(n),length=0;
	int upNow=0,upPre=0;//�i�� 
	if(len<10)
	{
	  for(int i=len;i>0;i--)
	    n[i]=n[i-1];//�����Ჾ,�⭺��ťX�Ӷi��
	  n[0] = '0';//�����0 
	  length =len;
	  
	} 
	if(len==10) length=len-1;//�h��length�O�]���p�G�u��len,len-1����,arrarnge�|���� 
	
	for(int i=length;i>=0;i--)
    {
       upNow =  ( ((int)n[i] - 48)*times +upPre);
	    
	    if( upNow >= 10  )
	    {
	  	  
		  n[i] = (char)( upNow%10+48);
		  upNow =  upNow/10;
		  upPre = upNow;
		  
		  
	   }
	   else
	   {
	   	 n[i] = (char)( upNow%10+48);
	   	 upPre =0;//�]���S�i��
	   }
   	
   	
   	
    }
	 
	

   
   while((int)n[0] - 48==0)//�קK����0 
   {
		arrange(n,len+1);
		
	}
	
	
	
	
}
 
 

