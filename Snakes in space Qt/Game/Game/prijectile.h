#ifndef PRIJECTILE_H
#define PRIJECTILE_H

#include <QObject>

class Prijectile : public QObject
{
    Q_OBJECT
public:
    explicit Prijectile(QObject *parent = 0);
    ~Prijectile();

signals:

public slots:
};

#endif // PRIJECTILE_H
