#ifndef COLORCOMMAND_H
#define COLORCOMMAND_H


#include <QObject>

class ColorCommand : public QObject
{
    Q_OBJECT
    public:
        ColorCommand(QObject* parent, QString  colorName);

    public slots:
        void execute();

    private:
        QString             mColorName;
};

#endif // COLORCOMMAND_H
