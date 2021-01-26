#include <QApplication>
#include <QButtonGroup>
#include <QDebug>
#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QRadioButton>
#include <QScreen>
#include <QVBoxLayout>

QRect screenGeometry()
{
    QScreen *screen = QGuiApplication::primaryScreen();

    return screen->geometry();
}

int screenWidth()
{
    return screenGeometry().width();
}

class ModeDialog : public QDialog
{
    Q_OBJECT
public:
    ModeDialog(QWidget* parent) :  QDialog(parent)
    {
        auto prompt = new QLabel("Here is the prompt text, quite a long description blah blah blah");
        prompt->setWordWrap(true);
        auto short_button = new QRadioButton("Short option");
        auto long_button = new QRadioButton("Long option with quite a lot of words that take up more than one line");

        auto mode_selector = new QButtonGroup();
        mode_selector->addButton(short_button, 1);
        mode_selector->addButton(long_button, 2);

        auto mainlayout = new QVBoxLayout();
        mainlayout->addWidget(prompt);
        mainlayout->addWidget(short_button);
        mainlayout->addWidget(long_button);
        mainlayout->addStretch(1);

        setLayout(mainlayout);

        int prompt_width = prompt->width();
        int radio_width = long_button->width();
        int screen_width = screenWidth();
        int dialog_width = this->width();

        qDebug() << "prompt width" << prompt_width << "\n"
                 << "radio width" << radio_width << "\n"
                 << "screen width" << screen_width << "\n"
                 << "dialog width" << dialog_width << "\n";

    }
};

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    ModeDialog dialog(nullptr);
    dialog.exec();

    return app.exec();
}

#include "main.moc"
