#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QQuickItem>
#include <QDebug>
#include <QString>
#include <QQueue>
#include <QList>
#include <iostream>
#include <string>
#include "parsingtree.h"
#include "parser.h"
#include "refutationtree.h"
#include "formula.h"
#include "generatortest.h"
#include "treeaux.h"
#include "data.h"
#include "parseddata.h"

using namespace std;

class Receiver : public QObject {
    Q_OBJECT

    signals:
        void node(int x, int y, QString formula, bool isLiteral );

    public slots:
        void _nextTestSlot() {
            qDebug() << "Hay que hacer el test siguiente.";
        }

        void _prevTestSlot() {
            qDebug() << "Hay que hacer el test anterior.";
        }

        void _setData(
                QString _algorithm,
                QString _preCondition,
                QString _postCondition,
                QString _invariant,
                QString _bound );
    public:
        void _sendNodes(QQueue<data> node);
};

#endif // RECEIVER_H
