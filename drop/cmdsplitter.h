#ifndef CMDSPLITTER_H
#define CMDSPLITTER_H

#include <QObject>
#include <QSplitter>

class QEvent;
class QDragEnterEvent;
class QDropEvent;

class CmdSplitter : public QSplitter
{
    Q_OBJECT
public:
    CmdSplitter(QWidget *parent = Q_NULLPTR);
    CmdSplitter(Qt::Orientation orient, QWidget *parent = Q_NULLPTR);
    ~CmdSplitter();
protected:
    void enterEvent(QEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // CMDSPLITTER_H
