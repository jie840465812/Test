#ifndef _QUEUE_H_
#define _QUEUE_H_

#define BueueSize 1000
#define ArraySize (( BueueSize ) + 1)

typedef int QElem_t;

struct Queue_t {
	QElem_t data[ArraySize];
	unsigned int front;
	unsigned int rear;
};

// 初始化队列
void init_Q( Queue_t& queue );

// 插入元素（不检查队列是否为满）
void posh_Q( Queue_t& queue, QElem_t value );

// 取出元素
QElem_t pop_Q( Queue_t& queue );

// 判断队列是否为空
bool is_empty_Q( Queue_t& queue );

// 判断队列是否为满
bool is_full_Q( Queue_t& queue );

#endif
