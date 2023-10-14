#include<stdio.h>
int len=9;
int insert(int *a,int num,int in_num){
		int i=0;

#if 1
		len++;
		for(i=len;i>=num;i--){
a[i]=a[i-1];
// printf("ti:%d\n %d ",a[i],i);
		}
		a[num]=in_num;
		return 0;
#else
printf("%d",i);
return 0;
#endif

}
int show(int *a){

		for(int j=0;j<len;j++){
		printf("%d\n",a[j]);
		}

};
int del(int *a,int num){
for(int i=num;i<len;i++){
a[i]=a[i+1];
}
len--;
}

int main(){
int a[100]={1,2,3,4,5,6,7,8,9};
printf("len%d\n",len);
insert(a,3,100);
printf("len%d\n",len);
show(a);
del(a,3);
printf("-----------");
show(a);
}
