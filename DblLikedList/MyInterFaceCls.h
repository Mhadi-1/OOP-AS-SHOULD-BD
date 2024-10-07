#pragma once
#include<iostream>
#include<string>
using namespace std; 

class ClsMyQueueLineInterFace
{
private:

public:

	// Issue Ticket method
	virtual void  IssueTicket() = 0;
	// print Object Info 
	virtual void printInfo() = 0;
	// Should Print All Ticket Prefix From right To Left
	virtual void printTicketInfoRTL() = 0;
	// Should Print All Ticket Prefix From Left To right
	virtual void printTicketInfoLTR() = 0;
	 /* Print All Tickets Info 
	 { (0) Prefix , (1) date  , (2) time , (3) wating Clients , (4) Service Time }
	 */
	virtual void PrintAllTickets() = 0;
	virtual bool ServedNextClient() = 0;

};

