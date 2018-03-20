#include <iostream>
#include <vector>
#include <memory>


class Command {
public:
	explicit Command()
	{}
	virtual ~Command()
	{}


public: // Interface
	virtual void Execute() = 0;
};


class CommandTest1 : public Command {
public:
	explicit CommandTest1()
	{}
	virtual ~CommandTest1()
	{}


public: // Interface
	virtual void Execute() override {
		std::cout << "CommandTest1 Execute()" << std::endl;
	}
};


class CommandTest2 : public Command {
public:
	explicit CommandTest2()
	{}
	virtual ~CommandTest2()
	{}


public: // Interface
	virtual void Execute() override {
		std::cout << "CommandTest2 Execute()" << std::endl;
	}
};


class Commander {
public:
	explicit Commander() {
		InitCommand();
	}
	virtual ~Commander()
	{}

public: // Function
	void InitCommand() {
		m_CommandList.push_back(std::shared_ptr<Command>(new CommandTest1));
		m_CommandList.push_back(std::shared_ptr<Command>(new CommandTest2));
	}
	void Execute(int num) {
		m_CommandList[num]->Execute();
	}


private:
	std::vector<std::shared_ptr<Command>> m_CommandList;
};


int main(void) {
	Commander command;

	command.Execute(0);
	command.Execute(1);

	return 0;
}