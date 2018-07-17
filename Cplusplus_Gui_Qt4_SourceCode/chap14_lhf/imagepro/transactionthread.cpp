#include <QtGui>

#include "transactionthread.h"

Transaction * const EndTransaction = 0;

FlipTransaction::FlipTransaction(Qt::Orientation orientation)
{
    this->orientation = orientation;
}

QImage FlipTransaction::apply(const QImage &image)
{
    return image.mirrored(orientation == Qt::Horizontal,
                          orientation == Qt::Vertical);
}

