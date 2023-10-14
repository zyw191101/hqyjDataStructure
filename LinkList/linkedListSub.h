#ifndef N
#define N
typedef char datatype;

//链表结构体
typedef struct link_node_list{
datatype data;
struct link_node_list *next;
}LNL;

//学生链表结构体
typedef struct student{
float score;
struct student *next;
}STU;


// void swapLinkList(LNL *head);
int InsertEnd(STU *head,STU *tail,STU *pstu);
void show(STU *head);
// createLinkList();
STU * createLinkList();

void insertMdInto(STU *head,float data,int insert);

int acmlenLinkList(STU *head);

int sigleDel(STU *head,int delNum);

int clearLinkList(STU *head);

int searchDataLinkList(STU *head,float data);
#endif
