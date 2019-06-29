#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define max 32
int ifempty=0;//标志，判断链表是无否为空
long long int nowcounter=0;
long long int outcounter[2050][13]={0};
long long int incounter[2050][13]={0};
struct outmouth
{
	char name[max];
	int counter[2050][13];
}out_mouth[5000];
int ii=0;
struct outmouth_ki
{
	char kind[max];
	int counter[2050][13];
}out_mouth_ki[5000];
int oo=0;
typedef struct dnode /* 定义双向链表结构体 */
{
int year;/*年*/
int mouth;/*月*/
int day;/*日*/
int number; /* 货物编号 */
char name[max]; /* 货物名称 */
char  kind[max];/*货物类型*/
int price;/*单价*/
int counter; /* 货物数量 */
struct dnode *prior, *next;
/* 定义两指针，分别指向其前驱和后继 */
}dlnode;

dlnode *create(dlnode *L);
dlnode *input(dlnode *L);
dlnode *output(dlnode *L);
dlnode * outnum(dlnode *L);
dlnode * outname(dlnode *L);
dlnode * outkind(dlnode *L);
dlnode *current(dlnode *L);
void search(dlnode *L);
void searchnum(dlnode *L);
void searchname(dlnode *L);
void searchkind(dlnode *L);
void display(dlnode *L) ;

void iocounter()
{
	int y,ye,mo;
	char na[max],ki[max];
	while(1)
{
printf("=====================\n");
printf("1.在库元器件总价值\n");
printf("2.每月出库元器件总价值\n");
printf("3.每月出库元器件数量(按名称查询)\n");
printf("4.每月出库元器件数量(按类型查询)\n");
printf("0.返回上一层\n");
printf("====================\n");
printf("选择0--4:");
scanf("%d",&y);
int ion=0;
switch(y)
{
case 1:printf("在库元器件总价值为%lld\n",nowcounter);break;
case 2:printf("请输入年份与月份：\n");
		scanf("%d%d",&ye,&mo);
		printf("%d年%d月的出库元器件总价值为%lld\n",ye,mo,outcounter[ye][mo]);
		break;
case 3:printf("请输入元器件名称：\n") ;
		scanf("%s",&na);
		printf("请输入年份与月份：\n") ;
		scanf("%d%d",&ye,&mo);
		for(int i=0;i<=ii;i++)
		if(strcmp(out_mouth[i].name,na)==0)
		{
		printf("%d年%d月%s共出库%lld件\n",ye,mo,na,out_mouth[i].counter[ye][mo]);ion=1;break;
		}
		if(ion==0) printf("未找到该元器件，请检查是否输入错误\n");ion=0;
		break;
case 4:printf("请输入元器件类型：\n") ;
		scanf("%s",&ki);
		printf("请输入年份与月份：\n") ;
		scanf("%d%d",&ye,&mo);
		for(int i=0;i<=oo;i++)
		if(strcmp(out_mouth_ki[i].kind,ki)==0)
		{
		printf("%d年%d月%s共出库%lld件\n",ye,mo,ki,out_mouth_ki[i].counter[ye][mo]);ion=1;break;
		}
		if(ion==0) printf("未找到该元器件，请检查是否输入错误\n");ion=0;
		break;
case 0:return;//返回
default:printf("enter error!Please input 0--4!\n\n");
getchar();getchar();printf("\n\n");
}
}
}
int main()
{
int x;
dlnode *L;
if(!(L=(dlnode *)malloc(sizeof(dlnode)))) //分配空间
{
printf("\n");
exit(1);
}
create(L);///调用函数，创建头节点
while(1)
{////////////////////////主菜单///////////////////////////
printf(" ============================\n");
printf(" 1. 货物出库和入库\n");
printf(" 2. 查找货物表\n");
printf(" 3. 显示仓库货物表\n");
printf(" 4. 统计数据\n");
printf(" 0. 退出\n");
printf(" =============================\n");
printf(" 选择0--4:");
scanf("%d",&x);
switch(x)
{
case 2:search(L);break;//调用查找函数
case 1:current(L);break;//调用入库出库函数
case 3:display(L);break;//调用显示输出函数
case 4:iocounter();break;//调用统计函数
case 0:printf("\n bye!see you!\n");
getchar();getchar();exit(0);//退出程序
default:printf("\n Enter erreor!please input 0--4!");
getchar();getchar();
}
}
}
dlnode *create(dlnode *L)//创建链表头节点
{
printf(" 欢迎使用电子元器件仓库管理系统");
getchar();
ifempty=0;
///////初始化头节点的值////////
L->next=NULL;L->prior=NULL;
L->number=L->counter=L->day=L->mouth=L->year=L->price=0;
strcpy(L->name," ");
strcpy(L->kind," ");
return L;
}

void search(dlnode *L) ///查找的主要菜单
{
int y;
if(ifempty==0)
{
printf("没有输入货物!\n");
getchar();getchar();
return;
}
else
{
while(1)
{
printf("=====================\n");
printf("1.按编号查询\n");
printf("2.按货物名称查询\n");
printf("3.按货物类型查询\n");
printf("0.返回上一层\n");
printf("====================\n");
printf("选择0--3:");
scanf("%d",&y);
switch(y)
{
case 1:searchnum(L);break;//调用按编号查找的函数
case 2:searchname(L);break;//调用按名称查找的函数
case 3:searchkind(L);break;//调用按名称查找的函数
case 0:return;//返回
default:printf("enter error!Please input 0--3!\n\n");
getchar();getchar();printf("\n\n");
}
}
}
}
void searchnum(dlnode *L)///按编号查找的函数
{
int num,flag=0;//flag为是否找到的标志
dlnode *head=L;
if(ifempty==0)
{
printf("没有货物被输入\n");
getchar();getchar();
return;
}
printf("输入你要查找的货物编号:\n");
scanf("%d",&num);
while((L=L->next)!=head)
{
if(L->number==num)
{ flag=1;//flag为1时表示找到
printf("找到指定编号货物 \n");
printf("\n编号:%d\n",L->number);
printf("名称:%s\n",L->name) ;
printf("类型:%s\n",L->kind) ;
printf("数量:%d\n\n",L->counter);
}
}
if(flag==0)//flag为0时表示没有找到
printf("未找到该元器件，请检查是否输入错误\n");
getchar();getchar();
}

void searchname(dlnode *L)//按名称查找的函数
{
int flag=0;//flag为是否找到的标志
char na[32];
dlnode *head=L;
if(ifempty==0)
{
printf("没有货物被输入\n");
getchar();getchar();
return;
}
printf("输入你要查找的货物名称\n");
scanf("%s",&na);
while((L=L->next)!=head)
{
if(strcmp(L->name,na)==0)
{ flag=1;//flag为1时表示找到
printf("找到指定名称货物 \n");
printf("\n编号:%d\n",L->number);
printf("名称:%s\n",L->name) ;
printf("类型:%s\n",L->kind) ;
printf("数量:%d\n\n",L->counter);
}
}

if(flag==0)//flag为0时表示没有找到
printf("未找到该元器件，请检查是否输入错误\n\n");
getchar();getchar();
}

void searchkind(dlnode *L)//按名称查找的函数
{
int flag=0;//flag为是否找到的标志
char ki[32];
dlnode *head=L;
if(ifempty==0)
{
printf("没有货物被输入\n");
getchar();getchar();
return;
}
printf("输入你要查找的货物类型\n");
scanf("%s",&ki);
while((L=L->next)!=head)
{
if(strcmp(L->kind,ki)==0)
{ flag=1;//flag为1时表示找到
printf("找到指定类型货物 \n");
printf("\n编号:%d\n",L->number);
printf("名称:%s\n",L->name) ;
printf("类型:%s\n",L->kind) ;
printf("数量:%d\n\n",L->counter);
}
}

if(flag==0)//flag为0时表示没有找到
printf("未找到该元器件，请检查是否输入错误\n\n");
getchar();getchar();
}
dlnode *current(dlnode *L)//货物出库入库函数
{
int y;
while(1)
{
printf("========================\n");
printf(" 1.货物入库\n");
printf(" 2.货物出库\n");
printf(" 0.返回上一层\n");
printf("========================\n");
printf(" 选择0--2:");
scanf("%d",&y);
switch(y)
{
case 1:input(L);break;//调用入库函数
case 2:output(L);break;//调用出库函数
case 0:return(L);//返回上一层
default:printf("enter error!Please input 0--2!");
getchar();getchar();
printf("\n\n");
}
}
}

dlnode *input(dlnode *L)//定义入库函数
{
dlnode *in,*head;
head=in=(dlnode *)malloc(sizeof(dlnode));//分配空间
head=L;

printf("\n请输入日期(年 月 日)：\n");
scanf("%d%d%d",&in->year,&in->mouth,&in->day);
printf("\n请输入货物数据:\n");
printf("编号:");scanf("%d",&in->number);
printf("名称:");scanf("%s",&in->name);
printf("类型:");scanf("%s",&in->kind);
printf("单价:");scanf("%d",&in->price);
printf("数量:");scanf("%d",&in->counter);
incounter[in->year][in->mouth]+=in->price*in->counter;
nowcounter+=in->price*in->counter;
if(L->next==NULL) //如果只有头节点，
{ //把刚输入的in节点
L->next=in; //跟在头节点后面
L->prior=in; //
in->next=L; //
in->prior=L; //
ifempty++; //ifempty加1
}
else
{//如果当前L的下一个节点不是头节点
while((L=L->next)!=head)
{//如果输入的数大于L->number，则插到L的前面
if(L->number<in->number)
{
in->next=L;
in->prior=L->prior;
L->prior->next=in;
L->prior=in;
ifempty++; //ifempty加1
return(head);
}
}
//输入的编号比其它编号都小，则插到最后个节点，并首尾相连
head->prior->next=in;
in->prior=head->prior;
head->prior=in;
in->next=head;
ifempty++; //ifempty加1
}
return head;
}

dlnode *output(dlnode *L)//出库的函数
{
int y;
dlnode *head=L;
if(ifempty==0)//检测是否有货物输入
{
printf("没有货物输入系统\n");
getchar();getchar();
return(head);
}
while(1)
{
printf("=============\n");
printf("1.按编号出库\n");
printf("2.按名称出库\n");
printf("3.按类型出库\n");
printf("0.返回上一层\n");
printf("==============\n");
printf("选择0--3:");scanf("%d",&y);
switch(y)
{
case 1:outnum(L);break;//调用按编号出库函数
case 2:outname(L);break;//调用按名称出库函数
case 3:outkind(L);break;//调用按类型出库函数
case 0:return(L);
default:printf("enter error!Please input 0--3!");
getchar();getchar();printf("\n\n");
}
}
}
dlnode *outnum(dlnode *L)//按编号出库函数
{
int num;
dlnode *head=L;
int ion=0;
printf("请输入出库货物的编号:");
scanf("%d",&num);
while((L=L->next)!=head)
{//如果找到就删除节点
if(L->number==num)
{
outcounter[L->year][L->mouth]+=L->price*L->counter;
nowcounter-=L->price*L->counter;
for(int i=0;i<=oo;i++)
if(strcmp(out_mouth_ki[i].kind,L->kind)==0)
{
	out_mouth_ki[i].counter[L->year][L->mouth]+=L->counter,ion=1;
	break;
}
if(ion==0)
{
	strcpy(out_mouth_ki[oo++].kind,L->kind);
	out_mouth_ki[oo-1].counter[L->year][L->mouth]=L->counter;
}
ion=0;
for(int i=0;i<=ii;i++)
if(strcmp(out_mouth[i].name,L->name)==0)
{
	out_mouth[i].counter[L->year][L->mouth]+=L->counter;
	ion=1;break;
}
if(ion==0)
{
	strcpy(out_mouth[ii++].name,L->name);
	out_mouth[ii-1].counter[L->year][L->mouth]=L->counter;
}
L->prior->next=L->next;
L->next->prior=L->prior;
ifempty--; //ifempty减1
ion=1;
}
}
if(ion==1)
{
printf("编号为%d的货物成功出库",num);
getchar();getchar();
return head;
}
else
{
printf("未找到该元器件，请检查是否输入错误\n\n");
getchar();getchar();
return (head);
}
}

dlnode *outname(dlnode *L)//按名称出库函数
{
char na[32];
dlnode *head=L;
int ion=0;
printf("请输入出库货物的名称:");
scanf("%s",&na);
while((L=L->next)!=head)
{//如果找到就删除节点
if(strcmp(L->name,na)==0)
{
outcounter[L->year][L->mouth]+=L->price*L->counter;
nowcounter-=L->price*L->counter;
for(int i=0;i<=oo;i++)
if(strcmp(out_mouth_ki[i].kind,L->kind)==0)
{
	out_mouth_ki[i].counter[L->year][L->mouth]+=L->counter,ion=1;
	break;
}
if(ion==0)
{
	strcpy(out_mouth_ki[oo++].kind,L->kind);
	out_mouth_ki[oo-1].counter[L->year][L->mouth]=L->counter;
}
ion=0;
for(int i=0;i<=ii;i++)
if(strcmp(out_mouth[i].name,L->name)==0)
{
	out_mouth[i].counter[L->year][L->mouth]+=L->counter;
	ion=1;break;
}
if(ion==0)
{
	strcpy(out_mouth[ii++].name,L->name);
	out_mouth[ii-1].counter[L->year][L->mouth]=L->counter;
}
L->prior->next=L->next;
L->next->prior=L->prior;
ifempty--; //ifempty减1
ion=1;
}
}
if(ion==1)
{
printf("名称为%s的货物成功出库",na);
getchar();getchar();
return (head);
}
else
{
printf("未找到该元器件，请检查是否输入错误\n\n");
getchar();getchar();
return(head);
}
}

dlnode *outkind(dlnode *L)//按类型出库函数
{
char ki[32];
dlnode *head=L;
int ion=0;
printf("请输入出库货物的类型:");
scanf("%s",&ki);
while((L=L->next)!=head)
{//如果找到就删除节点
if(strcmp(L->kind,ki)==0)
{
outcounter[L->year][L->mouth]+=L->price*L->counter;
nowcounter-=L->price*L->counter;
for(int i=0;i<=oo;i++)
if(strcmp(out_mouth_ki[i].kind,L->kind)==0)
{
	out_mouth_ki[i].counter[L->year][L->mouth]+=L->counter,ion=1;
	break;
}
if(ion==0)
{
	strcpy(out_mouth_ki[oo++].kind,L->kind);
	out_mouth_ki[oo-1].counter[L->year][L->mouth]=L->counter;
}
ion=0;
for(int i=0;i<=ii;i++)
if(strcmp(out_mouth[i].name,L->name)==0)
{
	out_mouth[i].counter[L->year][L->mouth]+=L->counter;
	ion=1;break;
}
if(ion==0)
{
	strcpy(out_mouth[ii++].name,L->name);
	out_mouth[ii-1].counter[L->year][L->mouth]=L->counter;
}
L->prior->next=L->next;
L->next->prior=L->prior;
ifempty--; //ifempty减1
ion=1;
}
}
if(ion==1)
{
printf("类型为%s的货物成功出库",ki);
getchar();getchar();
return (head);
}
else
{
printf("未找到该元器件，请检查是否输入错误\n\n");
getchar();getchar();
return(head);
}
}

void display(dlnode *L)//显示货物清单
{
dlnode *head=L;
if(ifempty==0)
{
printf("没有货物可显示\n");
getchar();getchar();
return;
}
L=L->next;
do
{
printf("\n编号:%d\n",L->number);
printf("名称:%s\n",L->name) ;
printf("类型:%s\n",L->kind) ;
printf("数量:%d\n\n",L->counter);
}while((L=L->next)!=head);
getchar();getchar();
}
