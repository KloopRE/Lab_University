#include "iostream"
#include "locale.h"
#include "windows.h"
#include <conio.h>
#include <math.h>
using namespace std;

class Time
{
private:
	int sec = 0, mins = 0, hr = 0;
	char cch = ':';
public:
	Time() : sec(0), mins(0), hr(0), cch(':')
	{}
	Time(int s, int m, int h, char c) : sec(s), mins(m), hr(h), cch(c)
	{}
	void gettime()
	{
	
		
		do {
			cout << "Введите значение времени 23:59:59: ";
			cin >> hr >> mins >> sec;
		} while (hr > 23 || mins > 59 || sec > 59);
	}
	void showtime() const
	{
		cout << hr << ":" << mins << ":" << sec << endl;
	}

	Time operator+ (Time t1) const
	{
		int ss = sec + t1.sec;
		int mm = mins + t1.mins;
		int hh = hr + t1.hr;

		if (ss > 59)
		{
			ss = ss - 60;
			mm++;
		}
		if (mm > 59)
		{
			mm = mm - 60;
			hh++;
		}
		if (hh > 23)
		{
			hh = hh - 24;
			hh++;
		}
		return Time(ss, mm, hh, ':');
	}
	Time operator- (Time t1) const
	{
		int ss = sec - t1.sec;
		int mm = mins - t1.mins;
		int hh = hr - t1.hr;
		if (ss < 0)
		{
			ss = 60 + ss;
			mm--;
		}
		if (mm < 0)
		{
			mm = 60 + mm;
			hh--;
		}
		if (hh < 0)
		{
			hh = 24 + hh;
		}
		return Time(ss, mm, hh, ':');
	}
	Time operator* (Time t1) const
	{
		
		
		int hh = hr;
		int mm = mins + hh * 60;
		int ss = sec + mm * 60;

		ss = ss * t1.sec + ss * t1.mins + ss * t1.hr;
		while (ss > 3600 * 23)
		{
			ss = ss - 3600 * 23;
		}
		while (ss > 3600)
		{
			ss = ss - 3600;
			hh++;
		}
		while (ss > 60)
		{
			ss = ss - 60;
			mm++;
		}
		while (mm > 60)
		{
			mm = mm - 60;
			hh++;
		}
		while (hh > 23)
		{
			hh = hh - 23;
		}
		return Time(ss, mm, hh, ':');
	}
};




class time12 {
	private:
	int hour, min, sec;
	bool pm = 0;
	char ch = ':';
public:
	
	void settime12() {
		while(hour > 23 || min > 60 || sec > 60 || hour < 0 || min < 0 || sec < 0) {
			cout << "Введите время, через пробел: ";
			cin >> hour >> min >> sec;
		}
		if (sec >= 60)
		{
			min++;
			sec = 0;
		}
		if (min >= 60)
		{
			hour++;
			min = 0;
		}
		if (hour > 23)
		{
			hour = 0;
			min = 0;
				sec = 0;
		}
		
		
		if (hour > 12) { pm = 1; hour = hour - 12; cout << hour << ch << min << ch << sec << " После полудня" << endl; }
		else { pm = 0; cout << hour << ch << min << ch << sec <<" До полудня" << endl;
		}
		
		}

	void time12v24()
	{
		
		if (pm == 1) {
			cout << "Результат преобразования " << hour << ch << min << ch << sec << " После полудня, в гражданский формат: " << endl;
			hour = hour + 12; cout << hour << ch << min << ch << sec << endl;
		}
		else { cout << "Результат преобразования " << hour << ch << min << ch << sec << " До полудня, в военный формат: " << endl; cout << hour << ch << min << ch << sec << endl; }
	}
};

class time24 {
private:
	int hour, min, sec;
	bool pm = 0;
	char ch = ':';
public:

	void settime12() {
		while (hour > 23 || min > 60 || sec > 60 || hour < 0 || min < 0 || sec < 0) {
			cout << "Введите время, через пробел: ";
			cin >> hour >> min >> sec;
		}
		if (sec >= 60)
		{
			min++;
			sec = 0;
		}
		if (min >= 60)
		{
			hour++;
			min = 0;
		}
		if (hour > 23)
		{
			hour = 0;
			min = 0;
			sec = 0;
		}


		cout << hour << ch << min << ch << sec << endl;
	}
	void time24v12()
	{

		if (hour > 12) {
			cout << "Результат преобразования " << hour << ch << min << ch << sec << endl;
			hour = hour - 12; cout << hour << ch << min << ch << sec << " После полудня" << endl;
		}
		else {
			cout << "Результат преобразования " << hour << ch << min << ch << sec << endl;
		    cout << hour << ch << min << ch << sec << " До полудня" << endl;
		}
	}
};


void main(){
	setlocale(LC_ALL, "Russian");
	Time time1, time2, time3, time4, time5;
	time1.gettime();
	time2.gettime();
	time1.showtime();
	time2.showtime();
	time3 = time1 + time2;
	time3.showtime();
	time4 = time1 - time2;
	time4.showtime();
	time5 = time1 * time2;
	time5.showtime();
	time12 t12;
	time24 t24;
	t12.settime12();
	t12.time12v24();
	t24.settime12();
	t24.time24v12();
}