#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <memory>

/*
* 해석자 패턴 (Interpreter Pattern)
* 문법 규칙을 클래스화 한 구조로써, 일련의 규칙으로 정의된 언어를 해석하는 패턴이다.
* 문법 규칙이 많아지면 복잡하고 무거워지기 때문에 그럴땐 차라리 파서/컴파일러 생성기를 쓰는게 좋다.
* 언어 분석기 라고 생각하면 되며, 스크립트나 컴파일러 문법등이 있을 수 있다.
* 예로 SQL 구문이나 shell 커맨드 해석기, 통신 프로토콜 등이 있다.
*/

// Context 의 명령이 And 인지 OR 인지 해석해주는 간단한 예제.



// Abstract Expression
class AbstractExpression {
public:
	virtual bool Interpreter(std::string strData) = 0;
};



// TerminalExpression 상속 클래스
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



// OR Expression 상속 클래스
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



// And Expression 상속 클래스
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




// 해석자 문법 생성 함수
AbstractExpression* buildInterpreterTree() {
	// Literal
	AbstractExpression* pTerminal1 = new TerminalExpression("Hong");
	AbstractExpression* pTerminal2 = new TerminalExpression("Gil");
	AbstractExpression* pTerminal3 = new TerminalExpression("Dong");
	AbstractExpression* pTerminal4 = new TerminalExpression("Choi");

	/* Hong 또는 Gil*/
	AbstractExpression* alternation1 = new OrExpression(pTerminal1, pTerminal2);
	/* Dong 또는 (Hong 또는 Gil) */
	AbstractExpression* alternation2 = new OrExpression(pTerminal3, alternation1);

	// Choi 그리고 (Hong 또는 Gil)
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