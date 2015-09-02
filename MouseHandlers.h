//
// Created by michiel on 17-8-2015.
//

#ifndef OPENPSTD_MOUSEHANDLERS_H
#define OPENPSTD_MOUSEHANDLERS_H

class MouseStrategy;
class MouseVoidStrategy;
class MouseMoveSceneStrategy;
class MouseCreateDomainStrategy;

#include <memory>
#include "operations/BaseOperation.h"
#include <QVector2D>
#include <QtGui/qevent.h>

class MouseStrategy
{
protected:
    std::shared_ptr<OperationRunner> operationRunner;

public:
    void SetOperationRunner(std::shared_ptr<OperationRunner> operationRunner);

    virtual void mousePressEvent(std::shared_ptr<Model> const &model, QMouseEvent *, QVector2D pos){};
    virtual void mouseReleaseEvent(std::shared_ptr<Model> const &model, QMouseEvent *mouseEvent, QVector2D pos){};
    virtual void mouseMoveEvent(std::shared_ptr<Model> const &model, QMouseEvent *mouseEvent, QVector2D pos){};
    virtual void wheelEvent(std::shared_ptr<Model> const &model, QWheelEvent *mouseEvent, QVector2D pos){};
};

class MouseVoidStrategy : public MouseStrategy
{
};

class MouseSelectStrategy : public MouseStrategy
{
public:
    virtual void mouseReleaseEvent(std::shared_ptr<Model> const &model, QMouseEvent *mouseEvent, QVector2D pos) override;
};

class MouseMoveSceneStrategy : public MouseStrategy
{
private:
    QVector2D mousePos;
public:
    virtual void mousePressEvent(std::shared_ptr<Model> const &model, QMouseEvent *, QVector2D pos) override;

    virtual void mouseMoveEvent(std::shared_ptr<Model> const &model, QMouseEvent *mouseEvent, QVector2D pos) override;

    virtual void wheelEvent(std::shared_ptr<Model> const &model, QWheelEvent *mouseEvent, QVector2D pos) override;
};

class MouseCreateDomainStrategy : public MouseStrategy
{
private:
    QVector2D _start;
    QVector2D _end;
public:
    virtual void mousePressEvent(std::shared_ptr<Model> const &model, QMouseEvent *, QVector2D pos) override;

    virtual void mouseMoveEvent(std::shared_ptr<Model> const &model, QMouseEvent *mouseEvent, QVector2D pos) override;

    virtual void mouseReleaseEvent(std::shared_ptr<Model> const &model, QMouseEvent *mouseEvent, QVector2D pos) override;
};

#endif //OPENPSTD_MOUSEHANDLERS_H


