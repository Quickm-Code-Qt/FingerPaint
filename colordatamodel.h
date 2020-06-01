#ifndef COLORDATAMODEL_H
#define COLORDATAMODEL_H

#include "singletonbase.h"

#include <QAction>
#include <QString>



class ColorDataModel  : public SingletonBase<ColorDataModel>
{
public:
    ColorDataModel();
    virtual ~ColorDataModel() = default;

    QColor              getNextColor();
    void                setCurrentColor(const QString & color);

    QAction *           getColorAction(QString color);
    QVector<QString>    getSupportedColors();
protected:
    void                createColorList();
    void                createColorActions();


private:
    QVector<QString>            mColorMap;
    QMap<QString, QAction *>    mColorActions;
    QColor                      mCurrentColor;
    QList<QColor>             mPenColors;

};

#endif // COLORDATAMODEL_H
