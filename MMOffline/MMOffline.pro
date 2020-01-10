# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = UNAOrders
CONFIG += release
LIBS += -L"."
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += .
TRANSLATIONS += mmoffline_ru.ts \
    mmoffline_en.ts \
    mmoffline_ro.ts
HEADERS += ./Widgets/LogBranch/DocumentEntrySelectionSubbranch.h \
    ./MMOffline.h \
    ./Widgets/parents/abstractNodeInterface.h \
    ./Widgets/parents/inframedWidget.h \
    ./Widgets/parents/AbstractVariantSelectionWidget.h \
    ./Widgets/parents/AbstractListSelectionWidget.h \
    ./Widgets/parents/AbstractCheckboxSelection.h \
    ./Widgets/ElementWidgets/ZebraListItemDelegate.h \
    ./Widgets/utils/SpecializedWidgets.h \
    ./Widgets/ElementWidgets/ProcessingOverlay.h \
    ./Widgets/ElementWidgets/MegaIconButton.h \
    ./Widgets/ElementWidgets/BigButtonsSpinbox.h \
    ./Widgets/ModeDefining/OnlineLoginWidget.h \
    ./Widgets/ModeDefining/StartingScreen.h \
    ./Widgets/ModeDefining/SettingsScreen.h \
    ./Widgets/MultibranchWidgets/GroupSelectionWidget.h \
    ./Widgets/MultibranchWidgets/ProductSelectionWidget.h \
    ./Widgets/MultibranchWidgets/DocumentSelectionWidget.h \
    ./Widgets/LogBranch/LogBranchRoot.h \
    ./Widgets/LogBranch/LogsWidget.h \
    ./Widgets/Syncing/SyncMenuWidget.h \
    ./Widgets/Syncing/SyncInfoWidget.h \
    ./Widgets/DocumentBranch/DocumentRootWidget.h \
    ./Widgets/DocumentBranch/ClientSelectionWidget.h \
    ./Widgets/DocumentBranch/DocumentCreationScreen.h \
    ./Widgets/DocumentBranch/EntryCreationScreen.h \
    ./Widgets/ExtendedDelegates/DelegateUtility.h \
    ./Widgets/ExtendedDelegates/ClientsDelegate.h \
    ./Widgets/ExtendedDelegates/ProductsDelegate.h \
    ./Widgets/ExtendedDelegates/GroupDelegate.h \
    ./Widgets/ExtendedDelegates/DocumentsDelegate.h \
    ./Widgets/ExtendedDelegates/EntryDelegate.h \
    ./Networking/queryTemplates.h \
    ./Networking/RequestAwaiter.h \
    ./Networking/dataupdateengine-http.h \
    ./Networking/dataupdateengine.h \
    ./Networking/Parsers/abs_parser.h \
    ./Networking/Parsers/ErrorParser.h \
    ./Networking/Parsers/JsonUniresult.h \
    ./Networking/Parsers/RequestParser.h \
    ./Networking/Parsers/LinearParser.h \
    ./debugtrace.h \
    ./Widgets/utils/ApplicationDataWorkset.h \
    ./Widgets/utils/ElementsStyles.h \
    ./Widgets/utils/GlobalAppSettings.h \
    ./Widgets/utils/EventsAndFilters.h \
    ./Dataprovider/IdGenerator.h \
    ./Dataprovider/SqliteDataProvider.h \
    ./Dataprovider/TableHandlers.h \
    ./Dataprovider/Entities/abs_entity.h \
    ./Dataprovider/Entities/DocumentEntryEntity.h \
    ./Dataprovider/Entities/FieldTablesPredefines.h \
    ./Dataprovider/Entities/NamedIdEntity.h \
    ./Dataprovider/Entities/ProductEntity.h \
    ./Dataprovider/DataEntities.h \
    ./Dataprovider/Entities/ClientEntity.h \
    ./Dataprovider/Entities/DocumentEntity.h \
    ./Dataprovider/Entities/GroupEntity.h \
    ./Widgets/MultibranchWidgets/ProductSelectionBranch.h
SOURCES += ./main.cpp \
    ./MMOffline.cpp \
    ./Widgets/ExtendedDelegates/DocumentsDelegate.cpp \
    ./Widgets/ExtendedDelegates/EntryDelegate.cpp \
    ./Widgets/MultibranchWidgets/DocumentSelectionWidget.cpp \
    ./Widgets/ElementWidgets/BigButtonsSpinbox.cpp \
    ./Widgets/ElementWidgets/MegaIconButton.cpp \
    ./Widgets/ElementWidgets/ProcessingOverlay.cpp \
    ./Widgets/ElementWidgets/ZebraListItemDelegate.cpp \
    ./Widgets/utils/SpecializedWidgets.cpp \
    ./Widgets/parents/AbstractCheckboxSelection.cpp \
    ./Widgets/parents/AbstractListSelectionWidget.cpp \
    ./Widgets/parents/abstractNodeInterface.cpp \
    ./Widgets/parents/AbstractVariantSelectionWidget.cpp \
    ./Widgets/parents/inframedWidget.cpp \
    ./Widgets/ModeDefining/OnlineLoginWidget.cpp \
    ./Widgets/ModeDefining/SettingsScreen.cpp \
    ./Widgets/ModeDefining/StartingScreen.cpp \
    ./Widgets/LogBranch/LogBranchRoot.cpp \
    ./Widgets/LogBranch/LogsWidget.cpp \
    ./Widgets/DocumentBranch/ClientSelectionWidget.cpp \
    ./Widgets/MultibranchWidgets/GroupSelectionWidget.cpp \
    ./Widgets/MultibranchWidgets/ProductSelectionWidget.cpp \
    ./Widgets/Syncing/SyncInfoWidget.cpp \
    ./Widgets/Syncing/SyncMenuWidget.cpp \
    ./Widgets/ExtendedDelegates/ClientsDelegate.cpp \
    ./Widgets/ExtendedDelegates/GroupDelegate.cpp \
    ./Widgets/ExtendedDelegates/ProductsDelegate.cpp \
    ./Widgets/DocumentBranch/DocumentCreationScreen.cpp \
    ./Widgets/DocumentBranch/DocumentRootWidget.cpp \
    ./Widgets/DocumentBranch/EntryCreationScreen.cpp \
    ./Networking/dataupdateengine-http.cpp \
    ./Networking/dataupdateengine.cpp \
    ./Networking/Parsers/JsonUniresult.cpp \
    ./Networking/RequestAwaiter.cpp \
    ./Networking/Parsers/abs_parser.cpp \
    ./Networking/Parsers/ErrorParser.cpp \
    ./Networking/Parsers/LinearParser.cpp \
    ./debugtrace.cpp \
    ./Widgets/utils/ApplicationDataWorkset.cpp \
    ./Widgets/utils/ElementsStyles.cpp \
    ./Widgets/utils/EventsAndFilters.cpp \
    ./Widgets/utils/GlobalAppSettings.cpp \
    ./Dataprovider/IdGenerator.cpp \
    ./Dataprovider/SqliteDataProvider.cpp \
    ./Dataprovider/TableHandlers.cpp \
    ./Networking/queryTemplates.cpp \
    ./Dataprovider/DataEntities.cpp \
    ./Dataprovider/Entities/abs_entity.cpp \
    ./Dataprovider/Entities/ClientEntity.cpp \
    ./Dataprovider/Entities/DocumentEntity.cpp \
    ./Dataprovider/Entities/DocumentEntryEntity.cpp \
    ./Dataprovider/Entities/FieldTablesPredefines.cpp \
    ./Dataprovider/Entities/GroupEntity.cpp \
    ./Dataprovider/Entities/NamedIdEntity.cpp \
    ./Dataprovider/Entities/ProductEntity.cpp \
    ./Widgets/LogBranch/DocumentEntrySelectionSubbranch.cpp \
    ./Widgets/MultibranchWidgets/ProductSelectionBranch.cpp
RESOURCES += MMOffline.qrc