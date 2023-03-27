#include <iostream>
#include "Item.h"
#include "HealthPot.h"
using namespace std;
int main()
{
	HealthPot hp(0, 100, 50);
	hp.receiveItem();
	cout << hp.GetCount();
}