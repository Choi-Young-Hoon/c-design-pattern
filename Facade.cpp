#include <iostream>

/*
* �Ϸ��� Ŭ������ ������ �������̽� ����.
*/


class LeftLegs {
public:
	explicit LeftLegs()
	{}
	virtual ~LeftLegs()
	{}

public: // Function
	void Move() {
		std::cout << "Left Move" << std::endl;
	}
};


class RightLegs {
public:
	explicit RightLegs()
	{}
	virtual ~RightLegs()
	{}

public: // Function
	void Move() {
		std::cout << "Right Move" << std::endl;
	}
};



class Legs {
public:
	explicit Legs()
	{}
	virtual ~Legs()
	{}

public:
	void Move() {
		m_Right.Move();
		m_Left.Move();
	}

private:
	RightLegs m_Right;
	LeftLegs  m_Left;
};

int main(void) {
	Legs leg;

	leg.Move();

	return 0;
}