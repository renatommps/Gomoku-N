#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QtGui>

int main(int argc, char *argv[]) {

    /* 
     * QApplication object. This object manages application - wide resources and
     * isnecessary to run any Qt program that has a GUI. It needs argv and args
     * because Qt accepts a few command line arguments.
     */
    QApplication app(argc, argv);

    QTextEdit *textEdit = new QTextEdit;
    QPushButton *quitButton = new QPushButton("&Quit");
    
    /* 
     * A slot is a function that can be invoked at runtime using its name
     * (as a literal string). A signal is a function that when called will
     * invoke slots registered with it; we call that to connect the slot to the
     * signal and to emit the signal.
     * - quit() is a slot of QApplication that exits the application.
     * - clicked() is a signal that QPushButton emits when it is pushed.
     * - The static QObject::connect() function takes care of connecting the
     * slot to the signal
     * - SIGNAL() and SLOT() are two macros that take the function signatures of
     * the signal and slot to connect.
     */
    QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(quitButton);

    QWidget window;
    window.setLayout(layout);

    window.show();

    return app.exec();
}
