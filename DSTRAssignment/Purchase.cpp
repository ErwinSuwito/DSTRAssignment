#include "Purchase.h"

bool Purchase::AddPurchase(string cName, string cPhNo, string cEmail)
{
	time_t now = time(0);
	purchaseTimeStamp = ctime(&now);
	custName = cName;
	custEmail = cEmail;
	custPhNo = cPhNo;

	return false;
}
