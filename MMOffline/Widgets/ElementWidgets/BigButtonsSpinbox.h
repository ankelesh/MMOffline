#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qdatetimeedit.h>
#include <QtWidgets/qgridlayout.h>
#include <QtWidgets/QLabel>
#include "widgets/utils/EventsAndFilters.h"
#include "QtWidgets/qdatetimeedit.h"
/*
	This class is a wrapper for any normal spinBox, providing it with big and suitable
	buttons for steps. For specifying which spinbox is added into it->check spintype.
	It uses RTTI for connecting to corresponding slots, so you must alter this class to add
	new spinbox type in it. Now supported: SpinBox, DatetimeEdit and all their inheritors.

	Update:
		Now Keyfilter is filtering input to get back presses. Signal backRequired is emitted
		on <- key.
*/

class BigButtonsSpinbox : public QWidget
	//	Spinbox with two GIANT buttons which are replacing it's original
{
	Q_OBJECT
public:
	enum spintype { intspin, timespin, floatspin, datespin };	//	Used to determine which type of spinbox is wrapped

private:
	QGridLayout* mainLayout;			//	View
	QPushButton* buttonUp;
	QPushButton* buttonDown;
	QAbstractSpinBox* coreSpinbox;	//	Abstract spinbox allows to place here any spinbox
	filters::CaptureBackFilter* keyFilter;		//	Captures back press

	spintype sptype;				//	Stores type for correct usage of inner functions

	virtual void showEvent(QShowEvent*) override;
public:
	BigButtonsSpinbox(spintype type, QWidget* parent, double adaptH = 0.125);
	//	methods of QSpinBox interface
	void setMinimum(int min);	// sets maximum
	void setMaximum(int max);	// sets minimum
	void setValue(int val);		//	sets current value
	void setDValue(double val);
	int value() const;				//	returns current value
	double dvalue() const;
	void setPrecision(int prec);
	//	methods of QTimeEdit interface
	void setTime(const QTime& tm);	//	sets current value
	QTime time();			//	returns current value
	void setDisplayFormat(const QString& tf);//	sets format
	bool hasFocus() const;
	void setInfo(QString&);
	// methods of QDateEdit
	QDate date();
	void clear();
	void setDate(QDate time = QDate::currentDate());
private slots:
	void intValueChanged(int);				//	These slots are wrapping slots of inner spinbox
	void timeValueChanged(const QTime& t);
	void doubleValueChanged(double);
	void editingDone();
	void backRequire();
	void dateChanged(const QDate&);
public slots:
	void setFocus() const;			//	Sets focus to spinbox

signals:
	void ivalueChanged(int);			//	emitted only when SpinBox is wrapped
	void timeChanged(const QTime& t);	//	emitted only when TimeEdit is wrapped
	void valueChanged(QString);
	void dateValueChanged(const QDate& d);
	void dvalueChanged(double);
	void returnPressed();				//	return was pressed
	void backRequired();				//	back was pressed
};
