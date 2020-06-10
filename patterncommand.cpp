#include "colordatamodel.h"
#include "patterncommand.h"


PatternCommand::PatternCommand(QObject *parent, Qt::BrushStyle style)
    : QObject(parent), mBrushStyle(style)
{

}

void PatternCommand::execute()
{
    ColorDataModel::getInstance().setCurrentPattern(mBrushStyle);
}
