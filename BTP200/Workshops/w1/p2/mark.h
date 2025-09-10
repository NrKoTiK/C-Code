#ifndef SENECA_MARK_H
#define SENECA_MARK_H

namespace seneca 
{
	/// <summary>
	/// Record of a mark received by a student.
	/// </summary>
	struct Mark
	{
		/// <summary>
		/// The first name of the student.
		/// </summary>
		char m_firstName[20 + 1];
		/// <summary>
		/// The last name of the student.
		/// </summary>
		char m_lastName[30 + 1];
		/// <summary>
		/// The mark the student received (as a number between 0 and 100).
		/// </summary>
		int m_mark;
	};
	/// <summary>
	/// prints report with graph for comparison of marks
	/// </summary>
	/// <param name="filename">takes input a .csv file</param>
	/// <returns></returns>
	bool printReport(const char* filename);
	
	/// <summary>
	/// sorts marks from greatest to least. 
	/// </summary>
	/// <param name="marks">takes struct as parameter</param>
	void markSort(Mark marks[], int count);
	
}
#endif
