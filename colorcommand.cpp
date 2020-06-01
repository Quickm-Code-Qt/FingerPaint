#include "colorcommand.h"
#include "colordatamodel.h"
#include <utility>

ColorCommand::ColorCommand(QObject *parent, QString  colorName)
    : QObject(parent), mColorName(std::move(colorName))
{

}

void ColorCommand::execute()
{
    ColorDataModel::getInstance().setCurrentColor(mColorName);
}
