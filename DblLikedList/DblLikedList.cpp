#include <iostream>
#include <string>;
#include "clsQueueLine.h"
using namespace std; 


int main()
{
	
	clsQueueLine PayBillsQueueLine("A0" , 10);
	clsQueueLine SubscriptionQueue("B0", 5); 

	PayBillsQueueLine.IssueTicket();
	PayBillsQueueLine.IssueTicket();
	PayBillsQueueLine.IssueTicket();
	PayBillsQueueLine.IssueTicket();
	PayBillsQueueLine.IssueTicket();

	PayBillsQueueLine.printInfo();

	PayBillsQueueLine.printTicketInfoRTL();
	PayBillsQueueLine.printTicketInfoLTR();

	PayBillsQueueLine.PrintAllTickets();

	cout << "\n\n Pay Baills Queue After Sreved Client Is : \n\n"; 
	PayBillsQueueLine.ServedNextClient(); 
	PayBillsQueueLine.printInfo();
	
	cout << "\n\n Subscription  Queue Info : \n\n";
	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();

	SubscriptionQueue.printInfo(); 
	SubscriptionQueue.printTicketInfoRTL();
	SubscriptionQueue.printTicketInfoLTR();
	SubscriptionQueue.PrintAllTickets();

	SubscriptionQueue.ServedNextClient(); 
	cout << "\n\n Subscription Queue After Sreved Client Is : \n\n";
	SubscriptionQueue.printInfo();




	system("pause>0");
}
