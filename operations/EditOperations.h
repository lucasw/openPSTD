//
// Created by michiel on 16-8-2015.
//

#ifndef OPENPSTD_EDITOPERATIONS_H
#define OPENPSTD_EDITOPERATIONS_H

#include "BaseOperation.h"
#include <boost/numeric/ublas/vector.hpp>
#include <QVector2D>

class CreateDomainOperation: public BaseOperation
{
private:
    QVector2D StartPoint;
    QVector2D EndPoint;

public:
    CreateDomainOperation(QVector2D StartPoint, QVector2D EndPoint);

    virtual void Run(const Reciever &reciever) override;
};

class RemoveSelectedDomainOperation: public BaseOperation
{
public:
    virtual void Run(const Reciever &reciever) override;
};

class RemoveDomainOperation: public BaseOperation
{
private:
    int index;

public:
    RemoveDomainOperation(int index);

    virtual void Run(const Reciever &reciever) override;
};

class EditDomainPositionsOperation: public BaseOperation
{
private:
    int index;
    QVector2D StartPoint;
    QVector2D EndPoint;

public:
    EditDomainPositionsOperation(int index, QVector2D startPoint, QVector2D endPoint);

    virtual void Run(const Reciever &reciever) override;
};

class EditDomainEdgeAbsorptionOperation: public BaseOperation
{
private:
    int index;
    PSTD_DOMAIN_SIDE Side;
    float NewValue;

public:
    EditDomainEdgeAbsorptionOperation(int index, PSTD_DOMAIN_SIDE side, float newValue);

    virtual void Run(const Reciever &reciever) override;
};

template <typename T>
class EditPropertyOperation: public BaseOperation
{
private:
    const std::string Property;
    T NewValue;

public:
    EditPropertyOperation(const std::string property, T newValue): NewValue(newValue), Property(property)
    {
    }

    virtual void Run(const Reciever &reciever) override
    {
        using namespace rapidjson;

        std::shared_ptr<Document> conf = reciever.model->d->GetSceneConf();

        Document::AllocatorType& allocator = conf->GetAllocator();

        (*conf).AddMember(this->Property, this->NewValue, allocator);

        reciever.model->d->SetSceneConf(conf);
    }
};


#endif //OPENPSTD_EDITOPERATIONS_H

