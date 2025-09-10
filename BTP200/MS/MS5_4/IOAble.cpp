//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 4/2/2024
#include <iostream>
#include "IOAble.h"

namespace seneca
{

	IOAble::~IOAble()
	{
	}
	std::ostream& operator<<(std::ostream& out, const IOAble& IO_obj)
	{
		return IO_obj.write(out);
	}
	std::istream& operator>>(std::istream& in, IOAble& IO_obj)
	{
		return IO_obj.read(in);
	}
}