#include <iostream>
#include <string>
#include <list>
#include <memory>

/*
* 해석자 패턴 (Interpreter Pattern)
* 문법 규칙을 클래스화 한 구조로써, 일련의 규칙으로 정의된 언어를 해석하는 패턴이다.
* 문법 규칙이 많아지면 복잡하고 무거워지기 때문에 그럴땐 차라리 파서/컴파일러 생성기를 쓰는게 좋다.
* 언어 분석기 라고 생각하면 되며, 스크립트나 컴파일러 문법등이 있을 수 있다.
* 예로 SQL 구문이나 shell 커맨드 해석기, 통신 프로토콜 등이 있다.
*/


// Context 클래스
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



// Abstract Expression 인터페이스
class AbstractExpression {
public:
	virtual void Interpreter(Context* pContext) = 0;
};


// Terminal Expression 상속 클래스
class TerminalExpression : public AbstractExpression {
public:
	virtual void Interpreter(Context* pContext) override {
		std::cout << "TerminalExpression" << std::endl;
	}
};


// Nonterminal Expression 상속 클래스
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