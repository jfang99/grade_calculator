#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class grade_calculator;
}

class grade_calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit grade_calculator(QWidget *parent = nullptr);
    ~grade_calculator();



public slots:
    void update_score();
 void compute_overall_A();
void compute_overall_B();
private:
    Ui::grade_calculator *ui;
    double grade;
};




#endif // GRADE_CALCULATOR_H
