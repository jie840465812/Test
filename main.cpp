#include "mian.h"

using namespace std;

Queue_t buf;
bool write_lock = false;
bool read_lock  = false;

void production( void )
{
	for ( int i = 1; i <= 100; ++i )
	{
		while ( write_lock || is_full_Q( buf ) )
			;
		write_lock = true;
		posh_Q( buf, i );
		printf("ID:%s  production:%5d\n", ((stringstream&)(stringstream()<<this_thread::get_id())).str().c_str(), i);
		write_lock = false;
	}
}

void expenditure( void )
{
	for ( int i = 1; i <= 100; ++i )
	{
		while ( read_lock || is_empty_Q( buf ) )
			;
		read_lock = true;
		printf("ID:%s  expenditure:%4d\n", ((stringstream&)(stringstream()<<this_thread::get_id())).str().c_str(), pop_Q( buf ));
		read_lock = false;
	}
}


int main( int argc, const char *argv[] )
{
	const size_t m = 2;
	thread t1[m], t2[m];
	init_Q( buf );

	for ( int i = 0; i < m; i++ )
	{
		t1[i] = thread(production);
		t2[i] = thread(expenditure);
	}
	for ( int i = 0; i < m; i++ )
        {
		t1[i].join();
		t2[i].join();
        }
	
	
	return EXIT_SUCCESS;
}
