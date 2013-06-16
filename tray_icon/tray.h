#ifndef TRAY_H
#define TRAY_H
#include <QDialog>
#include <QSystemTrayIcon>

class QAction;
class QVBoxLayout;
class QGroupBox;
class QLineEdit;
class QTextEdit;
class QPushButton;
class QSystemTrayIcon;

class tray : public QDialog
{
	Q_OBJECT
public:
	explicit tray();
private slots:
	void showMessage();
private:
	void createActions();
	void createTrayIcon();
	void setIcon();
	QVBoxLayout* mainlayout;
	QGroupBox* groupbox;
	QLineEdit* title;
	QTextEdit* text;
	QPushButton* button;
	QAction* max;
	QAction* min;
	QAction* res;
	QAction* bye;
	QMenu* trayMenu;
	QSystemTrayIcon *trayIcon;
};

#endif

