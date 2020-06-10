#ifndef COLORDATAMODEL_H
#define COLORDATAMODEL_H

#include "singletonbase.h"

#include <QAction>
#include <QString>



class ColorDataModel  : public SingletonBase<ColorDataModel>
{
public:
    ColorDataModel();
    virtual ~ColorDataModel();

    QColor              getNextColor();
    Qt::BrushStyle      getPattern();
    void                setCurrentColor(const QString & color);
    void                setCurrentPattern(const Qt::BrushStyle & pattern);

    QAction *           getColorAction(QString color);
    QAction *           getPatternAction(QString pattern);
    QVector<QString>    getSupportedColors();
    QVector<QString>    getSupportedPatterns();

protected:
    void                createColorList();
    void                createPatternMap();
    void                createColorActions();
    void                createPatternActions();
    void                createPatternList();


private:
    QVector<QString>            mColorList;
    QVector<Qt::BrushStyle>     mPatternList;
    QMap<QString, QAction *>    mColorActions;
    QMap<QString, QAction *>    mPatternActions;
    QMap<Qt::BrushStyle, QString> mPatternMap;
    QColor                      mCurrentColor;
    Qt::BrushStyle              mCurrentPattern;
    QList<QColor>               mPenColors;

};

#endif // COLORDATAMODEL_H
