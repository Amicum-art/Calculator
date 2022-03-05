#include <QApplication>
#include "./ui_untitled.h"
#include "calculator.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalculatorMainWindow window(nullptr);
    Ui::MainWindow calculator;
    calculator.setupUi(&window);
    window.lineEdit = calculator.lineEdit;
    window.resize(300, 450);
    window.show();
    return QApplication::exec();
}
