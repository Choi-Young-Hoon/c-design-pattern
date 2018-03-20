#include <iostream>
#include <vector>


// Observer ´ë»ó °´Ã¼µé.
class Observer {
public:
	virtual void DoWork(int a) = 0;
};


class ConcreteObserverA : public Observer {
public:
	virtual void DoWork(int a) override {
		std::cout << "ConcreteObserverA : " << a << std::endl;
	}
};


class ConcreteObserverB : public Observer {
public:
	virtual void DoWork(int a) override {
		std::cout << "ConcreteObserverB : " << a << std::endl;
	}
};


//Observer Event Notify °´Ã¼.
class Subject {
public:
	virtual void Attach(Observer* obs) = 0;
	virtual void Detach(Observer* obs) = 0;
	virtual void Notify() = 0;
};


class ConcreteSubject : public Subject {
public:
	explicit ConcreteSubject()
	{}

	virtual ~ConcreteSubject()
	{}
	

public:
	virtual void Attach(Observer* obs) override {
		notify_list.push_back(obs);
	}


	virtual void Detach(Observer* obs) override {
		for (auto i = notify_list.begin(); i != notify_list.end(); i++) {
			if (*i == obs) {
				notify_list.erase(i);
				break;
			}
		}
	}


	virtual void Notify() override {
		for (int i = 0; i < notify_list.size(); i++) {
			notify_list[i]->DoWork(i);
		}
	}


private:
	std::vector<Observer *> notify_list;
};



int main(void) {
	ConcreteSubject subject;
	Observer* obs_1 = new ConcreteObserverA();
	Observer* obs_2 = new ConcreteObserverB();

	subject.Attach(obs_1);
	subject.Attach(obs_2);

	subject.Notify();

	subject.Detach(obs_1);
	subject.Detach(obs_2);

	delete obs_1;
	delete obs_2;

	return 0;
}