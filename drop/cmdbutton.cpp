#include "cmdbutton.h"

#include <QDrag>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMouseEvent>
#include <QMimeData>
#include <QPixmap>
#include <QPoint>

CmdButton::CmdButton(QWidget *parent)
    :QPushButton(parent)
    ,mCmdUuid("")
    ,mCmdName("")
    ,mCmdIcon("")
    ,flat(false)
{
    setAcceptDrops(true);//将CmdButton设置为可拖拽
    setStyleSheet(QLatin1String("height: 62px;width: 78px"));//设置CmdButton大小
    setAttribute(Qt::WA_AlwaysShowToolTips);//总是显示工具提示
    setFlat(true);//设置CmdButton边框突起
}

CmdButton::~CmdButton()
{

}

QString CmdButton::btnMimeType()
{
    return QStringLiteral("application/cmdbtnmedata");
}

void CmdButton::enterEvent(QEvent *event)
{

}

void CmdButton::leaveEvent(QEvent *event)
{

}

void CmdButton::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat(CmdButton::btnMimeType()))
    {
        event->setDropAction(Qt::CopyAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void CmdButton::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat(CmdButton::btnMimeType()))
    {
        event->setDropAction(Qt::CopyAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void CmdButton::dropEvent(QDropEvent *event)
{

}

void CmdButton::mousePressEvent(QMouseEvent *event)
{
    //左键选中，右键拖放
    if(event->button()==Qt::LeftButton)
    {
        emit cmdBtnClickSignal(mCmdUuid);
    }
    else if(event->button()==Qt::RightButton)
    {
        //创建drag
        QByteArray byteArray;
        QDataStream dataStream(&byteArray,QIODevice::WriteOnly);
        dataStream<<mCmdUuid<<mCmdName<<mCmdIcon;
        QDrag *drag=new QDrag(this);
        QMimeData *mimeData=new QMimeData;
        mimeData->setData(CmdButton::btnMimeType(),byteArray);
        drag->setMimeData(mimeData);
        QPixmap pixmap(mCmdIcon);
        drag->setPixmap(pixmap);
        drag->setHotSpot(QPoint(pixmap.width()/2,pixmap.height()/2));
        drag->exec(Qt::CopyAction);
    }
}
