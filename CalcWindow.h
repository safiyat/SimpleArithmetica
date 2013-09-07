#ifndef CALCWINDOW_H
#define CALCWINDOW_H

#include <QDialog>

namespace Ui {
	class CalcWindow;
}

class CalcWindow : public QDialog
{
		Q_OBJECT
		
	public:
		explicit CalcWindow(QWidget *parent = 0);
		~CalcWindow();

	private slots:
		void add();
		void sub();
		void mul();
		void div();
		void clr();
		void prec();
		void setIp1();
		void setIp2();
		
	private:
		Ui::CalcWindow *ui;
		int precision, prev;
//		void (*prev_func)();
};

#endif // CALCWINDOW_H
