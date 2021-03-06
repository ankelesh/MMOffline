#include "EntryDelegate.h"
#include "Dataprovider/DataEntities.h"
#include "DelegateUtility.h"
#include <QtGui/QPainter>
#include <cmath>

void EntryDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	DocumentEntry d = upcastItem<DocumentEntryEntity>(index);
	if (d == nullptr)
		return;

	// painting begins
	painter->save();

	// drawing first textbox for price
	QRect textbox(
		QPoint(
			option.rect.bottomLeft().x(), option.rect.bottomLeft().y() - ((option.fontMetrics.height() + 6)))
		, QSize(
		(option.rect.width() * 0.333333333), option.fontMetrics.height() + 7));
	painter->setPen(Qt::PenStyle::SolidLine);
	drawRect(textbox, bright_delegate_color, painter);
	painter->drawText(textbox, Qt::AlignCenter, tr("Price:") + QString::number(d->price));

	// drawing second textbox for quantity
	textbox.setTopLeft(textbox.topRight());
	textbox.setBottomRight(QPoint(
		option.rect.topLeft().x() + (option.rect.width() * 0.66666666),
		option.rect.bottomLeft().y()
	));
	drawRect(textbox, bright_delegate_color, painter);
	painter->drawText(textbox, Qt::AlignCenter, tr("Quantity:") + QString::number(d->quantity));

	// drawing third textbox for total price of all entry
	textbox.setTopLeft(textbox.topRight());
	textbox.setBottomRight(option.rect.bottomRight());
	drawRect(textbox, bright_delegate_color, painter);
	painter->drawText(textbox, Qt::AlignCenter, /*tr("Summ:") +*/ QString::number(d->quantity * d->price, 'g', 4));

	// drawing flexible square for product name
	textbox.setTopLeft(option.rect.topLeft());
	textbox.setBottomRight(QPoint(option.rect.bottomRight().x(), option.rect.bottomRight().y() - ((option.fontMetrics.height() + 6))));

	drawRect(textbox, dark_delegate_color, painter);
	painter->drawText(textbox, Qt::TextWordWrap | Qt::AlignCenter, d->productName);

	// drawing selection box
	if (option.state.testFlag(QStyle::State_Selected))
	{
		painter->setBrush(option.palette.highlight());
		painter->setOpacity(0.4);
		painter->drawRect(option.rect);
	}
	painter->restore();
}

QSize EntryDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	// final size is 1 * font height + enough space to wrap product name
	DocumentEntry d = upcastItem<DocumentEntryEntity>(index);
	if (d == nullptr)
		return QSize(100, 50);
	double wdth = option.fontMetrics.averageCharWidth() * (d->productName.length() + 8);
	int tabs = 0;
	if (option.rect.width() == 0)
	{
		tabs = wdth;
	}
	else
		tabs = std::ceil(wdth / option.rect.width());
	tabs = (tabs > 1) ? tabs : 2;
	double t = (tabs + 1) * (option.fontMetrics.height() + 2);
	return QSize(option.rect.width(), t);
}