#include "TicketMachine.h"
#include <iostream>
using namespace std;

TicketMachine::TicketMachine():price(0){
	
} 
TicketMachine::~TicketMachine(){
	
}

TicketMachine::void showPrompt(){

	cout<<"someting";
}

TicketMachine::void getMoney(int money){

	balance+=money;
}

TicketMachine::void printTicket(){

}

TicketMachine::void showBalance(){

	cout<<balance;
}

TicketMachine::void printError(){

}
