#ifndef TICKETMAXHINEE_H_
#define TICKETMAXHINEE_H_

class TicketMachine{
public:
	TicketMachine();
	virtual ~TicketMachine();
    void showPrompt();
    void getMoney();
    void printTicket();
    void showBalance();
    void printError();
private:
    const int price;
    int balance;
    int total;
};

#endif 
