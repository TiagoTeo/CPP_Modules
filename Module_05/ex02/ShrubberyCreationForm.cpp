/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:36:52 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 15:46:46 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("NoTarget") {
	std::cout << "Shrubbery Creation Form with no target default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target) {
	std::cout << "Shrubbery Creation Form constructor called with target: " << _target <<  std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Creation Form's: " << _target << " destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {
	std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

const std::string &ShrubberyCreationForm::getTarget() const {
	return (_target);
}

const char *ShrubberyCreationForm::NotSigned::what() const throw() {
	return ("Form is not signed, can't execute");
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer) const {
	std::string fileName = this->getTarget() + "_shrubbery.txt";
	std::ofstream outFile;

	if (!this->getIsSigned())
		throw ShrubberyCreationForm::NotSigned();
	else if (executer.getGrade() > this->getGradeExec())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::cout << this->getTarget() << " planting a ASCII tree..." << std::endl;
	outFile.open(fileName.c_str());
	if (!outFile.is_open()) {
		std::cerr << "Error opening the file" << std::endl;
	}
	outFile << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
	outFile << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
	outFile << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
	outFile << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
	outFile << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
	outFile << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
	outFile << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
	outFile << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
	outFile << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
	outFile << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
	outFile << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
	outFile << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
	outFile << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
	outFile << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
	outFile << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
	outFile << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
	outFile << "             {/{\\{\\{\\/}/}{\\{\\}/}" << std::endl;
	outFile << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
	outFile << "              (_)  \\.-'.-/" << std::endl;
	outFile << "          __...--- |'-.-'| --...__" << std::endl;
	outFile << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
	outFile << " -\"    ' .  . '    |.'-._| '  . .  '      " << std::endl;
	outFile << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
	outFile << "          ' ..     |'-_.-|" << std::endl;
	outFile << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
	outFile << "              .'   |'- .-|   '." << std::endl;
	outFile << "  ..-'   ' .  '.   `-._.-´   .'  '  - ." << std::endl;
	outFile << "   .-' '        '-._______.-'     ' " << std::endl;
}

