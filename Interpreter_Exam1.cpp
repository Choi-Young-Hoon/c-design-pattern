#include <iostream>
#include <string>
#include <list>
#include <memory>

/*
* �ؼ��� ���� (Interpreter Pattern)
* ���� ��Ģ�� Ŭ����ȭ �� �����ν�, �Ϸ��� ��Ģ���� ���ǵ� �� �ؼ��ϴ� �����̴�.
* ���� ��Ģ�� �������� �����ϰ� ���ſ����� ������ �׷��� ���� �ļ�/�����Ϸ� �����⸦ ���°� ����.
* ��� �м��� ��� �����ϸ� �Ǹ�, ��ũ��Ʈ�� �����Ϸ� �������� ���� �� �ִ�.
* ���� SQL �����̳� shell Ŀ�ǵ� �ؼ���, ��� �������� ���� �ִ�.
*/


// Context Ŭ����
class Context {
public:
	explicit Context(char* szData)
		: m_strData(szData)
	{}


public:
	std::string GetData() { return m_strData; }


private:
	std::string m_strData;
};



// Abstract Expression �������̽�
class AbstractExpression {
public:
	virtual void Interpreter(Context* pContext) = 0;
};


// Terminal Expression ��� Ŭ����
class TerminalExpression : public AbstractExpression {
public:
	virtual void Interpreter(Context* pContext) override {
		std::cout << "TerminalExpression" << std::endl;
	}
};


// Nonterminal Expression ��� Ŭ����
class NonterminalExpression : public AbstractExpression {
public:
	virtual void Interpreter(Context* pContext) override {
		std::cout << "NonterminalExpression" << std::endl;
	}
};



int main(void) {
	Context context("Test Context");

	std::list<std::shared_ptr<AbstractExpression>> list;
	list.push_back(std::shared_ptr<AbstractExpression>(new TerminalExpression()));
	list.push_back(std::shared_ptr<AbstractExpression>(new NonterminalExpression()));

	for (auto& iter : list) {
		iter->Interpreter(&context);
	}

	list.clear();

	return 0;
}