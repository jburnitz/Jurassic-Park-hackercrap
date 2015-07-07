#ifndef NEWMAN_H
#define NEWMAN_H

#include <QMainWindow>
class QMovie;

class Newman : public QMainWindow
{
    Q_OBJECT
public:
    explicit Newman(QWidget *parent = 0);

private:
    QMovie *gif;

signals:

public slots:
    void PlayAnimation();
};

#endif // NEWMAN_H
