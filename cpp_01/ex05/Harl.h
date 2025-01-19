#ifndef HARL_H_
#define HARL_H_

#include <string>

class Harl
{
public:
	void complain(std::string level);
private:
	void debug();
	void info();
	void warning();
	void error();
};

#endif //HARL_H_