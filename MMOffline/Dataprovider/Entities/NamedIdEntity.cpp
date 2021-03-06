#include "NamedIdEntity.h"

using namespace fieldPredefinitions;
uniform_json_object_representation NamedIdEntity::toJsonRepresentation() const
{
	return uniform_json_object_representation(
		fieldsOfNamedIdEntity,
		QStringList{ name, QString::number(id) }
	);
}

bool NamedIdEntity::fromJsonRepr(const uniform_json_object_representation& o)
{
	QString t = o.value(QLatin1String("id"));
	bool ok;
	int tmp = t.toLongLong(&ok);
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

TemplatedTableHandler* NamedIdEntity::getAssocTable() const
{
	return predefinedTables + NamedIds;
}

QString NamedIdEntity::getContentsForDb() const
{
	return QStringLiteral("( \"")
		+ name +
		QStringLiteral("\" , ")
		+ QString::number(id) +
		QStringLiteral(" )");
}

abs_entity* NamedIdEntity::fabricate() const
{
	return new NamedIdEntity(*this);
}

bool NamedIdEntity::fromSql(QueryPtr q)
{
	if (!q->next())
		return false;
	QVariant temp(q->value(0));
	if (!temp.isValid())
		return false;
	name = temp.toString();
	temp = q->value(1);
	bool ok;
	if (!temp.isValid())
		return false;
	id = temp.toLongLong(&ok);
	if (!ok)
		return false;
	return true;
}

bool NamedIdEntity::isLikeString(const QRegExp& qregexp) const
{
	return name.contains(qregexp.pattern(), Qt::CaseInsensitive);
}

IdInt NamedIdEntity::extractId() const
{
	return id;
}

NamedIdEntity::NamedIdEntity()
	: abs_entity(NamedIds), name(), id(0)
{
}

NamedIdEntity::NamedIdEntity(QString Name, IdInt Id)
	: abs_entity(NamedIds), name(Name), id(Id)
{
}

NamedIdEntity::NamedIdEntity(const QStringList& List)
	: abs_entity(NamedIds), name(), id(0)
{
	switch (List.count())
	{
	case 2:
		id = List.at(1).toInt();
	case 1:
		name = List.at(0);
	default:
		break;
	}
}

bool NamedIdEntity::compare(abs_entity* another) const
{
	auto temp = dynamic_cast<NamedIdEntity*>(another);
	if (temp == nullptr)
		return false;
	return id == temp->id;
}

bool NamedIdEntity::higherThan(const abs_entity* another) const
{
	return id > another->getId();
}

int findNamedId(const QString& qstr, const NamedIdList& list)
{
	for (int i = 0; i < list.count(); ++i)
	{
		if (list.at(i)->name.length() == qstr.length())
		{
			if (list.at(i)->name == qstr)
			{
				return i;
			}
		}
	}
	return -1;
}

int findNamedId(const int id, const NamedIdList& list)
{
	for (int i = 0; i < list.count(); ++i)
	{
		if (list.at(i)->id == id)
			return i;
	}
	return -1;
}