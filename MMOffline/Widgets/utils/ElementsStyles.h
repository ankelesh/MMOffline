#pragma once
#include <QtWidgets/QApplication>
#include <QtWidgets/qdesktopwidget.h>
#define GEOMETRY_SOURCE qApp->screens().first()
#include <QtGui/QScreen>
#include <QString>

/*
	This file contains constants which are defining buttons stylesheets as a C-strings. all
	new styles must be added ONLY here to allow quick change if necessary.
	Naming: \state\_\element\_STYLESHEET

	Update:
		Now this file also stores additional inline functions for calculating adaptive sizes
		of interface elements. Their defaults are usually correspond most used values.
	Update:
		now theese functions are using actual screen size API instead of deprecated desktop()
*/

//These functions are used to calculate size in percent of all window

inline static int calculateAdaptiveButtonHeight(double percent = 0.125)
//Calculates height for buttons, by default is giving 12.5% of screen height
{
	return GEOMETRY_SOURCE->availableGeometry().height() * percent;
}

inline static int calculateAdaptiveWidth(double percent = 0.5)
//Calculates width, by default is giving 50% of screen width
{
	return GEOMETRY_SOURCE->availableGeometry().width() * percent;
}
inline static QSize calculateAdaptiveSize(double percent = 0.3)
//Calculates square size, by default is giving 30% of screen dimensions
{
	return QSize(
		GEOMETRY_SOURCE->availableGeometry().width() * percent,
		GEOMETRY_SOURCE->availableGeometry().height() * percent
	);
}
inline static QSize calculateAdaptiveSize(double Hpercent, double Wpercent)
//Calculates more adaptive size, allowing to scale both dimensions. No defaults.
{
	return QSize(
		GEOMETRY_SOURCE->availableGeometry().width() * Wpercent,
		GEOMETRY_SOURCE->availableGeometry().height() * Hpercent
	);
}

inline static QSize imitatePhoneSize(double HPercent)
// sets window size in vertical projection using screen height
{
	return QSize(
		GEOMETRY_SOURCE->availableGeometry().height() * (HPercent * 0.66),
		GEOMETRY_SOURCE->availableGeometry().height() * HPercent
	);
}

class FontAdapter
	// creates scaled fonts
{
	int minheight;		//	minimum height of letter
	int maxheight;		//	maximum height of letter
	double minimumFontPercent;	// default font percent, which used to create original scaling
	static FontAdapter* _instance;
public:
	FontAdapter(int minheight, int maxheight, double minimumFontPercent);
	const FontAdapter* instance() {
		return _instance;
	};
	// creates scaled font by using adapter. Extra percents are relational to calculated minheight
	static QFont makeFont(double extrapercents);
};

// asserts value, creating gradient stylesheet which are curr * max/100 percents between two colors
QString makeGradientStylesheet(const QColor& first, const QColor& second, int max, int curr);

// better use wordWrap, this meant only for QPushButtons with too long names
QString& normalizeLine(QString& line, int maxSymb);

// old call for FontAdapter::makeFont
QFont makeFont(double perc);

extern const QString OK_BUTTONS_STYLESHEET;
// All buttons which are made for confirmation (commit button is separated from simple confirm)

extern const QString BACK_BUTTONS_STYLESHEET;
// Back buttons must be same-styled through all application

extern const QString COMMIT_BUTTONS_STYLESHEET;
// Commit is more saturated

extern const QString DELETE_BUTTONS_STYLESHEET;
// Delete buttons must have this style and provide a warning messagebox

extern const QString CHANGE_BUTTONS_STYLESHEET;
// All buttons which are allowing to change barcode must be same-styled so the user always knew it's functuon by color

extern const QString CHECKED_BUTTONS_STYLESHEET;
// This style is specified to checked state of toggled buttons. use it for settings flags

extern const QString UP_SPINBOX_STYLESHEET;
// up buttons of BigButtonsSpinbox

extern const QString DOWN_SPINBOX_STYLESHEET;
// down buttons of BigButtonsSpinbox

extern const QString CANCEL_BUTTONS_STYLESHEET;
// buttons that are quitting from complex branches must use this style

extern const QString SETTINGS_BUTTONS_STYLESHEET;
// buttons which are opening settings

extern const QString NAVIGATE_BUTTONS_STYLESHEET;
// Nav buttons differ with their enhanced disabled style

extern const QString LARGE_BUTTON_STYLESHEET;
// deprecated

extern const QString BETTER_CALENDAR_STYLESHEET;
// large calendar

extern const QString ERROR_TEXT_STYLESHEET;
// red text for emergency messages

extern const QString UNCHECKED_BUTTONS_STYLESHEET;
// stylesheet for toggled buttons

// This pair of stylesheets is used in zebra-styled items
extern const QString ZEBRAEVEN_BUTTONS_STYLESHEET;
// stylesheet for even buttons
extern const QString ZEBRAODD_BUTTONS_STYLESHEET;
// stylesheet for odd buttons

extern const QString CHECKBOX_BUTTON_STYLESHEET;
// stylesheet for BIG checkboxes based on buttons

extern const QString FRAMED_LABEL_STYLESHEET;
// extra frame for labels

extern const QString DOWNLOAD_BUTTON_STYLESHEET;
// more soft colors

extern const QString UPLOAD_BUTTON_STYLESHEET;
// softer colors