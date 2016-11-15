#ifndef _DATE_H_
#define _DATE_H_

class Date {
	public:
	
	Date(int month, int day, int year);
	void set_month(int month);
	void set_day(int day);
	void set_year(int year);
	std::string get_date_string();

	private:
	Date();

	protected:


}


#endif

