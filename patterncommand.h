#ifndef PATTERNCOMMAND_H
#define PATTERNCOMMAND_H

#include <QObject>

class PatternCommand : public QObject
{
    Q_OBJECT
    public:
        PatternCommand(QObject* parent, Qt::BrushStyle  style);

    public slots:
        void execute();

    private:
        Qt::BrushStyle      mBrushStyle;
};

#endif // PATTERNCOMMAND_H
