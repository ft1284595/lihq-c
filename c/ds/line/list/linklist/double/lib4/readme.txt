这个版本是在lib2的基础上进行修改.
它的具体思路是,在llist.h中隐藏数据结构, 因为llist.c最终可以做成动态库或者静态库,
用户只需要根据llist.h的内容就能操作list. 但是用户并没有必要知道具体的node_st的内容,
因为用户如果知道了node节点的具体内容,他是可以通过一些方法来篡改node节点的内容的.



这是一个最基本的带头节点的双向循环链表
struct node_st {
	void *data;
	struct node_st *prev;
	struct node_st *next;
}

使用变长的struct结构来代替节点中的*data
struct node_st {
	struct node_st *prev;
	struct node_st *next;
	//char data[0]; 		//C99标准才支持0个元素数组的写法
	char data[1];			//这里只是一个占位符,即data的起始位置
}
