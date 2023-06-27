/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <connectionhandler.h>
#include <devicefinder.h>
#include <devicehandler.h>

#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif

Q_QMLTYPE_EXPORT void qml_register_types_Shared()
{
    QMetaType::fromType<BluetoothBaseClass *>().id();
    qmlRegisterTypesAndRevisions<ConnectionHandler>("Shared", 1);
    qmlRegisterTypesAndRevisions<DeviceFinder>("Shared", 1);
    qmlRegisterTypesAndRevisions<DeviceHandler>("Shared", 1);
    qmlRegisterModule("Shared", 1, 0);
}

static const QQmlModuleRegistration registration("Shared", qml_register_types_Shared);
