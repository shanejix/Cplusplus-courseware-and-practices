#include "TicketMachine.h"

int main(int argc, char const *argv[])
{
	TicketMachine tm;
	tm.getMoney(100);
	tm.showBalance();
	return 0;
}
