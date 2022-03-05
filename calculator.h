#ifndef UNTITLED1_CALCULATOR_H
#define UNTITLED1_CALCULATOR_H
#include <QMainWindow>
#include <QLineEdit>

class CalculatorMainWindow: public QMainWindow{
    Q_OBJECT
    int result;
    bool add, subtract, divide, multiply, new_value;
public:
    QLineEdit *lineEdit {nullptr};
    explicit CalculatorMainWindow(QWidget* parent = nullptr): QMainWindow(parent) {
        add = subtract = divide = multiply = result = new_value = false;
    };
public slots:
    void slot_universal() noexcept {
    //Вместо 10 отдельных слотов ради исключения дублирования...
    //Хотел передавать значение инициирующей кнопки, но не нашел, как.
    //Зато имя кнопки передается прекрасно.
        int num = sender()->objectName().toStdString()[3];
        if (lineEdit->text() != "0" && !new_value
                && (lineEdit->text()[0] >= "0" && lineEdit->text()[0] <= "9" || lineEdit->text()[0] == "-")){
            lineEdit->setText(lineEdit->text()+ QString(num));
        } else {
            lineEdit->setText(QString(num));
            if (!(subtract || add || multiply || divide)) result = 0;
            new_value = false;
        }
    };
    void num_ce() noexcept {
        lineEdit->setText("0");
        add = subtract = divide = multiply = new_value = result = 0;
    };
    void num_neg() noexcept {
        std::string text = lineEdit->text().toStdString();
        if(text[0] >= '0' && text[0] <= '9' || text[0] == '-') {
            if (text[0] == '-') {
                auto it = text.find('-');
                text = text.substr(it + 1);
            } else {
                text = '-' + text;
            }
            if (!(subtract || add || multiply || divide)) result = 0;
            if (!result) result = std::stoi(text);
            lineEdit->setText(text.c_str());
        }
    };
    void equal() noexcept {
        if(!result){
            return;
        } else if (add) {
            result += lineEdit->text().toInt();
            add = false;
        } else if (subtract) {
            result -= lineEdit->text().toInt();
            subtract = false;
        } else if (divide) {
            if(!lineEdit->text().toInt()) {
                lineEdit->setText("Error");
                new_value = true;
                divide = result = 0;
                return;
            }
            result /= lineEdit->text().toInt();
            divide = false;
        } else if (multiply){
            result *= lineEdit->text().toInt();
            multiply = false;
        }
        new_value = true;
        lineEdit->setText(std::to_string(result).c_str());
    };
    void num_add() noexcept {
        if(!result){
            result = lineEdit->text().toInt();
        } else if (add) {
            result += lineEdit->text().toInt();
        } else if (subtract) {
            result -= lineEdit->text().toInt();
            subtract = false;
        } else if (divide) {
            if(!lineEdit->text().toInt()) {
                lineEdit->setText("Error");
                add = new_value = true;
                divide = result = 0;
                return;
            }
            result /= lineEdit->text().toInt();
            divide = false;
        } else if (multiply){
            result *= lineEdit->text().toInt();
            multiply = false;
        }
        add = new_value = true;
        lineEdit->setText(std::to_string(result).c_str());
    };
    void num_subtract() noexcept {
        if(!result){
            result = lineEdit->text().toInt();
        } else if (add) {
            result += lineEdit->text().toInt();
            add = false;
        } else if (subtract) {
            result -= lineEdit->text().toInt();
        } else if (divide) {
            if(!lineEdit->text().toInt()) {
                lineEdit->setText("Error");
                subtract = new_value = true;
                divide = result = 0;
                return;
            }
            result /= lineEdit->text().toInt();
            divide = false;
        } else if (multiply){
            result *= lineEdit->text().toInt();
            multiply = false;
        }
        subtract = new_value = true;
        lineEdit->setText(std::to_string(result).c_str());
    };
    void num_multiply() noexcept {
        if(!result){
            result = lineEdit->text().toInt();
        } else if (add) {
            result += lineEdit->text().toInt();
            add = false;
        } else if (subtract) {
            result -= lineEdit->text().toInt();
            subtract = false;
        } else if (divide) {
            if(!lineEdit->text().toInt()) {
                lineEdit->setText("Error");
                multiply = new_value = true;
                divide = result = 0;
                return;
            }
            result = (lineEdit->text().toInt())? result/lineEdit->text().toInt() : 0;
            divide = false;
        } else if (multiply){
            result *= lineEdit->text().toInt();
        }
        multiply = new_value = true;
        lineEdit->setText(std::to_string(result).c_str());
    };
    void num_divide() noexcept {
        if(!result){
            result = lineEdit->text().toInt();
        } else if (add) {
            result += lineEdit->text().toInt();
            add = false;
        } else if (subtract) {
            result -= lineEdit->text().toInt();
            subtract = false;
        } else if (divide) {
            if(!lineEdit->text().toInt()) {
                lineEdit->setText("Error");
                new_value = true;
                result = 0;
                return;
            }
            result /= lineEdit->text().toInt();
        } else if (multiply){
            result *= lineEdit->text().toInt();
            multiply = false;
        }
        divide = new_value = true;
        lineEdit->setText(std::to_string(result).c_str());
    };
};


#endif //UNTITLED1_CALCULATOR_H
