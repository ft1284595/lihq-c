这个版本在lib2的基础上,将链表操作的方法(insert, travel, find, fetch, delete...),以面向对象的方式封装到链表的头部节点中.

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
