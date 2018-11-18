#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTabWidget;
class QWidget;
class QGraphicsView;
class QScrollArea;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTabWidget *m_pTabWidget;
    QWidget *m_pOverviewWidget;
    QGraphicsView *m_pMainView;
    QScrollArea *m_pScrollArea;
};

#endif // MAINWINDOW_H
