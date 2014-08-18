#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputLineEdit_textChanged(const QString &text)
{
    QString output;
    QByteArray utf8 = text.toUtf8();

    int j = 0;
    foreach (char c, utf8) {
        if (j > 0)
            output.append((j & 1) ? "  " : "\n");

        for (int i = 7; i >= 4; i--) {
            output.append((c & (1 << i)) ? "■" : "□");
        }
        output.append("\u00a0"); // nonbreaking space
        for (int i = 3; i >= 0; i--) {
            output.append((c & (1 << i)) ? "■" : "□");
        }
        j++;
    }
    ui->outputTextEdit->setPlainText(output);
}
