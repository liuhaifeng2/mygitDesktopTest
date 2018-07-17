#ifndef XMLSTREAMREADER_H
#define XMLSTREAMREADER_H

#include <QXmlStreamReader>

class QTreeWidget;
class QTreeWidgetItem;

class XmlStreamReader
{
public:
    XmlStreamReader(QTreeWidget *tree);

    bool readFile(const QString &fileName);

private:
    void readBookindexElement();
    void readEntryElement(QTreeWidgetItem *parent);
    void readPageElement(QTreeWidgetItem *parent);
    void skipUnknownElement();

    QTreeWidget *treeWidget;
    // The QXmlStreamReader class provides a fast parser for reading
    // well-formed XML via a simple streaming API.
    QXmlStreamReader reader;
};

#endif
