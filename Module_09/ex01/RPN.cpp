#include "RPN.hpp"

RPN::RPN(std::string argument) : _arg(argument) {
    if (_arg.find_first_not_of("0123456789+-*/ ") != std::string::npos) {
        std::cout << "Error invalid characters" << std::endl;
        exit(1);
    }
    cleanPrompt();
    execute();
}

RPN::~RPN() {}

void RPN::cleanPrompt() {
    while ((int)_arg.find(' ') != -1) {
        int i = (int)_arg.find(' ');
        _arg.erase(i, 1);
    }
}

void RPN::doOperation() {
    int n1, n2;
    if (_data.size() < 2) {
        std::cout << "Error incorrect Polish Expression" << std::endl;
        exit(1);
    }
    if ((_arg[1] == '-' || _arg[1] == '+' || _arg[1] == '*' || _arg[1] == '/') && (_arg[0] == '-' || _arg[0] == '+')) {
        if (_arg[0] == '-') {
            int top = _data.top();
            _data.pop();
            int top2 = _data.top() * -1;
            _data.push(top2);
            _data.push(top);
        }
        return ;
    }
    n1 = _data.top();
    _data.pop();
    n2 = _data.top();
    _data.pop();
    std::cout << "op = "<< n2 << _arg[0] << n1 << std::endl; 
    switch (_arg[0]) {
        case '+':
                _data.push(n1 + n2);
                break;
        case '-':
                _data.push(n2 - n1);
                break;
        case '/':
                _data.push(n2 / n1);
                break;
        case '*':
                _data.push(n2 * n1);
                break;
    }
    std::cout << "final op = " << _data.top() << std::endl;
}

void RPN::execute() {
    while (!_arg.empty()) {
        std::cout << "Arg = " << _arg << std::endl;
        if (std::isdigit(_arg[0])) {
            std::cout << "pusnhing " << _arg[0] - 48 << std::endl;
            _data.push(static_cast<int>(_arg[0] - 48));
        }
        else
            doOperation();
        _arg.erase(0, 1);
    }
    std::cout << _data.top() << std::endl;
}

