#include <iostream>
#include <iomanip>
#include <string>
#include "clsDbilLinkedList.h"
#include "clsMyQueue.h"
#include "clsDynamicArray.h"
#include "clsMyQueueArr.h"
#include "clsMyString.h"
#include "clsQueueLine.h"

using namespace std;

int main()
{
	clsQueueLine S("A0", 10);

	S.IssueTicket();
	S.IssueTicket();
	S.IssueTicket();
	S.IssueTicket();
	S.IssueTicket();

	S.PrintInfo();
	S.PrintTicketsLineRTL();
	S.PrintTicketsLineLTR();

	S.PrintAllTickets();
	S.ServeNextClient();
	S.PrintAllTickets();
	S.PrintInfo();

	system("pause>0");
	return 0;
}
