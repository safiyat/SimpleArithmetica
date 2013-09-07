#include "CalcWindow.h"
#include "ui_CalcWindow.h"

CalcWindow::CalcWindow(QWidget *parent) : QDialog(parent), ui(new Ui::CalcWindow)
{
	ui->setupUi(this);
	QDoubleValidator *val = new QDoubleValidator(-3.4e38, +3.4e38, 10, this);
	ui->num1Edit->setValidator(val);
	ui->num2Edit->setValidator(val);
	precision=2;
	prev=0;
//	prev_func=NULL;
}

CalcWindow::~CalcWindow()
{
	delete ui;
}

void CalcWindow::add()
{
	double res;
	QString str;

	res = (ui -> num1Edit -> text()).toDouble() + ( ui -> num2Edit -> text()).toDouble();

//	ui -> resEdit -> setText(QString::number(res));
	ui -> resEdit -> setText(str.setNum(res, 'f', precision));
	if(res==0)
		return;
	if(ui->listWidget->count()!=0)
		if(QString::compare(ui->listWidget->item(0)->text(), str, Qt::CaseInsensitive)==0)
			return;
	ui -> listWidget->insertItem(0, str);
//	prev_func=add;
	prev=1;

}

void CalcWindow::sub()
{
	double res;
	QString str;

	res = (ui -> num1Edit -> text()).toDouble() - ( ui -> num2Edit -> text()).toDouble();

//	ui -> resEdit -> setText(QString::number(res));
	ui -> resEdit -> setText(str.setNum(res, 'f', precision));
	if(res==0)
		return;
	if(ui->listWidget->count()!=0)
		if(QString::compare(ui->listWidget->item(0)->text(), str, Qt::CaseInsensitive)==0)
			return;
	ui -> listWidget->insertItem(0, str);
//	prev_func=sub;
	prev=2;
}

void CalcWindow::mul()
{
	double res;
	QString str;

	res = (ui -> num1Edit -> text()).toDouble() * ( ui -> num2Edit -> text()).toDouble();

//	ui -> resEdit -> setText(QString::number(res));
	ui -> resEdit -> setText(str.setNum(res, 'f', precision));
	if(res==0)
		return;
	if(ui->listWidget->count()!=0)
		if(QString::compare(ui->listWidget->item(0)->text(), str, Qt::CaseInsensitive)==0)
			return;
	ui -> listWidget->insertItem(0, str);
//	prev_func=mul;
	prev=3;
}

void CalcWindow::div()
{
	double res;
	QString str;

	if(( ui -> num2Edit -> text()).toDouble() == 0)
	{
		ui -> resEdit -> setText("DIVIDE BY ZERO ERROR  ");
		return;
	}
	res = (ui -> num1Edit -> text()).toDouble() / ( ui -> num2Edit -> text()).toDouble();

//	ui -> resEdit -> setText(QString::number(res));
	ui -> resEdit -> setText(str.setNum(res, 'f', precision));
	if(res==0)
		return;
	if(ui->listWidget->count()!=0)
		if(QString::compare(ui->listWidget->item(0)->text(), str, Qt::CaseInsensitive)==0)
			return;
	ui -> listWidget->insertItem(0, str);
//	prev_func=div;
	prev=4;
}

void CalcWindow::clr()
{
	if((((ui -> num1Edit -> text()).toDouble())==0) && (((ui -> num2Edit -> text()).toDouble())==0))
		ui -> resEdit -> clear();
	ui -> num1Edit -> clear();
	ui -> num2Edit -> clear();
	prev=0;
}

void CalcWindow::prec()
{
	precision = ui -> preSpinBox -> value();
//	*prev_func();
	if(prev==1)
		CalcWindow::add();
	else if(prev==2)
		CalcWindow::sub();
	else if(prev==3)
		CalcWindow::mul();
	else if(prev==4)
		CalcWindow::div();
}

void CalcWindow::setIp1()
{
	if(ui->listWidget->selectedItems().count())
		ui->num1Edit->setText(ui->listWidget->selectedItems().first()->text());
}

void CalcWindow::setIp2()
{
	if(ui->listWidget->selectedItems().count())
		ui->num2Edit->setText(ui->listWidget->selectedItems().first()->text());
}
