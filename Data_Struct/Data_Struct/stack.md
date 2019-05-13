<?xml version="1.0" encoding="utf-8"?>
<RuleSet Name="New Rule Set" Description=" " ToolsVersion="10.0">
</RuleSet>

##	栈
###	顺序栈
*	栈是限制在一端进行插入操作和删除操作的线性表（俗称堆栈）。
*   允许进行操作的一端成为“栈顶”，另一固定端成为“栈底”，当栈中没有元素时成为“空栈”。
*   特点“先进后出”

###	链式栈
  *插入操作和删除操作均在链表头部进行，链表尾部就是栈底，栈顶指针就是头指针。
```
struct node_t{
data_t data;
struct node_t *next;
};
```

### 队列
队列是限制在两端进行插入操作和删除操作的线性表。
允许进行存入操作的一端称为“队尾”，允许进行删除操作的一端称为“队头”。
  *线性结构
  *先进先出（只允许在表尾插入，表头取出）
  *顺序队列 sequeue
  *链式队列 linkqueue
