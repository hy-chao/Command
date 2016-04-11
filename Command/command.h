#pragma once
#include<iostream>
using namespace std;
//Receiver�֪࣬�����ʵʩ��ִ��һ����������صĲ������κ��඼������Ϊһ��������
class Receiver
{
public:
	void Action()
	{
		cout << "ִ������!" << endl;
	}
};
//Command�࣬��������ִ�в����Ľӿ�
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
//ConcreteCommand�࣬��һ�������߶������һ�����������ý�������Ӧ�Ĳ�������ʵ��Execute
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
//Invoker�࣬Ҫ�������ִ���������
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

