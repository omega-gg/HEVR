//=================================================================================================
/*
    Copyright (C) 2015-2020 HEVR authors. <http://omega.gg/HEVR>

    Author: Benjamin Arnaud. <http://bunjee.me> <bunjee@omega.gg>

    This file is part of HEVR.

    - GNU Lesser General Public License Usage:
    This file may be used under the terms of the GNU Lesser General Public License version 3 as
    published by the Free Software Foundation and appearing in the LICENSE.md file included in the
    packaging of this file. Please review the following information to ensure the GNU Lesser
    General Public License requirements will be met: https://www.gnu.org/licenses/lgpl.html.
*/
//=================================================================================================

#include "VDataLocal.h"

// Qt includes
#include <qtlockedfile>

// Sk includes
#include <WControllerFile>

// Private includes
#include "VDataLocal_p.h"

// Namespaces
using namespace QtLP_Private;

//=================================================================================================
// VDataLocalWrite
//=================================================================================================

class VDataLocalWrite : public WAbstractThreadAction
{
    Q_OBJECT

public:
    VDataLocalWrite(VDataLocalPrivate * data)
    {
        this->data = data;
    }

protected: // WAbstractThreadAction implementation
    /* virtual */ bool run();

public: // Variables
    VDataLocalPrivate * data;

    QString path;
};

//-------------------------------------------------------------------------------------------------

/* virtual */ bool VDataLocalWrite::run()
{
    QtLockedFile file(path);

    if (WControllerFile::tryUnlock(file) == false)
    {
        qWarning("VDataLocalWrite::run: File is locked %s.", path.C_STR);

        return false;
    }

    if (file.open(QIODevice::WriteOnly) == false)
    {
        qWarning("VDataLocalWrite::run: Failed to open file %s.", path.C_STR);

        return false;
    }

    file.lock(QtLockedFile::ReadLock);

    file.unlock();

    return true;
}

//=================================================================================================
// VDataLocalRead and VDataLocalReadReply
//=================================================================================================

class VDataLocalRead : public VDataLocalWrite
{
    Q_OBJECT

public:
    VDataLocalRead(VDataLocalPrivate * data) : VDataLocalWrite(data) {}

protected: // VDataLocalWrite reimplementation
    /* virtual */ WAbstractThreadReply * createReply() const;

protected: // VDataLocalWrite reimplementation
    /* virtual */ bool run();
};

//-------------------------------------------------------------------------------------------------

class VDataLocalReadReply : public WAbstractThreadReply
{
    Q_OBJECT

public:
    VDataLocalReadReply(VDataLocalPrivate * data)
    {
        this->data = data;
    }

protected: // WAbstractThreadReply reimplementation
    /* virtual */ void onCompleted(bool ok);

public: // Variables
    VDataLocalPrivate * data;
};

//=================================================================================================
// VDataLocalRead
//=================================================================================================

/* virtual */ WAbstractThreadReply * VDataLocalRead::createReply() const
{
    return new VDataLocalReadReply(data);
}

/* virtual */ bool VDataLocalRead::run()
{
    QtLockedFile file(path);

    if (WControllerFile::tryUnlock(file) == false)
    {
        qWarning("VDataLocalRead::run: File is locked %s.", path.C_STR);

        return false;
    }

    if (file.open(QIODevice::ReadOnly) == false)
    {
        qWarning("VDataLocalRead::run: Failed to open file %s.", path.C_STR);

        return false;
    }

    VDataLocalReadReply * reply = qobject_cast<VDataLocalReadReply *> (this->reply());

    file.lock(QtLockedFile::ReadLock);

    file.unlock();

    return true;
}

//=================================================================================================
// VDataLocalReadReply
//=================================================================================================

/* virtual */ void VDataLocalReadReply::onCompleted(bool ok)
{
    data->setLoaded(ok);
}

//=================================================================================================
// VDataLocalPrivate
//=================================================================================================

VDataLocalPrivate::VDataLocalPrivate(VDataLocal * p) : WLocalObjectPrivate(p) {}

void VDataLocalPrivate::init() {}

//=================================================================================================
// VDataLocal
//=================================================================================================

/* explicit */ VDataLocal::VDataLocal(QObject * parent)
    : WLocalObject(new VDataLocalPrivate(this), parent)
{
    Q_D(VDataLocal); d->init();
}

//-------------------------------------------------------------------------------------------------
// WLocalObject reimplementation
//-------------------------------------------------------------------------------------------------

/* Q_INVOKABLE virtual */ QString VDataLocal::getFilePath() const
{
    return getParentPath() + "/data.xml";
}

//-------------------------------------------------------------------------------------------------
// Protected WLocalObject reimplementation
//-------------------------------------------------------------------------------------------------

/* virtual */ WAbstractThreadAction * VDataLocal::onSave(const QString & path)
{
    Q_D(VDataLocal);

    VDataLocalWrite * action = new VDataLocalWrite(d);

    action->path = path;

    return action;
}

/* virtual */ WAbstractThreadAction * VDataLocal::onLoad(const QString & path)
{
    Q_D(VDataLocal);

    VDataLocalRead * action = new VDataLocalRead(d);

    action->path = path;

    return action;
}
