#include "colorcommand.h"
#include "colordatamodel.h"
#include "color_constants.h"
#include <QObject>

ColorDataModel::ColorDataModel()
{
    createColorList();
    createColorActions();
//    mPenColors
//            << QColor("green")
//            << QColor("purple")
//            << QColor("red")
//            << QColor("blue")
//            << QColor("yellow")
//            << QColor("pink")
//            << QColor("orange")
//            << QColor("magenta")
//            << QColor("grey")
//            << QColor("black");
    for(QString color : mColorMap)
    {
        mPenColors << QColor(color);
    }

    mCurrentColor = Qt::GlobalColor::white;
}

//ColorDataModel::~ColorDataModel()
//{
//    mColorMap.clear();
//    mColorActions.clear();
//    myPenColors.clear();
//}

void ColorDataModel::createColorList()
{
    mColorMap.append("green");
    mColorMap.append("red");
    mColorMap.append("blue");
    mColorMap.append("yellow");
    mColorMap.append("magenta");
    mColorMap.append("cyan");
    mColorMap.append("orange");
    mColorMap.append("pink");
}

void ColorDataModel::createColorActions()
{
    QAction * colorAction = nullptr;

    QVector<QString>    colors      = mColorMap;
    ColorCommand  *     colorCmd    = nullptr;
    for(const QString & color : colors)
    {
        colorAction = new QAction(color);
        mColorActions.insert(color, colorAction);

        colorCmd = new ColorCommand(colorAction, color);
        QObject::connect(colorAction, &QAction::triggered, colorCmd, &ColorCommand::execute );
    }

    QString multicolor = "Mult-color";
    colorAction = new QAction(multicolor);
    mColorActions.insert(multicolor, colorAction);

    colorCmd = new ColorCommand(colorAction, COLOR_NAME_WHITE);
    QObject::connect(colorAction, &QAction::triggered, colorCmd, &ColorCommand::execute );
}

QColor ColorDataModel::getNextColor()
{
    static int index = 0;
    QColor color;

    if (mCurrentColor != Qt::GlobalColor::white)
    {
        color = mCurrentColor;
    }

    else
    {
        if (index < mPenColors.length())
        {
            color = mPenColors[index];

            index++;
            index = (index >= mPenColors.length()-1) ? 0 : index+1;
        }
    }

    return color;
}

void ColorDataModel::setCurrentColor(const QString &color)
{
    QColor newColor(color);

    mCurrentColor = newColor;
}

QAction * ColorDataModel::getColorAction(QString color)
{
    QAction * action = nullptr;

    action = mColorActions.value(color);

    return action;
}

QVector<QString> ColorDataModel::getSupportedColors()
{
    return mColorMap;
}
