#include "grade_calculator.h"
#include "ui_grade_calculator.h"
#include <QLabel>
#include<QSlider>
#include<QSpinBox>
#include<QHBoxLayout>
#include<QMenuBar>
#include<QString>
#include<vector>

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);
    /*QMenuBar* menubar = new QMenuBar(this);
    menubar->addMenu("Setting");*/
    grade=0;

    QObject::connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(compute_overall_A()));
    QObject::connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(update_score()));

    QObject::connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(compute_overall_B()));
    QObject::connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(update_score()));
}

grade_calculator::~grade_calculator()
{
    delete ui;
}


void grade_calculator::update_score(){

    ui->overall->setText(QString::number(grade));
    return;
}

void grade_calculator::compute_overall_A(){
    grade=0.0;
    int hw1=ui->spinBox->value();
    int hw2=ui->spinBox_2->value();
    int hw3=ui->spinBox_3->value();
    int hw4=ui->spinBox_4->value();
    int hw5=ui->spinBox_5->value();
    int hw6=ui->spinBox_6->value();
    int hw7=ui->spinBox_7->value();
    int hw8=ui->spinBox_8->value();
    std::vector<int> vec={hw1,hw2,hw3,hw4,hw5,hw6,hw7,hw8};
    int min=hw1;
    for(int i=1;i<8;i++){
        if(vec[i]<min)min=vec[i];
    }
    int homework=0;
    for(int i=0;i<8;i++){
        homework+=vec[i];
    }
    homework-=min;
    double hw=homework/700.0*25;

    int midterm1=ui->spinBox_9->value();
    int midterm2=ui->spinBox_10->value();
    double mid=(midterm1/100.0*20)+(midterm2/100.0*20);

    int finalexam=ui->spinBox_11->value();
    double final=finalexam/100.0*35;

    grade=hw+mid+final;

}

void grade_calculator::compute_overall_B(){
    grade=0.0;
    int hw1=ui->spinBox->value();
    int hw2=ui->spinBox_2->value();
    int hw3=ui->spinBox_3->value();
    int hw4=ui->spinBox_4->value();
    int hw5=ui->spinBox_5->value();
    int hw6=ui->spinBox_6->value();
    int hw7=ui->spinBox_7->value();
    int hw8=ui->spinBox_8->value();
    std::vector<int> vec={hw1,hw2,hw3,hw4,hw5,hw6,hw7,hw8};
    int min=hw1;
    for(int i=1;i<8;i++){
        if(vec[i]<min)min=vec[i];
    }
    int homework=0;
    for(int i=0;i<8;i++){
        homework+=vec[i];
    }
    homework-=min;
    double hw=homework/700.0*25;

    int midterm1=ui->spinBox_9->value();
    int midterm2=ui->spinBox_10->value();
    double mid;
    if(midterm1>midterm2){
        mid=midterm1/100.0*35;
    }
    else{
        mid=midterm2/100.0*35;
    }


    int finalexam=ui->spinBox_11->value();
    double final=finalexam/100.0*44;

    grade=hw+mid+final;

}

