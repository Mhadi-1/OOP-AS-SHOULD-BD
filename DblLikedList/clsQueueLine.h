#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "MyInterFaceCls.h"
#include "C:\Users\chmik\source\repos\BanckClient\BANCKPROJECT\BANCKPROJECT/clsDate.h"


using namespace std; 

class clsQueueLine : protected ClsMyQueueLineInterFace
{
private:
	
	short _TotalTickets = 0; 
	string _Prefix; 
	short _AverageTimeSreved = 0 ; 

	class clsTicket {
	private:

		short _TNumber = 0;
		string _Prefix;
		string _TicketTime;
		string _TicketDate; 
		short _WaitingClients = 0;
		short _AverageServeTime = 0;
		clsDate Date; 

	  public:

		  clsTicket(string Prefix, short TicketNumber, short WaitingClient , short AverageServeedTime) {

			  _Prefix = Prefix; 
			  _TNumber = TicketNumber; 
			  _AverageServeTime = AverageServeedTime;
			  _TicketTime = Date.GetSystemDateTimeString();
			  _WaitingClients = WaitingClient;
			  _TicketDate = Date.DateToString();
		  }


		  string Prefix() {

			  return _Prefix;
		  }

		  string FullNumber() {

			  return _Prefix + to_string(Number()); 
		  }

		  string TicketTime() {
			  return _TicketTime; 
		  }

		  string TicketDate() {
			  return _TicketDate; 
		  }

		  short Number() {
			  return _TNumber;
		  }

		  short WiatingClient() {
			  return _WaitingClients; 
		  }

		  short ExpectedServeTime() {

			  return _AverageServeTime * _WaitingClients; 
		  }

		  void Print() {

			  cout << "\n\t\t\t  _______________________\n";
			  cout << "\n\t\t\t\t    " << FullNumber();
			  cout << "\n\n\t\t\t    " << TicketTime() + " : " + TicketDate();
			  cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
			  cout << "\n\t\t\t      Serve Time In";
			  cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			  cout << "\n\t\t\t  _______________________\n";
			  cout << "\n";
		  }

	}; 


public:

	queue<clsTicket> QueueLine; 

	clsQueueLine(string Prefix, short Servicetime) {
		
		//_TicketNumber = 0 ; 
		_Prefix = Prefix; 
		_AverageTimeSreved = Servicetime; 

	}

	
	void IssueTicket() {

		_TotalTickets++;

		clsTicket Ticke(_Prefix, _TotalTickets, WhoIsNext(), _AverageTimeSreved);
		QueueLine.push(Ticke);
	};

	short WhoIsNext() {
		return QueueLine.size();
	}

	short WaitingClients() {

		return QueueLine.size();
	}

	short ServedClients() {

		return _TotalTickets - WaitingClients();
	}

	void printTicketInfoRTL() {

		if (QueueLine.empty()) {
			return; 
		}
		
			queue<clsTicket> _TempalteQueueLine; 
			_TempalteQueueLine = QueueLine; 
			while (!_TempalteQueueLine.empty())
			{
				cout << " " << _TempalteQueueLine.front().FullNumber() << " <-- ";
				_TempalteQueueLine.pop();

			}
			cout << endl;
	}
	
	void printTicketInfoLTR() {

		if (QueueLine.empty()) {
			return; 
		}
		
		queue<clsTicket> _TempalteQueueLine;
		queue<clsTicket> _TemplateStackLine; 
	   _TempalteQueueLine = QueueLine;

	   while (!_TempalteQueueLine.empty())
	   {
		   _TemplateStackLine.push(_TempalteQueueLine.front()); 
		   _TempalteQueueLine.pop();
	   }

	   while (!_TemplateStackLine.empty()) {

		   cout << " " << _TemplateStackLine.front().FullNumber() << " --> ";
		   _TemplateStackLine.pop();
	   }
		
	   cout << endl;
	}
	
	void printInfo() {

		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";
		

	}
	
	void PrintAllTickets() {

		cout << "\n\n\t\t\t       ---Tickets---";
		if (QueueLine.empty()) {
			cout << "\n\n\t\t\t     ---No Tickets---\n";
			return; 
		}
		
		queue<clsTicket> _TemplateQueueLine; 
		_TemplateQueueLine = QueueLine; 
		while (!_TemplateQueueLine.empty())
		{
			_TemplateQueueLine.front().Print(); 
			_TemplateQueueLine.pop();
		}
	}

	bool ServedNextClient() {

		if (QueueLine.empty()) {

			cout<< " No Clients To Served ";
			return false; 
		}
		else {

		   QueueLine.pop();
		}
		return true;
	}


};

