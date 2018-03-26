#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <memory>

/*
* �ؼ��� ���� (Interpreter Pattern)
* ���� ��Ģ�� Ŭ����ȭ �� �����ν�, �Ϸ��� ��Ģ���� ���ǵ� �� �ؼ��ϴ� �����̴�.
* ���� ��Ģ�� �������� �����ϰ� ���ſ����� ������ �׷��� ���� �ļ�/�����Ϸ� �����⸦ ���°� ����.
* ��� �м��� ��� �����ϸ� �Ǹ�, ��ũ��Ʈ�� �����Ϸ� �������� ���� �� �ִ�.
* ���� SQL �����̳� shell Ŀ�ǵ� �ؼ���, ��� �������� ���� �ִ�.
*/

// Context �� ����� And ���� OR ���� �ؼ����ִ� ������ ����.



// Abstract Expression
class AbstractExpression {
public:
	virtual bool Interpreter(std::string strData) = 0;
};



// TerminalExpression ��� Ŭ����
class TerminalExpression : public AbstractExpression {
public:
	explicit TerminalExpression(std::string strData)
		: m_strMliteral(strData)
	{}


public:
	virtual bool Interpreter(std::string strData) override {
		std::istringstream iss(strData);
		std::string strToken;

		while (iss) {
			iss >> strToken;


			if (strToken == m_strMliteral) {
				std::cout << "Token: " << strToken << std::endl;
				return true;
			}
		}
		return false;
	}


private:
	std::string m_strMliteral;
};



// OR Expression ��� Ŭ����
class OrExpression : public AbstractExpression {
public:
	explicit OrExpression(AbstractExpression* pE1, AbstractExpression* pE2)
		: m_pExpression1(pE1), m_pExpression2(pE2)
	{}

	virtual ~OrExpression() {
		if (m_pExpression1 != NULL) {
			delete m_pExpression1;
		}

		if (m_pExpression2 != NULL) {
			delete m_pExpression2;
		}
	}


public:
	virtual bool Interpreter(std::string strData) override {
		return m_pExpression1->Interpreter(strData) || m_pExpression2->Interpreter(strData);
	}


private:
	AbstractExpression* m_pExpression1;
	AbstractExpression* m_pExpression2;
};



// And Expression ��� Ŭ����
class AndExpression : public AbstractExpression {
public:
	explicit AndExpression(AbstractExpression* pE1, AbstractExpression* pE2)
		: m_pExpression1(pE1), m_pExpression2(pE2)
	{}

	virtual ~AndExpression() {
		if (m_pExpression1 != NULL) {
			delete m_pExpression1;
		}

		if (m_pExpression2 != NULL) {
			delete m_pExpression2;
		}
	}


public:
	virtual bool Interpreter(std::string strData) override {
		return m_pExpression1->Interpreter(strData) && m_pExpression2->Interpreter(strData);
	}


private:
	AbstractExpression* m_pExpression1;
	AbstractExpression* m_pExpression2;
};




// �ؼ��� ���� ���� �Լ�
AbstractExpression* buildInterpreterTree() {
	// Literal
	AbstractExpression* pTerminal1 = new TerminalExpression("Hong");
	AbstractExpression* pTerminal2 = new TerminalExpression("Gil");
	AbstractExpression* pTerminal3 = new TerminalExpression("Dong");
	AbstractExpression* pTerminal4 = new TerminalExpression("Choi");

	/* Hong �Ǵ� Gil*/
	AbstractExpression* alternation1 = new OrExpression(pTerminal1, pTerminal2);
	/* Dong �Ǵ� (Hong �Ǵ� Gil) */
	AbstractExpression* alternation2 = new OrExpression(pTerminal3, alternation1);

	// Choi �׸��� (Hong �Ǵ� Gil)
	return new AndExpression(pTerminal4, alternation2);
}



int main(void) {
	std::string strContext1 = "Choi Young Hoon",
		strContext2 = "Choi Jae Gil",
		strContext3 = "Choi Hong";

	AbstractExpression* pExpression = buildInterpreterTree();

	std::cout << strContext1 << " is " << pExpression->Interpreter(strContext1) << std::endl;
	std::cout << strContext2 << " is " << pExpression->Interpreter(strContext2) << std::endl;
	std::cout << strContext3 << " is " << pExpression->Interpreter(strContext3) << std::endl;

	delete pExpression;

	return 0;
}