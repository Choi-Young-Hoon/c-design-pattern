#include <iostream>


class Duck {
public:
	explicit Duck()
	{}
	virtual ~Duck()
	{}

public: // Interface
	virtual void Quack() = 0;
};