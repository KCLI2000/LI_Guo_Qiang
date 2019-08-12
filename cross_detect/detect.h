#ifndef DETECT_H

#define DETECT_H

#include <QMainWindow>

#include <opencv2/opencv.hpp>

#include <opencv2/core.hpp>

#include <opencv2/imgcodecs.hpp>

#include <opencv2/highgui.hpp>

#include <opencv2/imgproc.hpp>

#include <iostream>

#include <string>

#include <QAction>

#include "qlabel.h"

using namespace cv;

using namespace std;

namespace Ui {

class MainWindow;

}

class MainWindow : public QMainWindow

{

    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    cv::Mat image;

    QImage img;

    cv::Mat image_gray;

    double sidewide;

    int thresh = 45;

    int max_thresh = 255;

private slots:

    void on_select_clicked();

    void on_detection_clicked();

private:

    Ui::MainWindow *ui;

};

#endif // DETECT_H
