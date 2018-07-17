#include <QtGui>
#include <iostream>

#include "xmlstreamreader.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Returns the list of command-line arguments.
    QStringList args = QApplication::arguments();

    if (args.count() < 2) {
        std::cerr << "Usage: xmlstreamreader file1.xml..."
                  << std::endl;
        return 1;
    }

    QStringList labels;
    // QStringList支持流的方式写入(<<)和读取(>>)
    labels << QObject::tr("Terms") << QObject::tr("Pages");

    // The QTreeWidget class provides a tree view that uses a
    // predefined tree model.
    QTreeWidget treeWidget;
    // 设置TreeView的标题栏
    treeWidget.setHeaderLabels(labels);
    treeWidget.header()->setResizeMode(QHeaderView::Stretch);
    treeWidget.setWindowTitle(QObject::tr("XML Stream Reader"));
    treeWidget.show();

    XmlStreamReader reader(&treeWidget);
    // 读取文件列表, 一一进行处理
    for (int i = 1; i < args.count(); ++i)
        reader.readFile(args[i]);

    return app.exec();
}
