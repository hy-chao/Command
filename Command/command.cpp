#include "command.h"

int main()
{
	Receiver * r = new Receiver();
	Command * c = new ConcreteCommand(r);
	invoker * i = new invoker();
	i->SetCommand(c);
	i->ExecuteCommand();
	return 0;
}