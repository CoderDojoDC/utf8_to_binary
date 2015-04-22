#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QList>

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

static QList<int> utf8ToCodepoints(const QByteArray &utf8)
{
    QList<int> codepoints;

    for (int i = 0; i < utf8.count(); i++) {
        char b0 = utf8.at(i);
        int value;
        if ((b0 & 0xf8) == 0xf0) {
            // 4 byte
            value = ((b0 & 0x7) << 18) |
                    ((utf8.at(i + 1) & 0x3f) << 12) |
                    ((utf8.at(i + 2) & 0x3f) << 6) |
                    (utf8.at(i + 3) & 0x3f);
            i += 3;
        } else if ((b0 & 0xf0) == 0xe0) {
            // 3 byte
            value = ((b0 & 0xf) << 12) |
                    ((utf8.at(i + 1) & 0x3f) << 6) |
                    (utf8.at(i + 2) & 0x3f);
            i += 2;
        } else if ((b0 & 0xe0) == 0xc0) {
            // 2 byte
            value = ((b0 & 0x1f) << 6) |
                    (utf8.at(i + 1) & 0x3f);
            i++;
        } else if ((b0 & 0x80) == 0) {
            // 1 byte
            value = b0;
        } else {
            // Invalid
            qCritical("Bad UTF-8 char");
            value = 0;
        }
        codepoints << value;
    }
    return codepoints;
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
    ui->utf8BitsTextEdit->setPlainText(output);

    j = 0;
    output.clear();
    QList<int> codepoints = utf8ToCodepoints(utf8);
    foreach (int c, codepoints) {
        if (j > 0)
           output.append((j % 2) ? ", " : "\n");

        output.append(QString("U+%1").arg(c, 4, 16, QLatin1Char('0')));
        j++;
    }
    ui->unicodeCodePointsTextEdit->setPlainText(output);
}
