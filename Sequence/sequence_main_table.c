#include<stdio.h>
#include<stdlib.h>
#include"sequence_sub_table.h"


int main(){
SEQ *p=CreateEpSeqlist();
InsertIntoSeqlist(p,0,100);
InsertIntoSeqlist(p,1,200);
ChangeSeqlist(p,100);
show(p);
delSeqlist(p,0);
ChangeSeqlist(p,100);
show(p);

//释放malloc函数开辟的空间
free(p);
return 0;
}



