#include "DocumentSelectionWidget.h"
#include "Dataprovider/SqliteDataProvider.h"
#include "Widgets/utils/ElementsStyles.h"
#include "Widgets/ExtendedDelegates/DocumentsDelegate.h"
#include "qmessagebox.h"
#include <QScroller>


DocumentSelectionWidget::DocumentSelectionWidget(QWidget* parent)
	: mainLayout(new QVBoxLayout(this)), mainView(new QListView(this)),
	coreModel(new DataEntityListModel(this)), filterModel(new DataEntityFilterModel(this)),
	searchField(new QLineEdit(this)), buttonsLayout(new QHBoxLayout(this)),
	backButton(new MegaIconButton(this)), editButton(new MegaIconButton(this)),
	deleteButton(new MegaIconButton(this))
{
	// emplacing widgets
	this->setLayout(mainLayout);
	mainLayout->addWidget(searchField);
	mainLayout->addWidget(mainView);
	mainLayout->addLayout(buttonsLayout);
	buttonsLayout->addWidget(backButton);
	buttonsLayout->addWidget(editButton);
	buttonsLayout->addWidget(deleteButton);

	// removing margins to avoid space loss
	mainLayout->setContentsMargins(0, 0, 0, 0);
	mainLayout->setSpacing(0);
	buttonsLayout->setContentsMargins(0, 0, 0, 0);
	buttonsLayout->setSpacing(0);

	// setting up models
	coreModel->setData(AppData->loadDataAs(DataEntity(new DocumentEntity())));
	filterModel->setSourceModel(coreModel);
	filterModel->setFilterRole(DataEntityListModel::SearchRole);
	mainView->setModel(filterModel);

	// setting up buttons appearance
	backButton->setText(tr("back"));
	editButton->setText(tr("edit"));
	deleteButton->setText(tr("delete"));

	backButton->setIcon(QIcon(":/res/back.png"));
	editButton->setIcon(QIcon(":/res/pencil.png"));
	deleteButton->setIcon(QIcon(":/res/data.png"));

	backButton->setStyleSheet(BACK_BUTTONS_STYLESHEET);
	editButton->setStyleSheet(CHANGE_BUTTONS_STYLESHEET);
	deleteButton->setStyleSheet(DELETE_BUTTONS_STYLESHEET);

	// setting up view
	mainView->setItemDelegate(new DocumentsDelegate(this));
	QScroller::grabGesture(mainView, QScroller::LeftMouseButtonGesture);
	mainView->setVerticalScrollMode(QListView::ScrollPerPixel);
	
	// connecting slots
	QObject::connect(searchField, &QLineEdit::textChanged, filterModel, &DataEntityFilterModel::setFilterFixedString);
	QObject::connect(mainView, &QListView::doubleClicked, this, &DocumentSelectionWidget::handleEdit);
	QObject::connect(backButton, &MegaIconButton::clicked, this, &DocumentSelectionWidget::backRequired);
	QObject::connect(editButton, &MegaIconButton::clicked, this, &DocumentSelectionWidget::handleEdit);
	QObject::connect(deleteButton, &MegaIconButton::clicked, this, &DocumentSelectionWidget::handleDelete);
	// disabling prediction on android to allow instant search
#ifdef Q_OS_ANDROID
	searchField->setInputMethodHints(Qt::InputMethodHint::ImhNoPredictiveText);
#endif
}

void DocumentSelectionWidget::replaceDocument(Document doc)
{
	coreModel->replaceDataEntity(doc);
}

void DocumentSelectionWidget::handleEdit()
{
	if (mainView->currentIndex().isValid())
	{
		//	making copy of document to avoid unnecessary shadow changes
		Document temp =
			std::dynamic_pointer_cast<DocumentEntity>(
				mainView->currentIndex().data(DataEntityListModel::DataCopyRole).value<DataEntity>()
				);
		if (temp != nullptr)
			emit DocumentSelected(temp, 1);
	}
	searchField->clear();
	mainView->clearSelection();
}

void DocumentSelectionWidget::handleDelete()
{
	if (mainView->currentIndex().isValid())
	{
		// asking confirmation
		int userResponse = QMessageBox::information(this,
			tr("Delete document"), tr("Sure you want to delete?"),
			QMessageBox::Ok, QMessageBox::Cancel);
		if (userResponse != QMessageBox::Ok)
			return;

		Document temp =
			std::dynamic_pointer_cast<DocumentEntity>(
				filterModel->mapToSource(mainView->currentIndex()).data(DataEntityListModel::DataCopyRole).value<DataEntity>()
				);
		if (temp != nullptr)
		{
			coreModel->removeDataEntity(filterModel->mapToSource(mainView->currentIndex()));
			emit DocumentSelected(temp, 0);
		}
	}
	searchField->clear();
	mainView->clearSelection();
}