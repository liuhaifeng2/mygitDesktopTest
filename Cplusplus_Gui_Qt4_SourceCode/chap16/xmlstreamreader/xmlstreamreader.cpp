#include <QtGui>
#include <QtXml>
#include <iostream>

#include "xmlstreamreader.h"

XmlStreamReader::XmlStreamReader(QTreeWidget *tree)
{
    treeWidget = tree;
}

bool XmlStreamReader::readFile(const QString &fileName)
{
    QFile file(fileName);
    // QIODevice::ReadOnly:
    // The device is open for reading.
    //
    // QIODevice::Text:
    // When reading, the end-of-line terminators are translators to
    // '\n'.
    // When writing, the end-of-line terninators are translators to
    // the local encoding, for example '\r\n' for Win32.
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
        return false;
    }

    // Sets the current device to &file.
    // Setting the device resets the stream to its initial state.
    reader.setDevice(&file);

    // Reads the next token and returns its type.
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isStartElement()) {
            if (reader.name() == "bookindex") {
                readBookindexElement();
            } else {
                reader.raiseError(QObject::tr("Not a bookindex file"));
            }
        } else {
            reader.readNext();
        }
    }

    file.close();
    if (reader.hasError()) {
        // const char *qPrintable(const QString &str):
        // Return str as a const char *. This is equivalent
        // to str.toLocal8Bit().constData().
        std::cerr << "Error: Failed to parse file "
                  << qPrintable(fileName) << ": "
                  << qPrintable(reader.errorString()) << std::endl;
        return false;

    }
    // FileError QFileDevice::error() const:
    // Returns the file error status.
    else if (file.error() != QFile::NoError)
    {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
        return false;
    }
    return true;
}

void XmlStreamReader::readBookindexElement()
{
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

        if (reader.isStartElement()) {
            if (reader.name() == "entry") {
                readEntryElement(treeWidget->invisibleRootItem());
            } else {
                skipUnknownElement();
            }
        } else {
            reader.readNext();
        }
    }
}

void XmlStreamReader::readEntryElement(QTreeWidgetItem *parent)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, reader.attributes().value("term").toString());

    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

        if (reader.isStartElement()) {
            if (reader.name() == "entry") {
                readEntryElement(item);
            } else if (reader.name() == "page") {
                readPageElement(item);
            } else {
                skipUnknownElement();
            }
        } else {
            reader.readNext();
        }
    }
}

void XmlStreamReader::readPageElement(QTreeWidgetItem *parent)
{
    QString page = reader.readElementText();
    if (reader.isEndElement())
        reader.readNext();

    QString allPages = parent->text(1);
    if (!allPages.isEmpty())
        allPages += ", ";
    allPages += page;
    parent->setText(1, allPages);
}

void XmlStreamReader::skipUnknownElement()
{
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

        if (reader.isStartElement()) {
            skipUnknownElement();
        } else {
            reader.readNext();
        }
    }
}
