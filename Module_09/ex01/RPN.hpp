#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <stack>

class RPN {
	private:
		std::string _arg;
		std::stack<int> _data;
	public:
		RPN(std::string argument);
		~RPN();

        void execute();
        void doOperation();
        void cleanPrompt();
};
#endif