#include "queue.h"

void init_Q( Queue_t& queue )
{
	queue.front = 1;
	queue.rear  = 0;
}

void posh_Q( Queue_t& queue, QElem_t value )
{
	if ( is_full_Q(queue) )
		return;
	queue.data[ ( queue.rear + 1 ) % ArraySize ] = value;
	queue.rear = ( queue.rear + 1 ) % ArraySize;
}

QElem_t pop_Q( Queue_t& queue )
{
	if ( is_empty_Q(queue) )
		return 0;
	QElem_t val = queue.data[ queue.front ];
	queue.front = ( queue.front + 1 ) % ArraySize;
	return val;
}

/*
QElem_t first_Q( Queue_t& queue )
{
	return ( queue.data )[ front ];
}
*/
bool is_empty_Q( Queue_t& queue )
{
	return ( queue.rear + 1 ) % ArraySize == queue.front;
}

bool is_full_Q( Queue_t& queue )
{
	return ( queue.rear + 2 ) % ArraySize == queue.front;
}

