#pragma once
#include <QtWidgets/qboxlayout.h>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QtWidgets/QFormLayout>
#include "Widgets/ElementWidgets/MegaIconButton.h"
#include "Widgets/ElementWidgets/BigButtonsSpinbox.h"
#include "Widgets/parents/inframedWidget.h"
#include "Dataprovider/DataEntities.h"

class DocumentCreationScreen : public inframedWidget
{
	Q_OBJECT
protected:
	QVBoxLayout* mainLayout;
	QLabel* clientInfo;
	QFormLayout* formLayout;
	QLabel* idInfo;
	BigButtonsSpinbox* dateSpinBox;
	QComboBox* depozitField;
	QComboBox* tipField;
	QLineEdit* contactField;
	BigButtonsSpinbox* summPaidField;
	QHBoxLayout* buttonLayout;
	MegaIconButton* backButton;
	MegaIconButton* okButton;

	NamedIdList depozits;
	NamedIdList tips;

	Document currentDocument;
public:
	DocumentCreationScreen(QWidget*);
	void primeCreation(Client);
	virtual void show() override;
protected slots:
	void okPressed();
signals:
	void documentCreated(Document);
};