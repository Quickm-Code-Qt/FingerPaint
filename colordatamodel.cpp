#include "colorcommand.h"
#include "colordatamodel.h"
#include "color_constants.h"
#include "patterncommand.h"
#include <QObject>

ColorDataModel::ColorDataModel()
{
    createColorList();
    createPatternList();
    createPatternMap();
    createColorActions();
    createPatternActions();

    for(QString color : mColorList)
    {
        mPenColors << QColor(color);
    }

    mCurrentColor   = Qt::GlobalColor::white;
    mCurrentPattern = Qt::SolidPattern;
}

ColorDataModel::~ColorDataModel()
{
    mColorList.clear();
    mPatternList.clear();
    mColorActions.clear();
    mPenColors.clear();
}

void ColorDataModel::createColorList()
{
    mColorList.append(COLOR_NAME_GREEN);
    mColorList.append(COLOR_NAME_RED);
    mColorList.append(COLOR_NAME_BLUE);
    mColorList.append(COLOR_NAME_YELLOW);
    mColorList.append(COLOR_NAME_MAGENTA);
    mColorList.append(COLOR_NAME_CYAN);
    mColorList.append(COLOR_NAME_ORANGE);
    mColorList.append(COLOR_NAME_PINK);
}

void ColorDataModel::createPatternMap()
{
    mPatternMap.insert(Qt::SolidPattern, "Solid");
    mPatternMap.insert(Qt::Dense3Pattern, "Dense 3");
    mPatternMap.insert(Qt::Dense6Pattern, "Dense 6");
    mPatternMap.insert(Qt::Dense7Pattern, "Dense 7");
    mPatternMap.insert(Qt::HorPattern, "Horizontal");
    mPatternMap.insert(Qt::VerPattern, "Vertical");
    mPatternMap.insert(Qt::CrossPattern, "Cross");
    mPatternMap.insert(Qt::BDiagPattern, "Backward Diagonal");
    mPatternMap.insert(Qt::FDiagPattern, "Forward Diagonal");
    mPatternMap.insert(Qt::DiagCrossPattern, "Diagonal Cross");
}

void ColorDataModel::createColorActions()
{
    QAction * colorAction = nullptr;

    QVector<QString>    colors      = mColorList;
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

void ColorDataModel::createPatternActions()
{
    QAction *                   patternAction   = nullptr;

    QVector<QString>            patterns        = getSupportedPatterns();
    PatternCommand  *           patternCmd      = nullptr;
    Qt::BrushStyle              patternStyle;

    for(const QString & pattern : patterns)
    {
        patternAction = new QAction(pattern);
        mPatternActions.insert(pattern, patternAction);

        patternStyle = mPatternMap.key(pattern);

        patternCmd = new PatternCommand(patternAction, patternStyle);
        QObject::connect(patternAction, &QAction::triggered, patternCmd, &PatternCommand::execute );
    }
}

void ColorDataModel::createPatternList()
{
    mPatternList.append(Qt::SolidPattern);
    mPatternList.append(Qt::Dense3Pattern);
    mPatternList.append(Qt::Dense6Pattern);
    mPatternList.append(Qt::Dense7Pattern);
    mPatternList.append(Qt::HorPattern);
    mPatternList.append(Qt::VerPattern);
    mPatternList.append(Qt::CrossPattern);
    mPatternList.append(Qt::BDiagPattern);
    mPatternList.append(Qt::FDiagPattern);
    mPatternList.append(Qt::DiagCrossPattern);
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

Qt::BrushStyle ColorDataModel::getPattern()
{
    return mCurrentPattern;
}

void ColorDataModel::setCurrentColor(const QString &color)
{
    QColor newColor(color);

    mCurrentColor = newColor;
}

void ColorDataModel::setCurrentPattern(const Qt::BrushStyle &pattern)
{
    mCurrentPattern = pattern;
}

QAction * ColorDataModel::getColorAction(QString color)
{
    QAction * action = nullptr;

    action = mColorActions.value(color);

    return action;
}

QAction *ColorDataModel::getPatternAction(QString pattern)
{
    QAction * action = nullptr;
    QString   styleStr;

//    styleStr = mPatternMap.value(style);
    action   = mPatternActions.value(pattern);

    return action;
}

QVector<QString> ColorDataModel::getSupportedColors()
{
    return mColorList;
}

QVector<QString> ColorDataModel::getSupportedPatterns()
{
    return mPatternMap.values().toVector();
}
