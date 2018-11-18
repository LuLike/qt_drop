#include "cmdsplitter.h"
#include "cmdbutton.h"

#include <QEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QByteArray>
#include <QDataStream>
#include <QMimeData>

CmdSplitter::CmdSplitter(QWidget *parent)
    :QSplitter(parent)
{
    setAcceptDrops(true);//允许拖放
}

CmdSplitter::CmdSplitter(Qt::Orientation orient, QWidget *parent)
    :QSplitter(orient, parent)
 {

 }

CmdSplitter::~CmdSplitter()
{

}

void CmdSplitter::enterEvent(QEvent *event)
{

}

void CmdSplitter::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat(CmdButton::btnMimeType()))
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void CmdSplitter::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat(CmdButton::btnMimeType()))
    {
        QByteArray byteArray=event->mimeData()->data(CmdButton::btnMimeType());
        QDataStream dataStream(&byteArray,QIODevice::ReadOnly);
        QString cmdUuid,cmdName,cmdIcon;
        dataStream>>cmdUuid>>cmdName>>cmdIcon;
        event->setDropAction(Qt::CopyAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
