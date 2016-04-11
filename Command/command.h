#pragma once
#include<iostream>
using namespace std;
//Receiver类，知道如何实施与执行一个与请求相关的操作，任何类都可能作为一个接收者
class Receiver
{
public:
	void Action()
	{
		cout << "执行请求!" << endl;
	}
};
//Command类，用来声明执行操作的接口
class Command
{
protected:
	Receiver * receiver;
public:
	Command(Receiver * r)
	{
		receiver = r;
	}
	virtual void Execute() = 0;
};
//ConcreteCommand类，将一个接收者对象绑定于一个动作，调用接收者相应的操作，以实现Execute
class ConcreteCommand : public Command
{
public:
	ConcreteCommand(Receiver *r) : Command(r)
	{}
	void Execute()
	{
		receiver->Action();
	}
};
//Invoker类，要求该命令执行这个请求
class invoker
{
private:
	Command * command;
public:
	void SetCommand(Command * command)
	{
		this->command = command;
	}
	void ExecuteCommand()
	{
		command->Execute();
	}
};

