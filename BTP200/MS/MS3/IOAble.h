//Name- Syed Ahmad
//Seneca student ID- 102437233
//Seneca emai- asyed113@myseneca.ca
//Date of completion- 3/27/2024
#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H
#include <iostream>

/// <summary>
/// ADD COMMENTS TO THE FUNCTIONS FR
/// </summary>

namespace seneca 
{
	class IOAble 
	{	
	public:
		
		virtual std::ostream& write(std::ostream& out) const = 0;

		virtual std::istream& read(std::istream& in) = 0;

		virtual ~IOAble();
	};

	/// <summary>
	/// 
	/// </summary>
	/// <param name="out"></param>
	/// <param name="IO_obj"></param>
	/// <returns></returns>
	std::ostream& operator<<(std::ostream& out, const IOAble& IO_obj);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="in"></param>
	/// <param name="IO_obj"></param>
	/// <returns></returns>
	std::istream& operator>>(std::istream& in, IOAble& IO_obj);
}
#endif // !SENECA_IOABLE_H
