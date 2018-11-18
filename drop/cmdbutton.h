#ifndef CMDBUTTON_H
#define CMDBUTTON_H

#include <QObject>
#include <QPushButton>

class QDrag;
class QDragEnterEvent;
class QDragMoveEvent;
class QDropEvent;
class QMouseEvent;

/**
 * @brief 算子按钮类
 */
class CmdButton : public QPushButton
{
    Q_OBJECT
public:
    CmdButton(QWidget *parent = Q_NULLPTR);
    ~CmdButton();
    /**
     * @brief btnMimeType
     * @return MimeType
     */
    static QString btnMimeType();
signals:
    void cmdBtnClickSignal(const QString &uuid);
protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
public:
    /**
     * @brief 算子唯一标识符
     */
    QString mCmdUuid;
    /**
     * @brief 算子名称
     */
    QString mCmdName;
    /**
     * @brief 算子图标
     */
    QString mCmdIcon;
    /**
     * @brief 算子按钮边框是否凸起标志
     */
    bool flat;
};

#endif // CMDBUTTON_H
