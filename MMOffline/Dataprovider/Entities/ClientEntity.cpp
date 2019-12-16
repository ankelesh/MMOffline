#include "ClientEntity.h"
#include <QVariant>
#include <QWidget>

uniform_json_object_representation ClientEntity::toJsonRepresentation() const
{
	return uniform_json_object_representation(
		QStringList{ "id", "name" },
		QStringList{ QString::number(id), name }
	);
}

bool ClientEntity::fromJsonRepr(const uniform_json_object_representation& o)
{
	QString t = o.value(QLatin1String("id"));
	bool ok;
	int tmp = t.toInt(&ok);
	if (ok)
	{
		id = tmp;
	}
	else
		return false;
	name = o.value(QLatin1String("name"));
	if (name.isNull())
		return false;
	return true;
}

TemplatedTableHandler* ClientEntity::getAssocTable() const
{
	return predefinedTables + Clients;
}


QString ClientEntity::getContentsForDb() const
{
	return QStringLiteral("( ") + QString::number(id) + QStringLiteral(" , \"") + name + QStringLiteral("\" )");
}

abs_entity* ClientEntity::fabricate() const
{
	return new ClientEntity(id, name);
}

ClientEntity::ClientEntity()
	:abs_entity(Clients)
{
}

ClientEntity::ClientEntity(int Id, QString Name)
	: abs_entity(Clients), id(Id), name(Name)
{

}


bool ClientEntity::fromSql(QueryPtr q)
{
	if (!q->next())
		return false;
	bool ok;
	QVariant temp(q->value(0));
	if (!temp.isValid())
		return false;
	id = temp.toInt(&ok);
	if (!ok)
		return false;
	temp = q->value(1);
	if (!temp.isValid())
		return false;
	name = temp.toString();
	return true;
}

ClientDataModel::ClientDataModel(QWidget* parent)
	: QAbstractListModel(parent)
{
}

ClientDataModel::ClientDataModel(const ClientList& clients, QWidget* parent)
	: QAbstractListModel(parent), innerList(clients)
{

}

int ClientDataModel::rowCount(const QModelIndex& parent) const
{
	return innerList.count();
}

QVariant ClientDataModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();
	if (index.row() >= rowCount())
		return QVariant();
	if (role == Qt::DisplayRole)
	{
		QVariant temp;
		temp.setValue<Client>(innerList.at(index.row()));
		return temp;
	}
	return QVariant();
}

QVariant ClientDataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	return QVariant();
}

void ClientDataModel::setList(ClientList l)
{
	innerList.clear();
	innerList << l;
}
